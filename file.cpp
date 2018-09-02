/*
 * file.cpp
 *
 *  Created on: 28-Aug-2018
 *      Author: student
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream i;
	ofstream o;
	i.open("src.txt");
	o.open("dest.txt");
	cout<<"Reading src to dest!\n";
	while(!i.eof()) {
		o.put(i.get());
	}
	cout<<"Reading dest!\n";
	i.close();
	o.close();
	i.open("dest.txt");
	while(!i.eof()) {
		char str[256];
		i.getline(str, 256);
		cout<<str<<endl;
	}
}
