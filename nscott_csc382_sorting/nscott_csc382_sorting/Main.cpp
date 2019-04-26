#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <array>
#include <stack>
#include <random>
#include "LinkedList.h"

template<typename T> void GetUserInput(T*);
bool TestUserInput();
template <typename T> int ClockInsertionSort(LinkedList<T> &, bool);
template <typename T> void ClockMultipleInsertionSorts(LinkedList<T> &, int, std::string, std::string);
template <typename T> int ClockQuickSort(LinkedList<T> &, bool);
template <typename T> void ClockMultipleQuickSorts(LinkedList<T> &, int, std::string, std::string);
template <typename T> void GetDataFromFile(LinkedList<T> &, std::string);
template <typename T> void OutputDataToFile(LinkedList<T> &, std::string);
template <typename T> bool SizeCheck(T, bool);
template <typename T> void InsertionSort(LinkedList<T>& list);
template <typename T> void QuickSort(LinkedList<T>& list);

// Main program loop
int main()
{
	// Linked list object
	LinkedList<int> myList;
	bool runProgram = true;
	auto userInput = 0;
	int menuChoice = 0;

	// Input files
	const std::string list10 = "num10.dat";
	const std::string list100 = "num100.dat";
	const std::string list1000 = "num1000.dat";
	const std::string list10000 = "num10000.dat";
	const std::string list100000 = "num100000.dat";
	const std::string listOutputFile = "list_output.txt";
	const std::string runtimeOutputFile = "times_output.txt";
	std::string inputLine;

	while (runProgram)
	{
		// Menu display
		std::cout << "*********************************************" << std::endl;
		std::cout << "********       SORTING PROGRAM       ********" << std::endl;
		std::cout << "*********************************************" << std::endl << std::endl;

		std::cout << " Please choose one of the following options:" << std::endl << std::endl;

		std::cout << "              | Insertion Sort | Quick Sort |" << std::endl;
		std::cout << "     10 nodes |       1        |     11     |" << std::endl;
		std::cout << "    100 nodes |       2        |     12     |" << std::endl;
		std::cout << "   1000 nodes |       3        |     13     |" << std::endl;
		std::cout << "  10000 nodes |       4        |     14     |" << std::endl;
		std::cout << " 100000 nodes |       5        |     15     |" << std::endl << std::endl;

		std::cout << " Exit program |       99" << std::endl << std::endl;

		std::cout << "Your choice: ";
		std::cin >> menuChoice;
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;

		switch (menuChoice)
		{
		// Insertion sorts
		case 1: // Insertion sort on 10 values
			GetDataFromFile(myList, list10);
			ClockInsertionSort(myList, true);
			myList.PrintList(false, false);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 2: // Insertion sort on 100 values
			GetDataFromFile(myList, list100);
			ClockInsertionSort(myList, true);
			myList.PrintList(false, false);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 3: // Insertion sort on 1000 values
			GetDataFromFile(myList, list1000);
			ClockInsertionSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 4: // Insertion sort on 10000 values
			GetDataFromFile(myList, list10000);
			ClockInsertionSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 5: // Insertion sort on 100000 values
			GetDataFromFile(myList, list100000);
			ClockInsertionSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		// Quick Sorts
		case 11: // Quick sort on 10 values
			GetDataFromFile(myList, list10);
			ClockQuickSort(myList, true);
			myList.PrintList(false, false);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 12: // Quick sort on 100 values
			GetDataFromFile(myList, list100);
			ClockQuickSort(myList, true);
			myList.PrintList(false, false);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 13: // Quick sort on 1000 values
			GetDataFromFile(myList, list1000);
			ClockQuickSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 14: // Quick sort on 10000 values
			GetDataFromFile(myList, list10000);
			ClockQuickSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		case 15: // Quick sort on 100000 values
			GetDataFromFile(myList, list100000);
			ClockQuickSort(myList, true);
			OutputDataToFile(myList, listOutputFile);
			break;
		// Hidden dev functions that run each sort multiple times and output their completion times to an output file
		case 31: // Insertion sort on 10 values
			ClockMultipleInsertionSorts(myList, 10, list10, runtimeOutputFile);
			break;
		case 32: // Insertion sort on 100 values
			ClockMultipleInsertionSorts(myList, 10, list100, runtimeOutputFile);
			break;
		case 33: // Insertion sort on 1000 values
			ClockMultipleInsertionSorts(myList, 10, list1000, runtimeOutputFile);
			break;
		case 34: // Insertion sort on 10000 values
			ClockMultipleInsertionSorts(myList, 10, list10000, runtimeOutputFile);
			break;
		case 35: // Insertion sort on 100000 values
			ClockMultipleInsertionSorts(myList, 10, list100000, runtimeOutputFile);
			break;
		case 41: // Quick sort on 10 values
			ClockMultipleQuickSorts(myList, 10, list10, runtimeOutputFile);
			break;
		case 42: // Quick sort on 100 values
			ClockMultipleQuickSorts(myList, 10, list100, runtimeOutputFile);
			break;
		case 43: // Quick sort on 1000 values
			ClockMultipleQuickSorts(myList, 10, list1000, runtimeOutputFile);
			break;
		case 44: // Quick sort on 10000 values
			ClockMultipleQuickSorts(myList, 10, list10000, runtimeOutputFile);
			break;
		case 45: // Quick sort on 100000 values
			ClockMultipleQuickSorts(myList, 10, list100000, runtimeOutputFile);
			break;
		case 99: // Exits the program
			runProgram = false;
			break;
		default: // Invalid option
			std::cout << "No such option exists. Please try again." << std::endl;
			break;
		}

		std::cout << std::endl;
	}

	return 0; // Exit program
}

