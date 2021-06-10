from flask import Flask, Response, jsonify, request, render_template

from flask_sqlalchemy import SQLAlchemy
from typing import Any, Union
from traceback import print_exc

app = Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:////assignment.db"

db = SQLAlchemy(app)


@app.get("/")
def hello_world() -> str:
    return render_template("base.html")


@app.post("/students")
def create_student() -> Response:
    """
    Create a new Student Object
    :return: Created Student Object
    """
    try:
        student = Student(name=request.form["name"], email=request.form["email"])
        db.session.add(student)
        db.session.commit()
        return jsonify(student.to_dict())
    except Exception as e:
        print_exc(e)
        return jsonify({"error": str(e)})


@app.get("/students")
def get_all_students() -> Union[str, Response]:
    """
    Get all students
    :return: Return HTML template displaying all students in a table
    """
    try:
        return render_template(
            "students.html",
            students=[student.to_dict() for student in Student.query.all()],
        )
    except Exception as e:
        print_exc(e)
        return jsonify({"error": str(e)})


@app.post("/marks")
def create_marks() -> Response:
    """
    Create a new Marks Object
    :return: Created Marks Object
    """
    try:
        marks = Marks(
            _id=request.form["id"],
            physics=int(request.form["physics"]),
            chemistry=int(request.form["chemistry"]),
            maths=int(request.form["maths"]),
        )
        db.session.add(marks)
        db.session.commit()
        return jsonify(marks.to_dict())
    except Exception as e:
        print_exc(e)
        return jsonify({"error": str(e)})


class Marks(db.Model):
    __tablename__ = "marks"

    _id = db.Column(db.Integer, db.ForeignKey("students._id"), primary_key=True)
    physics = db.Column(db.Integer)
    chemistry = db.Column(db.Integer)
    maths = db.Column(db.Integer)

    student = db.relationship("Student", back_populates="marks")

    def to_dict(self, exclude_relations: bool = False) -> dict[str, Any]:
        """
        Convert Model object to Dict
        :param exclude_relations: whether relation object dicts should be included or not
        :return: dict with model and relations data
        """
        obj = {
            "id": self._id,
            "physics": self.physics,
            "chemistry": self.chemistry,
            "maths": self.maths,
        }
        if not exclude_relations and self.student:
            obj["student"] = self.student.to_dict(exclude_relations=True)
        return obj


class Student(db.Model):
    __tablename__ = "students"

    _id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50))
    email = db.Column(db.String(50))

    marks = db.relationship("Marks", back_populates="student", uselist=False)

    def to_dict(self, exclude_relations: bool = False) -> dict[str, Any]:
        """
        Convert Model object to Dict
        :param exclude_relations: whether relation object dicts should be included or not
        :return: dict with model and relations data
        """
        obj = {"id": self._id, "name": self.name, "email": self.email}
        if not exclude_relations and self.marks:
            obj["marks"] = self.marks.to_dict(exclude_relations=True)
        return obj
