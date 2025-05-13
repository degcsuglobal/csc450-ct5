/*
Program: Create a C++ program that will obtain input from a user and store it into the provided CSC450_CT5_mod5.txt Download CSC450_CT5_mod5.txtfile. 
Download CSC450_CT5_mod5.txt Download CSC450_CT5_mod5.txtfile. Your program should append it to the provided text file, without deleting the existing data: 
Store the provided data in the CSC450_CT5_mod5.txt file.
Create a reversal method that will reverse all of the characters in the CSC450_CT5_mod5.txt file and store the result in a CSC450-mod5-reverse.txt file.

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std; 


void appendStringToFile(const string &filename, const string &data) {
	ofstream outFile(filename, ios::app); // open in append mode
	if (!outFile) {
		cerr << "Error opening file for writing." << endl;
		return;
	}
	outFile << data << endl;
	outFile.close();
}

// Save a reversed copy of a given file
void saveReversedFile(const string &originalFile, const string &reversedFile) {
	ifstream inFile(originalFile);
	if (!inFile) {
		cerr << "Error opening original file for reading." << endl;
		return;
	}

	// Read the entire thing into one string
	// (This would be bad if it was a huge file)
	string fileContents; 
	string line;
	while (getline(inFile, line)) {
		fileContents += line + "\n"; // Add a newline character to preserve line breaks
	}

	inFile.close();

	// Open the output file
	ofstream outFile(reversedFile);
	if (!outFile) {
		cerr << "Error opening reversed file for writing." << endl;
		return;
	}

	// Reverse the string
	// You can apparently do this by using .rbegin() and rend()
	// which are iterators that point to end/beginning. 
	string reversedContents = string(fileContents.rbegin(), fileContents.rend());

	// Write the reversed string to the output file
	outFile << reversedContents;

	// Close the output file
	outFile.close();
}


int main(int argc, char **argv) {

	// Get input from the user 
	cout << "Enter a string: ";
	string input;
	getline(cin, input);

	// Save it to the file (in append mode)
	// This path is relative to the current working directory,
	// not necessarily the executable. 
	appendStringToFile("CSC450_CT5_mod5.txt", input);
	cout << "Data appended to CSC450_CT5_mod5.txt." << endl;

	cout << "Now we are going to reverse the contents of the file and save it to CSC450-mod5-reverse.txt" << endl;

	// Reverse the file and save it to a new file
	// (This requires re-reading it, but who cares)
	saveReversedFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

	return 0;
}