// Gets user input
template<typename T> void GetUserInput(T* userInput)
{
	std::cin >> *userInput;
}

// Tests cin for failure and clears cin's flags and input buffer afterward
bool TestUserInput()
{
	bool failure;

	// Checks to see if there were any problems getting the user's input
	failure = std::cin.fail();
	// Clears cin's failure flag for next input
	std::cin.clear();
	// Clears the input buffer
	std::cin.ignore(256, '\n');

	if (failure) // User did not input a valid value
	{
		std::cout << "Invalid entry. Please try again." << std::endl;
	}

	// Returns whether the input was valid (true) or not (false)
	return !failure;
}

template <typename T>
int ClockInsertionSort(LinkedList<T> &myList, bool verbose)
{
	clock_t runTimer;

	// Starts tracking time
	runTimer = clock();
	// Runs the insertion sort
	InsertionSort(myList);
	// Finishes tracking time
	runTimer = clock() - runTimer;

	// Outputs the run time to the console, if desired
	if (verbose)
	{
		std::cout << "Insertion sort took " << runTimer << " clicks to complete." << std::endl << std::endl;
	}

	return runTimer;
}

template <typename T>
void ClockMultipleInsertionSorts(LinkedList<T> &myList, int timesToRun, std::string inputFileName, std::string outputFileName)
{
	// Opens the target file and clears its contents (will create the file if it does not already exist)
	std::ofstream outputFile;
	outputFile.open(outputFileName, std::ios::out);
	outputFile.clear();

	// Runs a user-defined numer of insertion sorts, and records their run times to an external file
	for (int count = 0; count < timesToRun; count++)
	{
		GetDataFromFile(myList, inputFileName);
		outputFile << ClockInsertionSort(myList, false) << "\n";
	}

	outputFile.close();

	std::cout << "The runtimes of each of the " << timesToRun <<
		" insertion sorts has been outputted to " << outputFileName << std::endl;
}

template <typename T>
int ClockQuickSort(LinkedList<T> &myList, bool verbose)
{
	clock_t runTimer;

	// Starts tracking time
	runTimer = clock();
	// Runs the insertion sort
	QuickSort(myList);
	// Finishes tracking time
	runTimer = clock() - runTimer;

	// Outputs the run time to the console, if desired
	if (verbose)
	{
		std::cout << "Quick sort took " << runTimer << " clicks to complete." << std::endl << std::endl;
	}

	return runTimer;
}

