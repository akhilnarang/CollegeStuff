/*
 * book.cpp
 *
 *  Created on: 07-Aug-2018
 *      Author: Akhil Narang
 *      Roll No. 203132
 *      OOP Mock Practical Exam
 *      Define a class to represent a Book. Include the following members:
 *      Data members :-
 *        - Author
 *        - Title
 *        - Price
 *        - Publisher
 *        - Position
 *      Member functions :-
 *        -To assign initial values
 *        - To display names
 */

// Including headers for input/output and string operators
#include <iostream>
#include <string>

using namespace std;

// Defining our Book class
class Book {

    // Some private data members of Boo class
    string author, title, publisher;
    float price;
    int position;

    // Public members of Book class
  public:
    // Default constructor initializing the data members to "" and 0 depending
    // on type
    Book() {
        author = title = publisher = "";
        price = 0.0;
        position = 0;
    }

    // Parameterized constructor for Book class setting the values passed by us
    Book(string author, string title, string publisher, float price,
         int position) {
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->price = price;
        this->position = position;
    }

    // Overloaded >> operator so that we can use cin with a Book object to
    // accept our data
    istream& operator>>(istream& stdin) {
        // getline() function used to accept a full line instead of a single
        // word
        cout << "Enter author name: ";
        getline(stdin, author);
        cout << "Enter book title: ";
        getline(stdin, title);
        cout << "Enter book publisher: ";
        getline(stdin, publisher);
        cout << "Enter book price: ";
        stdin >> price;
        cout << "Enter book position: ";
        stdin >> position;
        return stdin;
    }

    // Overloaded << operator so that we can use cout with a Book object to
    // display our data
    ostream& operator<<(ostream& stdout) {
        stdout << "Author name: " << author << endl;
        stdout << "Book title: " << title << endl;
        stdout << "Book publisher: " << publisher << endl;
        stdout << "Book price: " << price << endl;
        stdout << "Book position: " << position << endl;
        return stdout;
    }

    // Destructor to tell us when the object is being destroyed
    ~Book() {
        // Print pointer to object being destroyed
        cout << "Destroying object " << this << endl;
    }
};

// Defining our main() function
int main() {
    // Creating an object of Book
    Book book;
    cout << "Enter details of book!" << endl;
    // Using overloaded >> operator to accept details about a book
    book >> cin;
    cout << "Displaying details about book!" << endl;
    // Using overloaded << operator to display details about a book
    book << cout;

    // Creating another book object using our parameterized constructor to
    // initialize it
    Book b("Author Name", "Book Title", "Book Publisher", 399.99, 5);

    // Using overloaded << operator to display details about this book
    b << cout;
}

/* OUTPUT
Enter details of book!
Enter author name: name
Enter book title: title
Enter book publisher: publisher
Enter book price: 400.50
Enter book position: 1
Displaying details about book!
Author name: name
Book title: title
Book publisher: publisher
Book price: 400.5
Book position: 1
Author name: Author Name
Book title: Book Title
Book publisher: Book Publisher
Book price: 399.99
Book position: 5
Destroying object 0x7ffff430c460
Destroying object 0x7ffff430c3f0
*/
