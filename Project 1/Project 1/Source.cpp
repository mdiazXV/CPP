//Project One
//Author: Mariah Diaz
//This program utilizes a class named myString to manipulate a string and
//tests the functions of said class
#include<iostream>
#include<string>
using namespace std;

//Mystring class
class MyString {

	//Class variables
private:
	string myString;

	//Class functions
public:

	//Default constructor
	MyString() {
		myString = "";
	}

	//Return size of the string
	int size() {
		return myString.length();
	}

	//Add string to the start
	void addStart(string mystring) {
		if (size() > 25) {
			cout << "You can't add string at the front. String already in length 25" << endl;
		}
		else if ((size() + mystring.length()) > 25) {
			cout << "You can't add string at the front. String has maximum length 25" << endl;
		}
		else {
			myString = mystring + myString;
			cout << "You successfully added new string." << endl;
		}
	}

	//Add string to the end
	void addEnd(string mystring) {
		if (size() > 25) {
			cout << "You can't add string at the end.String already in length 25" << endl;
		}
		else if ((size() + mystring.length()) > 25) {
			cout << "You can't add string at the end.String has maximum length 25" << endl;
		}
		else {
			myString = myString + mystring;
			cout << "You successfully added new string." << endl;
		}
	}

	//Display only part of the string
	void partString(int startPos, int length) {
		if (startPos < 0) {
			cout << "Error!!! String index start from 0." << endl;
		}
		else if (startPos > 25) {
			cout << "Error!!! Maximum string length is 25." << endl;
		}
		else if (startPos + length > 25) {
			cout << "Error!!! Maximum string length is 25.." << endl;
		}
		else {
			for (int i = startPos; i <= length; i++) {
				cout << myString[i];
			}
			cout << endl;
		}
	}

	//Replace the string
	void replPartString(string mystring, int startPos) {
		if (startPos < 0) {
			cout << "Error!!! String index start from 0." << endl;
		}
		else if (startPos > 25) {
			cout << "Error!!! Maximum string length is 25." << endl;
		}
		else if ((size() - startPos) + mystring.length() > 25) {
			cout << "Error!!! Maximum string length is 25.." << endl;
		}
		else {
			string temp = "";
			for (int i = 0; i < size(); i++) {
				if (i == startPos - 1) {
					for (int j = 0; j < mystring.length(); j++) {
						temp += mystring[j];

					}
					myString = temp;
				}
				else {
					temp += myString[i];
				}
			}

			cout << "Successfully replaced!!!" << endl;
		}
	}

	//Replace the string with a new string
	void replWholeString(string mystring) {
		if (mystring.length() > 25) {
			cout << "Can't replace.Max length of the string is 25." << endl;
		}
		else {
			myString = mystring;
			cout << "Successfully replaced." << endl;
		}
	}

	//Compare strings
	bool compareString(string mystring) {

		if (size() != mystring.length()) {
			return false;
		}
		else {
			for (int i = 0; i < size(); i++) {
				if (myString[i] != mystring[i]) {
					return false;
				}
			}
			return true;
		}
	}

	//Initialize the string
	void initString() {
		myString = "";
	}

	//Setter
	void setstring(string mystring) {
		if (mystring.length() > 25) {
			cout << "Cannot add string.Max string length is 25." << endl;
		}
		else {
			myString = mystring;
		}

	}

	//Getter
	string getString() {
		return myString;
	}

	//Print the string
	void printStringScreen() {
		cout << "My string = " << myString << endl;
	}

	//Check for numerics
	bool numericString() {

		for (int i = 0; i < size(); i++) {
			if ((myString[i]) >= '0' && (myString[i]) <= '9' || (myString[i]) == '.')
				i++;
			else
				return false;
		}
		return true;
	}

	//Check for alphabetics
	bool alphabeticString() {

		for (int i = 0; i < size(); i++) {
			if (!isalpha(myString[i]))
				return false;

		}
		return true;
	}
};


int main()
{
	MyString mstring;

	mstring.setstring("World!!Good Morning");
	mstring.printStringScreen();

	//Add at start and print
	mstring.addStart("Hello ");
	mstring.printStringScreen();

	//Add end and print
	mstring.addEnd(".Nice Day.");
	mstring.printStringScreen();

	//Add end check
	mstring.addEnd(".");
	mstring.printStringScreen();

	//Print the string size
	cout << "Size of the string= " << mstring.size() << endl;

	//Part of the string
	mstring.partString(1, 10);

	//Replace the string
	mstring.replPartString("Day", 19);
	mstring.printStringScreen();

	//Repalce the entire string
	mstring.replWholeString("How are you?");
	mstring.printStringScreen();

	//Compare string
	if (mstring.compareString("How are you?") == 1)
	{
		cout << "Both strings are equal" << endl;
	}
	else {
		cout << "Both strings are not equal" << endl;
	}

	//Check for numeric
	if (mstring.numericString()) {
		cout << "String is numeric" << endl;
	}
	else {
		cout << "String is not numeric" << endl;
	}

	//Check for alphabetic
	if (mstring.alphabeticString()) {
		cout << "String is alphabetic string" << endl;
	}
	else {
		cout << "String is not alphabetic string" << endl;
	}

	//Check for numeric
	mstring.setstring("589623");
	if (mstring.numericString()) {
		cout << "String is numeric" << endl;
	}
	else {
		cout << "String is not numeric" << endl;
	}

	system("pause");
}