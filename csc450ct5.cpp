// CSC450 Module 5:  User Input Program
//
// Append user input to a file, and then, for some reason, 
// write a reversed copy of the file to a new file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 


bool appendStringToFile(const string &filename, const string &data) {
	ofstream outFile(filename, ios::app); // open in append mode
	if (!outFile) {
		cerr << "Error opening file for writing." << endl;
		return false;
	}
	outFile << data << endl;
	outFile.close();
	
	return true;
}

// Save a reversed copy of a given file
bool saveReversedFile(const string &originalFile, const string &reversedFile) {
	ifstream inFile(originalFile);
	if (!inFile) {
		cerr << "Error opening original file for reading." << endl;
		return false;
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
		return false;
	}

	// Reverse the string
	// You can apparently do this by using .rbegin() and rend()
	// which are iterators that point to end/beginning. 
	string reversedContents = string(fileContents.rbegin(), fileContents.rend());

	// Write the reversed string to the output file
	outFile << reversedContents;

	// Close the output file
	outFile.close();
	
	return true;
}


int main(int argc, char **argv) {

	const string INPUT_FILE_NAME = "CSC450_CT5_mod5.txt";
	const string REVERSED_OUTPUT_FILE_NAME = "CSC450-mod5-reverse.txt";
	
	// Get input from the user 
	cout << "Enter a string: ";
	string input;
	getline(cin, input);

	// Save it to the file (in append mode)
	// This path is relative to the current working directory,
	// not necessarily the executable. 
	appendStringToFile(INPUT_FILE_NAME, input);
	cout << "Data appended to CSC450_CT5_mod5.txt." << endl;
	
	// Reverse the file and save it to a new file
	// (This requires re-reading it, but should be OK for our purposes here)
	
	cout << "Now we are going to reverse the contents of the file and save it." << endl;

	saveReversedFile(INPUT_FILE_NAME, REVERSED_OUTPUT_FILE_NAME);

	cout << "Saved to " << REVERSED_OUTPUT_FILE_NAME << endl;
	return 0;
}
