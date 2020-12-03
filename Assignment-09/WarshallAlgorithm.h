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
	int transitiveClosure[20][20];
	long counter = 0;
	string originalFileName;

public:

	//--- CONSTRUCTOR ---//
	Warshall(string fileName);

	//--- Functions recording algorithm efficiency ---//
	int getCount();
	void incrementCount();
	void printInformation();


	//--- Algorithms for partitioning the dataset and using quicksort ---//
	void sortGraph(int graphInProgress[][20]);


};

