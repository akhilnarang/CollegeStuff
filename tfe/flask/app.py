#!/usr/bin/env python3

from typing import Any, Union

from flask_sqlalchemy import SQLAlchemy

from flask import Flask, Response, redirect, render_template, request, url_for

app = Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///assignment.db"

db = SQLAlchemy(app)


@app.get("/")
def root_path() -> str:
    return render_template("base.html")


@app.post("/students")
def create_student() -> Response:
    student = Student(name=request.form["name"], email=request.form["email"])
    db.session.add(student)
    db.session.commit()
    return redirect("students")


@app.get("/students")
def get_students() -> Union[str, Response]:
    """
    Get all students
    :return: Return HTML template displaying all students in a table
    """
    return render_template(
        "students.html",
        students=[student.to_dict() for student in Student.query.all()],
    )


@app.get("/marks")
def get_marks() -> Union[str, Response]:
    """
    Get all marks for a student
    :return: Return HTML template displaying all marks of a student in a table
    """
    studentid_ = request.args.get("id")
    marks = Marks.query.get(studentid_)
    return render_template("marks.html", marks=marks, id=studentid_)


@app.post("/marks")
def create_marks() -> Response:
    marks = Marks.query.get(request.form["id"])
    if marks is None:
        marks = Marks(id_=request.form["id"])
        for subject in ["oop", "ds", "dbms"]:
            if request.form[subject]:
                setattr(marks, subject, int(request.form[subject]))
        db.session.add(marks)
    else:
        for subject in ["oop", "ds", "dbms"]:
            if request.form[subject] and request.form[subject] != str(
                getattr(marks, subject)
            ):
                setattr(marks, subject, int(request.form[subject]))
    db.session.commit()
    return redirect(url_for("get_marks", id=request.form["id"]))


class Marks(db.Model):
    id_ = db.Column(db.Integer, db.ForeignKey("student.id_"), primary_key=True)
    oop = db.Column(db.Integer)
    ds = db.Column(db.Integer)
    dbms = db.Column(db.Integer)

    student = db.relationship("Student", back_populates="marks")

    def to_dict(self, exclude_relations: bool = False) -> dict[str, Any]:
        """
        Convert Model object to Dict
        :param exclude_relations: whether to include relation object dicts
        :return: dict with model and relations data
        """
        obj = {
            "id": self.id_,
            "oop": self.oop,
            "ds": self.ds,
            "dbms": self.dbms,
        }
        if not exclude_relations and self.student:
            obj["student"] = self.student.to_dict(exclude_relations=True)
        return obj


class Student(db.Model):
    id_ = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50))
    email = db.Column(db.String(50))

    marks = db.relationship("Marks", back_populates="student", uselist=False)

    def to_dict(self, exclude_relations: bool = False) -> dict[str, Any]:
        """
        Convert Model object to Dict
        :param exclude_relations: whether to include relation object dicts
        :return: dict with model and relations data
        """
        obj = {"id": self.id_, "name": self.name, "email": self.email}
        if not exclude_relations and self.marks:
            obj["marks"] = self.marks.to_dict(exclude_relations=True)
        return obj


if __name__ == "__main__":
    db.create_all()
    app.run()
