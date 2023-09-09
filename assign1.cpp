#include "assign1.h";

void checkArr(vector <int> vec) { //finds a value in the array
	int inp;
	int index = -1;
	cout << "Which integer index would you like to check? >> ";
	cin >> inp; //input of index
	for (int i = 0; i < 100; i++) { //checks through the array
		if (vec[i] == inp) {
			index = i;
				
		}
	}
	if (index >= 0) {
		cout << index; //outputs the correct index
	}
	else {
		cout << "Your integer was not in the array."; //prints if the value is not in the array
	}
	cout << endl;

	
}

void modArray(vector<int> vec) { //modifies a value in the array
	int index, newVal, oldVal;
	cout << "Input the index of the array you want to change. >> ";
	cin >> index; //input of the index
	cout << endl;
	cout << "Input the value you want to use. >> ";
	cin >> newVal; //input of the new val
	cout << endl;
	try {
		oldVal = vec.at(index); //checks to make sure index is valid
		vec[index] = newVal;
		cout << endl;
		cout << "Old value: " << oldVal<< "  New value: " << newVal << endl;

	}
	catch (...) { //catches error
		cout << "You entered an invalid input." << endl;
	}
	
}

void addToArray(vector <int> vec) { //adds a value to the array
	;
	int inp;
	try {
		cout << "What value would you like to add to the array? >> ";
		cin >> inp; //takes the input
		if (cin.fail()) {
			throw 1; //throws an error if the input is invalid
		}
		else {
			vec.push_back(inp); //if valid, puts the input on the array
		}
	}
	catch (int error) { //catches the error
		cout << "You entered an invalid input." << endl;
	}
}

void removeFromArray(vector <int> vec) { //changes certain index to 0
	int index;
	cout << "Input the index you would like to change to zero. >> ";
	cin >> index; //takes input 
	vec[index] = 0; //changes value to 0
}

int main() {
	vector <int> vec; //initializes vector
	ifstream inFile("vals.txt"); //input file
	int x;

	if (inFile.is_open()) { //goes through input file and makes the vector
		while (inFile >> x) {
			vec.push_back(x);
		}
	}
	inFile.close();
	checkArr(vec);
	modArray(vec);
	addToArray(vec);
	removeFromArray(vec);


}