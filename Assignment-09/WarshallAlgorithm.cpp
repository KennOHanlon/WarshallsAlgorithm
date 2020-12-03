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
	//opening file and initializing a matrix to hold the set of relations
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}

	for (int i = 0; i < 27; i++) {
		inFile >> relationSet[i][0];
		relationSet[i][0] = relationSet[i][0] - 1;
		inFile >> relationSet[i][1];
		relationSet[i][1] = relationSet[i][1] - 1;
	}
	
	cout << "Analyzing file : " << fileName << endl << endl << endl;

	inFile.close();

	// using the matrix for the set of relations to initialize the matrix for the transitive closure
	for (int i =0; i < 27; i++) {
		transitiveClosure[relationSet[i][0]][relationSet[i][1]] = 1;
		progressGraph[relationSet[i][0]][relationSet[i][1]] = 1;
	}

}





//print information function to write output to another file
void Warshall::printInformationToFile(string fileName)
{
	ofstream outFile;
	outFile.open(fileName);

	if (!outFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}
	else {
		outFile << "----------------------------------------------------------------------------" << endl << endl << "Name:\t\t Kenneth O'Hanlon" << endl;
		outFile << "Access ID:\t fj7615" << endl << endl << "----------------------------------------------------------------------------";
		outFile << endl << endl << "Transitive Closure Matrix: " << endl << endl;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				outFile << transitiveClosure[i][j] << "  ";
			}
			outFile << endl;
		}
	}

	getCount();
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
	outFile.close();
}

void Warshall::sortGraph(int graphInProgress[][20])
{
	for (int k = 0; k < 20; k++) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				incrementCount();
				if (progressGraph[i][j] == 1 || ((progressGraph[i][k] == 1) && (progressGraph[k][j] == 1))) {
					transitiveClosure[i][j] = 1;
					
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			progressGraph[i][j] = transitiveClosure[i][j];
		}
	}
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

void Warshall::returnCount(string fileName) {
	ofstream outFile;
	outFile.open(fileName);
	if (!outFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}
	else {
		outFile << "Number of Vertices (n): \t 20" << endl;
		outFile << "Time Complexity: \t\t " << getCount() << endl << endl;
		outFile << "n^3 = 20^3 = 8000 therefore the algorithm follows n^3 complexity" << endl <<endl;
		outFile << "**Please note that this calculation count is determined by the sortGraph function within the program itself.";
	}
	outFile.close();
}
