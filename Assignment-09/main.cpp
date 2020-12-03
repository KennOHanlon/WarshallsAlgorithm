//------------------------------------------------------------------------------------------
//	Assignment:		Divide and Conquer - Quicksort Implementation
//	Name:			Kenneth O'Hanlon
//	Class:			CSC3110
//	Date:			November 11, 2020
//	Description:	To utilize Hoare's partition alongside Quicksort in order to display the
//					efficiency of the alogrithm on predetermined datasets.
//------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "WarshallAlgorithm.h"

using namespace std;


const string INPUT_FILE = "Graph1.data";
const string OUTPUT_PROOF = "TimeComplexityProof.txt";
const string outputFile = "TransitiveClosureOutput.txt";

int main() {
	
	Warshall testingOutput(INPUT_FILE);
	testingOutput.sortGraph(testingOutput.transitiveClosure);

	testingOutput.printInformationToFile(outputFile);
	testingOutput.returnCount(OUTPUT_PROOF);

	//Quicksort dataset6(DATASET_6);
	//dataset6.QuickSortAlgorithm(min, dataset6.getNumElements() - 1);
	//dataset6.efficiencyToFile();


	system("pause");
	return 0;
}