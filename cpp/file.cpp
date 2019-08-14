/*
 * file.cpp
 *
 * 		Created on       : 28-Aug-2018
 *      Author           : Akhil Narang
 *		Roll No.         : 203132
 *		Subject          : OOP
 *		Problem Statement:
 *      story.txt contains 5 lines
 *      WAP to idenfity the lines which do not start with the letter a
 *
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream f;
    char str[256];
    bool b = false;
    f.open("/home/student/story.txt");
    int i = 0;
    while (f.getline(str, 256, '\n') && !f.eof()) {
        i++;
        if (str[0] == 'a' || str[0] == 'A') {
            cout << "Line " << i << " starts with the letter A|a!" << endl;
            b = true;
        }
    }
    f.close();
    if (!b) {
        cout << "None of the lines start with the letter A|a!";
    }
}
