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
	double tempData;
	originalFileName = fileName;
	inFile.open(fileName);

	if (!inFile) {
		cout << "ERROR-The file " << fileName << " failed opening." << endl;
		exit(1);
	}

	while (inFile.good()) {
		incrementCount();
		inFile >> tempData;
		unsortedData.push_back(tempData);
	}
	setNumElements(counter);
	resetCount();
	cout << "Analyzing file : " << originalFileName << endl << endl << endl;
	//For verification purposes
	//cout << "The number of elements in the dataset is: " << getNumElements() << endl;

	inFile.close();
}

void Quicksort::efficiencyToFile()
{
	//temporary assignment of data values for testing purposes
	//for (int i = 0; i < unsortedData.size(); i++) {
	//	sortedData.push_back( unsortedData.at(i));
	//}


	ofstream outFile;
	string fileName = createFileName();
	outFile.open(fileName);

	if (!outFile) {
		cout << "ERROR - The file " << fileName << " failed opening." << endl;
		exit(1);
	}

	for (int i = 0; i < unsortedData.size() - 1; i++) {
		outFile << unsortedData[i] << endl;
	}
	cout << "Number of elements: " << numElements << endl;
	cout << "Comparisons made: " << counter << endl << "-------------------------------------------" << endl << "-------------------------------------------" << endl << endl;

	outFile.close();
}

string Quicksort::createFileName()
{

	originalFileName = calculateEfficiency() + originalFileName;
	//originalFileName.append(to_string(numElements) + ".txt");
	return originalFileName;
}

int Quicksort::hoaresPartition(vector<double>& temp, int low, int high)
{
	double pivot = temp[low];
	double tempDouble = 0;
	//cout << "The pivot value is: " << pivot << endl;
	int i = low - 1;
	int j = high + 1;
	while (1)
	{
		counter--;
		counter--;
		do {
			incrementCount();
			incrementCount();
			i++;
			//cout << "Value of i: " << i << endl;
			//cout << "Value of j: " << j << endl;
		} while (temp[i] < pivot);

		do {
			incrementCount();
			incrementCount();
			j--;
			//cout << "Value of i: " << i << endl;
			//cout << "Value of j: " << j << endl;
		} while (temp[j] > pivot);

		if (i >= j) {
			counter--;
			return j;
		}
		swap(temp[i], temp[j]);


		//code verifying that swap worked
		//cout << "--------------------" << endl << "Test swapping values at indicies" << endl;
		//cout << "The value at index i: " << temp[i] << endl << "The value at index j: " << temp[j] << endl;

		//tempDouble = temp[j];
		//temp.at(j) = temp.at(i);
		//temp.at(i) = tempDouble;

		//code to verify that swap was working
		//cout << "--------------------" << endl << "Post swapping values" << endl;
		//cout << "The value at index i: " << temp[i] << endl << "The value at index j: " << temp[j] << endl;

	}

}




//print menu function to test count functions
void Warshall::printInformation()
{
	int userInput = 0;
	while (userInput != 99) {
		cout << "Enter 1 for getting the Count:" << endl << "Enter 2 for incrementing the count:" << endl << "Enter 3 for resetting the count:" << endl << "Enter 4 for writing effiency to file:" << endl;
		cin >> userInput;

		if (userInput == 1) {
			getCount();
		}
		else if (userInput == 2) {
			incrementCount();
		}
		else if (userInput == 3) {
			resetCount();
		}
		else if (userInput == 4) {
			efficiencyToFile();
		}
		else {
			cout << "Improper input" << endl;
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
