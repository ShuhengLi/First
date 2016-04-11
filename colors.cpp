/*
Implement Weighted_random() function
Author: Shuheng Li
Date: 04/11/2016
*/

#include<iostream>
#include<map>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

string weighted_random(map<string, int> colors);
void main() {
	map<string, int> colors;
	colors["green"] = 5;
	colors["red"] = 3;
	colors["blue"] = 2;
	string color;
	srand(time(NULL));
	double a = 0, b = 0, c = 0;

	int total = 1000;
	for (int i = 0; i < total; i++) {

		color = weighted_random(colors);
		if (color == "red") { a++; }
		else if (color == "green") { b++; }
		else { c++; }
		
		cout << color << endl;
	}
	cout << "red : " << a / total<< endl << "green :" << b / total << endl << "blue :" << c / total << endl;
	
	getchar();
}
string weighted_random(map<string, int> colors) {
	int sum = 0;
	for (auto it = colors.begin(); it != colors.end(); it++) {
		sum = sum + it->second;
		it->second = sum;
	}


	int n = (rand() % sum) + 1;
//	cout << n;
	for (auto it = colors.begin(); it != colors.end(); it++) {
		if (n <= it->second) {
			return it->first;
		}
	}
}
