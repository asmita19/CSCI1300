//Asmita Dhakal
//CSCI 1300 
//Reciatation: Bu Sun 202
//Cloud9 workspace esitor link: https://ide.c9.io/asmita97/csci1300
//Recitation 11- #4 Vector

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

int main() {

	vector <int> v;
	string number;
	int min;
	int max;
	bool flag = true; //flag for do while loop, exits when user enters q or Q

	do{
		cout << "Please enter a positive integer: " << endl << "Or enter 'Q' to quit." << endl;
		getline(cin, number);
	if (number == "q" || number == "Q"){
			flag = false;
		}
		else if (v.size() == 0){
			int tempo = stoi(number);
			v.push_back(tempo);
		}
		else if (v.size() != 0 && stoi(number) % 5 == 0){
			v.erase(v.begin()); //deletes first index of vector
		}
		else if (v.size() != 0 && stoi(number) % 3 == 0){
			v.pop_back(); //deletes last index of vector
		}
		else{
			int tempo = stoi(number);
			v.push_back(tempo);
		}
	}while (flag);
	cout << "The elements in the vector are: ";
	min = v.at(0); //Sets first index of vector to both min and max, alters the values later
	max = v.at(0);
	for(int i = 0; i < v.size(); i++){ //loops through the vector, prints out all values and modifies min and max values
		cout << v.at(i) << " ";
		if(v.at(i) > max){
			max = v.at(i);
		}
		if(v.at(i) < min){
			min = v.at(i);
		}
	}
	cout << endl;
	cout << "Min = " << min << endl;e
	cout << "Max = " << max << endl;
	return 0;

}