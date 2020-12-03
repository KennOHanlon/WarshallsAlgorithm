#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
using namespace std;

class Warshall
{
private:
	int numRelations = 27;
	int relationSet[27][2];
	long counter = 0;
	string originalFileName;

public:

	int progressGraph[20][20] = { 0 };
	int transitiveClosure[20][20] = { 0 };

	//--- CONSTRUCTOR ---//
	Warshall(string fileName);

	//--- Functions recording algorithm efficiency ---//
	int getCount();
	void incrementCount();
	void printInformationToFile(string fileName);
	void returnCount(string fileName);

	//--- Algorithms for partitioning the dataset and using quicksort ---//
	void sortGraph(int graphInProgress[][20]);


};

