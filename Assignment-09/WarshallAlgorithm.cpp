#include "WarshallAlgorithm.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
using namespace std;

//constructor used for initializing the unsortedData vector from each dataset
Warshall::Warshall(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}

	for (int i = 0; i < 27; i++) {
		inFile >> relationSet[i][1];
		inFile >> relationSet[i][2];
	}
	
	cout << "Analyzing file : " << fileName << endl << endl << endl;
	//For verification purposes
	//cout << "The number of elements in the dataset is: " << getNumElements() << endl;

	inFile.close();
}





//print menu function to test count functions
void Warshall::printInformationToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);

	if (!outFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}
	else {
		outFile << "------------------------------------" << endl << endl << "Name:\t Kenneth O'Hanlon" << endl;
		outFile << "Access ID:\t fj7615" << endl << "Transitive Closure Matrix: " << endl << endl;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				outFile << transitiveClosure[i][j] << "  ";
			}
			outFile << endl;
		}
	}
	//int userInput = 0;
	//while (userInput != 99) {
	//	cout << "Enter 1 for getting the Count:" << endl << "Enter 2 for incrementing the count:" << endl << "Enter 3 for resetting the count:" << endl << "Enter 4 for writing effiency to file:" << endl;
	//	cin >> userInput;

	//	if (userInput == 1) {
	//		getCount();
	//	}
	//	else if (userInput == 2) {
	//		incrementCount();
	//	}
	//	else {
	//		cout << "Improper input" << endl;
	//	}
	//}
}

void Warshall::sortGraph(int graphInProgress[][20])
{
}

//count functions to keep track of number of computations 
void Warshall::incrementCount()
{
	counter++;
}

int Warshall::getCount()
{
	cout << counter << endl;
	return counter;
}