template <typename T>
void ClockMultipleQuickSorts(LinkedList<T> &myList, int timesToRun, std::string inputFileName, std::string outputFileName)
{
	// Opens the target file and clears its contents (will create the file if it does not already exist)
	std::ofstream outputFile;
	outputFile.open(outputFileName, std::ios::out);
	outputFile.clear();

	// Runs a user-defined numer of quick sorts, and records their run times to an external file
	for (int count = 0; count < timesToRun; count++)
	{
		GetDataFromFile(myList, inputFileName);
		outputFile << ClockQuickSort(myList, false) << "\n";
	}

	outputFile.close();

	std::cout << "The runtimes of each of the " << timesToRun <<
		" quick sorts has been outputted to " << outputFileName << std::endl;
}
// Retrieves data from an external file
template <typename T> 
void GetDataFromFile(LinkedList<T> &myList, std::string fileToOpen)
{
	// Opens the target file
	std::ifstream inputFile;
	inputFile.open(fileToOpen, std::ios::in);

	std::string inputLine;

	// Clears the list of any previous stored values
	myList.Clear();

	// Gets the data from the target file
	if (inputFile)
	{
		while (getline(inputFile, inputLine))
		{
			myList.Insert(std::stoi(inputLine), false);
		}
	}
	// If the target file doesn't exist, displays an error message
	else
	{
		std::cout << "There was an error reading from the input file." << std::endl;
	}

	inputFile.close();
}

// Outputs the stored data of a linked list to a target file
template<typename T>
void OutputDataToFile(LinkedList<T> &myList, std::string fileToOpen)
{
	// Opens the target file and clears its contents (will create the file if it does not already exist)
	std::ofstream outputFile;
	outputFile.open(fileToOpen, std::ios::out);
	outputFile.clear();

	LL_Iterator<T> listIterator(myList.GetHeadNode());

	// Iterates through the linked list, and prints each node's data to the target file
	for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
	{
		outputFile << listIterator.GetNodeData() << " ";
	}

	outputFile.close();
}

// Checks to see if the list has enough nodes to be sorted
template <typename T> bool SizeCheck(T listSize, bool verbose = false)
{
	// If the list only has one element, the array is already sorted
	if (listSize == 1)
	{
		// Displays a feedback message, if desired
		if (verbose)
		{
			std::cout << "The list is already sorted!" << std::endl;
		}
		return true;
	}
	// If the list has no elements, the array is empty (and technically already sorted)
	else if (listSize == 0)
	{
		// Displays a feedback message, if desired
		if (verbose)
		{
			std::cout << "The list is empty!" << std::endl;
		}
		return true;
	}
	return false;
}

template <typename T> void InsertionSort(LinkedList<T>& list)
{
	// If the element has one or less elements, it is already sorted, and no further action should be taken
	if (SizeCheck(list.GetNodeCount(), true))
	{
		return;
	}
	
	// Starts checking nodes with the second element (first element is "sorted" by default)
	LL_Iterator<T> nodeToSortIter(list.GetHeadNode()->GetNextNode());
	// Iterator for looking through previously sorted elements
	LL_Iterator<T> alreadySortedIter;

	// Displays the list contents before sorting each element (commented out unless debugging is necessary)
	//list.PrintList(false, false);

	// Iterates forward through all unsorted elements
	for (nodeToSortIter; nodeToSortIter.GetCurrentNode() != nullptr; nodeToSortIter.IterateFwd())
	{
		// Pointer to the current element being evaluated; will update pointer when values swap
		LL_Node<T>* nodeToInsert = nodeToSortIter.GetCurrentNode();
		
		// Establishes the first "already sorted" node to compare values with
		alreadySortedIter.SetCurrentNode(nodeToSortIter.GetCurrentNode()->GetPrevNode());

		// Iterates backward through all previously sorted elements
		for (alreadySortedIter; alreadySortedIter.GetCurrentNode() != nullptr; alreadySortedIter.IterateBack())
		{
			// If the current value being sorted is smaller, swap the stored values
			if (alreadySortedIter.GetNodeData() > nodeToInsert->GetNodeData())
			{		
				list.SwapValues(nodeToInsert, alreadySortedIter.GetCurrentNode());
				// Update the pointer to the new position of the value being checked
				nodeToInsert = alreadySortedIter.GetCurrentNode();
			}
			else
			{
				break;
			}
		}

		// Displays the list contents after sorting each element (uncomment for quick visual debug)
		//list.PrintList(false, false);
	}
}

