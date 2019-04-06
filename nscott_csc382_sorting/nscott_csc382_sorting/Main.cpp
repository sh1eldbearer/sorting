#include <iostream>
#include <array>

#include "LinkedList.h"

template<typename T> void GetUserInput(T* userInput);
bool TestUserInput();
template <typename T> bool SizeCheck(int listSize, bool verbose);
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

	while (runProgram)
	{
		// Menu display
		std::cout << "**********************************" << std::endl;
		std::cout << "*** DOUBLY-LINKED LIST PROGRAM ***" << std::endl;
		std::cout << "**********************************" << std::endl;
		std::cout << " 1. Add new node " << std::endl;
		std::cout << " 2. Remove node" << std::endl;
		std::cout << " 3. Find data in list" << std::endl;
		std::cout << " 4. Find lowest value in the list" << std::endl;
		std::cout << " 5. Find highest value in the list" << std::endl;
		std::cout << " 6. Display list" << std::endl;
		std::cout << " 7. Display list in reverse order" << std::endl;
		std::cout << " 8. Exit program" << std::endl << std::endl;

		std::cout << "11. Auto-populate some nodes" << std::endl;
		std::cout << "12. Print a detailed list" << std::endl << std::endl;

		std::cout << "21. Test Insertion Sort" << std::endl;
		std::cout << "22. Test Quick Sort" << std::endl << std::endl;

		std::cout << "Your choice: ";
		std::cin >> menuChoice;
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;

		switch (menuChoice)
		{
		case 1: // Inputs a new node containing a inputted key value into the list
			std::cout << "What data would you like to store in this node? ";
			GetUserInput(&userInput);
			if (TestUserInput())
			{
				myList.Insert(userInput);
			}
			break;
		case 2: // Deletes the first node found containing the inputted value
			// If the list has no nodes, displays an error message
			if (myList.IsEmpty())
			{
				std::cout << "There are no nodes in the list." << std::endl;
			}
			else
			{
				std::cout << "What value would you like to delete from the list? ";
				GetUserInput(&userInput);
				if (TestUserInput())
				{
					myList.Delete(userInput);
				}
			}
			break;
		case 3: // Finds a value in the list
			// If the list has no nodes, displays an error message
			if (myList.IsEmpty())
			{
				std::cout << "There are no nodes in the list." << std::endl;
			}
			else
			{
				std::cout << "What value would you like to find in the list? ";
				GetUserInput(&userInput);
				if (TestUserInput())
				{
					myList.Find(userInput);
				}
			}
			break;
		case 4: // Returns the lowest value stored in the list
			userInput = myList.Minimum();
			if (userInput != NULL)
			{
				std::cout << "The lowest value stored in the list is: " <<
					myList.Minimum() << std::endl;
			}
			break;
		case 5: // Returns the highest value stored in the list
			userInput = myList.Maximum();
			if (userInput != NULL)
			{
				std::cout << "The highest value stored in the list is: " <<
					myList.Maximum() << std::endl;
			}
			break;
		case 6: // Displays the list of the values stored, from head to tail
			myList.PrintList(false, false);
			break;
		case 7: // Displays the list of the values stored, from tail to head
			myList.PrintList(true, false);
			break;
		case 8: // Exits the program
			runProgram = false;
			break;
		case 11: // Adds a random amount of random values to the list
			for (int i = 0; i < (std::rand() % 15 + 10); i++)
			{
				userInput = std::rand() % 101;
				myList.Insert(userInput);
			}
			break;
		case 12: // Prints a list of each value, and the adjacent values and node addresses
			myList.PrintList(false, true);
			break;
		case 21:
			//std::array<int, 4> testVals = { 40, 13, 20, 8 };
			//std::array<int, 10> testVals = { 9, 1, 4, 7, 8, 3, 6, 10, 5, 2 };
			std::array<int, 15>  testVals = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
			for (int i = 0; i < testVals.size(); i++)
			{
				myList.Insert(testVals[i]);
			}
			InsertionSort(myList);
			break;
		case 22:
			//std::array<int, 4> testVals = { 40, 13, 20, 8 };
			//std::array<int, 10> testVals = { 9, 1, 4, 7, 8, 3, 6, 10, 5, 2 };
			std::array<int, 15>  testVals = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
			for (int i = 0; i < testVals.size(); i++)
			{
				myList.Insert(testVals[i]);
			}
			QuickSort(myList);
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
	// If the element has one or less elements, it is already sorted, and no further action should be taken
	if (SizeCheck(list.GetNodeCount(), true))
	{
		return;
	}


}