#include <iostream>
#include <array>

#include "DblLinkedList.h"

template<typename Type> void GetUserInput(Type* userInput);
bool TestUserInput();
template <typename Type> bool SizeCheck(int listSize, bool verbose);
template <typename Type> void InsertionSort(DblLinkedList<Type>& list);

// Main program loop
int main()
{
	// Linked list object
	DblLinkedList<double> myList;
	bool runProgram = true;
	double userInput = 0;
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

		std::cout << "21. Test Insertion Sort" << std::endl << std::endl;

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
					myList.Delete(myList.Find(userInput, true));
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
			myList.PrintList(false);
			break;
		case 7: // Displays the list of the values stored, from tail to head
			myList.PrintList(true);
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
			//std::array<double, 4> testVals = { 40, 13, 20, 8 };
			std::array<double, 15> testVals = { 3, 44, 38, 5,47,15,36,26,27,2,46,4,19,50,48 };
			for (int i = 0; i < (int)testVals.size(); i++)
			{
				myList.Insert(testVals[i]);
			}
			InsertionSort(myList);
			break;
		}

		std::cout << std::endl;
	}

	return 0; // Exit program
}

// Gets user input
template<typename Type> void GetUserInput(Type* userInput)
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

template <typename Type>
bool SizeCheck(Type listSize, bool verbose = false)
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

template <typename Type>
void InsertionSort(DblLinkedList<Type>& list)
{
	// If the element has one or less elements, it is already sorted, and no further action should be taken
	if (SizeCheck(list.GetNodeCount(), true))
	{
		return;
	}
	
	// Gets the node just after the head node (element 1)
	DblLLIterator<Type> unsortedIter(list.GetHeadNode()->GetNextNode());

	list.PrintList(false);
	for (unsortedIter; unsortedIter.GetCurrentNode() != nullptr; unsortedIter.GetNextNode())
	{
		Type unsortedValue = unsortedIter.GetNodeValue();
		std::cout << "Attempting to sort value " << unsortedIter.GetNodeValue() << std::endl;
		DblLLIterator<Type> insertionIter(unsortedIter.GetCurrentNode()->GetPrevNode());
		for (insertionIter; insertionIter.GetNodeValue() > unsortedValue; insertionIter.GetPrevNode())
		{
			std::cout << "Swapping value " << insertionIter.GetNodeValue() << " to the right with value " << insertionIter.GetCurrentNode()->GetNextNode()->GetValue() << std::endl;
			list.SwapValues(insertionIter.GetCurrentNode(), insertionIter.GetCurrentNode()->GetNextNode());
			list.PrintList(false);
			if (insertionIter.GetCurrentNode()->GetPrevNode() == nullptr)
			{
				std::cout << "We out" << std::endl;
				break;
			}
			//std::cout << insertionIter.GetNodeValue() << " vs. " << unsortedIter.GetNodeValue() << ", " << insertionIter.GetCurrentNode()->GetPrevNode()->GetValue() << " vs. " << unsortedIter.GetNodeValue();
		}
		std::cout << std::endl;
	}
	/*
	for (int i = 1; i < N; i++) { // O(N)
		X = a[i]; // X is the item to be inserted
			for (j = i-1; j >= 0 && a[j] > X; j--) // can be fast or slow
				a[j+1] = a[j]; // make a place for X
		a[j+1] = X; // index j+1 is the insertion point
	}
	*/
}