template <typename T> void QuickSort(LinkedList<T>& list)
{
	// Holds the indexes of the elements that need to be checked
	std::stack<int> indexStack;
	T pivotValue; // The value currently stored in the pivot node
	int pivotIndex = 0; // The index of the pivot node
	int leftIndex = pivotIndex + 1; // The index of the lowest indexed element needing to be checked (swap node)
	int rightIndex = list.GetNodeCount() - 1; // The index of the highest indexed element needing to checked (comparison node)
	int leftPartitionIndex, rightPartitionIndex; // The index of the lowest and highest indexed element of the unsorted partion of the list 
	clock_t runTime;

	// Adds the pivot index to the index stack
	indexStack.push(pivotIndex); 
	// Adds the last element of the list to the index stack
	indexStack.push(rightIndex); 

	while (indexStack.size() > 0)
	{
		runTime = clock();
		// Sets the last element of the current partiton
		rightPartitionIndex = indexStack.top();
		indexStack.pop();
		// Sets the first element of the current partition
		leftPartitionIndex = indexStack.top();
		indexStack.pop();
		//std::cout << "Sorting nodes " << leftPartitionIndex << "-" << rightPartitionIndex << " ";

		// Sets the swap node as the first node after the current pivot node
		leftIndex = leftPartitionIndex + 1;
		// Sets the index of the pivot node
		pivotIndex = leftPartitionIndex;
		// Sets the highest index to start comparing node values at
		rightIndex = rightPartitionIndex;
		// Stores the pivot value for comparison
		pivotValue = list.FindByIndex(pivotIndex)->GetNodeData();

		// If the left index ever exceeds the right index, we should be done checking the list
		if (leftIndex > rightIndex)
		{
			//std::cout << "(" << clock() - runTime << " clicks)" << std::endl;
			continue;
		}

		// Sorting loop
		while (leftIndex < rightIndex)
		{
			// If the current swap node has a value smaller or equal to the pivot node, set the next node in the list as the swap node
			while ((leftIndex <= rightIndex) && (list.FindByIndex(leftIndex)->GetNodeData() <= pivotValue))
			{
				leftIndex++;
			}

			// If the current comparison node has a value greater than or equal to the pivot node, set the previous node in the last as the new comparison node
			while ((leftIndex <= rightIndex) && (list.FindByIndex(rightIndex)->GetNodeData() >= pivotValue))
			{
				rightIndex--;
			}

			// Once a node with a value smaller than the pivot node has been found, swap the values of the swap node and the comparison node
			if (rightIndex >= leftIndex)
			{
				list.SwapValues(list.FindByIndex(leftIndex), list.FindByIndex(rightIndex));
			}
		}

		// Once we reach the end of the current partition of nodes to be checked, swap the pivot node's value with the last swapped value
		if (pivotIndex <= rightIndex)
		{
			if (list.FindByIndex(pivotIndex)->GetNodeData() > list.FindByIndex(rightIndex)->GetNodeData())
			{
				list.SwapValues(list.FindByIndex(pivotIndex), list.FindByIndex(rightIndex));
			}
		}

		// Pushes indexes of the lowest and highest nodes of any partitions of the list that still need to be sorted
		if (leftPartitionIndex < rightIndex)
		{
			indexStack.push(leftPartitionIndex);
			indexStack.push(rightIndex - 1);
		}

		if (rightPartitionIndex > rightIndex)
		{
			indexStack.push(rightIndex + 1);
			indexStack.push(rightPartitionIndex);
		}

		//std::cout << "(" << clock() - runTime << " clicks)" << std::endl;
	}
}