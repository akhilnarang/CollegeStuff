#include <math.h>    // Including header file so that we can use sqrt() method
#include <stdlib.h>  // Including header file so that we can use exit() method
#include <iostream>

/**
 * Menu driven program to calculate area of different shapes
 * Different classes are derived for different shapes from a base class shape
 */

using namespace std;

class Shape  // Base class for shapes
{
   public:
    ~Shape()  // Destructor that will show when an object is destroyed
    {
        cout << "Destroying " << this << "!\n";
    }
};

class Circle : Shape  // Class for circle derived from shape
{
   public:
    int r;        // Variable for storing radius of circle
    void input()  // Function to accept radius of circle
    {
        cout << "Enter radius of circle!\nr: ";
        cin >> r;
    }
    void display()  // Function to display area of circle
    {
        double area = M_PI * r * r;
        cout << "Area of circle is " << area << "!\n";
    }
};

class Rectangle : Shape  // Class for rectangle derived from shape
{
   public:
    int l, b;     // Variables to store the dimensions of rectangle
    void input()  // Function to accept dimensions of rectangle
    {
        cout << "Enter length and breadth of rectangle!\n";
        cin >> l >> b;
    }
    void display()  // Function to display area of circle
    {
        double area = l * b;
        cout << "Area of Rectangle is " << area << "!\n";
    }
};

class Triangle : Shape  // Class for triangle derived from shape
{
   public:
    int a, b, c;  // Variables to store the dimensions of triangle
    void input()  // Function to accept dimensions of triangle
    {
        cout << "Enter 3 sides of triangle!\n";
        cin >> a >> b >> c;
    }

    void display()  // Function to display area of triangle
    {
        double s = a + b + c / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Area of triangle is " << area << "!\n";
    }
};

int main() {
    do {  // do-while loop so that user will get prompted until they enter an
          // invalid input
        cout << "Enter 1 for circle, 2 for rectangle, 3 for triangle, anything "
                "else to exit!\n";
        int c;
        cin >> c;
        // Accept choice and check value with switch-case structure
        // Create object of needed class and call the methods
        switch (c) {
            case 1: {
                Circle C;
                C.input();
                C.display();
                break;
            }
            case 2: {
                Rectangle R;
                R.input();
                R.display();
                break;
            }
            case 3: {
                Triangle T;
                T.input();
                T.display();
                break;
            }
            // default case to exit on wrong input!
            default:
                cout << "Exiting!\n\n";
                exit(1);
        }
    } while (
        1);  // infinite loop, program will exit when user enters invalid input
}

/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~$ g++ ./inheritance.cpp
fpllab@fpllab-OptiPlex-9020:~$ ./a.out
Enter 1 for circle, 2 for rectangle, 3 for triangle, anything else to exit!
1
Enter radius of circle!
r: 5
Area of circle is 78.5398!
Destroying 0x7fffb4397800!
Enter 1 for circle, 2 for rectangle, 3 for triangle, anything else to exit!
2
Enter length and breadth of rectangle!
5
6
Area of Rectangle is 30!
Destroying 0x7fffb4397800!
Enter 1 for circle, 2 for rectangle, 3 for triangle, anything else to exit!
3
Enter 3 sides of triangle!
5
6
7
Area of triangle is 84!
Destroying 0x7fffb4397800!
Enter 1 for circle, 2 for rectangle, 3 for triangle, anything else to exit!
0
Exiting!
*/
