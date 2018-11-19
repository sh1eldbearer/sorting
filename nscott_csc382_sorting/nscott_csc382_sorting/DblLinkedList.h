#ifndef nsDblLinkedList_H
#define nsDblLinkedList_H

#include <iostream>

#include "DblLLIterator.h"
#include "DblLLNode.h"

template <typename T> class DblLinkedList
{
private:
	int nodeCount = 0; // Stores a count of the number of nodes in the list
	DblLLNode<T>* headNode = nullptr; // Stores a pointer to the first node in the list
	DblLLNode<T>* tailNode = nullptr; // Stores a pointer to the last node in the list
public:
	DblLinkedList() {} // Default constructor
	~DblLinkedList() {} // Default destructor

	 // Inserts a new node
	void Insert(T newData)
	{
		// Creates a new node
		DblLLNode<T>* newNode = new DblLLNode<T>();

		// Sets the data being stored in the new node
		newNode->SetNodeData(newData);
		IncreaseNodeCount();

		// If this is the first node, sets the new node as the head of the list
		if (headNode == nullptr && tailNode == nullptr)
		{
			// Sets the new node as the head
			headNode = newNode;
		}
		// If this is not the first node, adds the new node to the end of the list
		else
		{
			// New node's previous node is the old tail node
			newNode->SetPrevNode(tailNode);
			// Old tail node's next node is the new node
			tailNode->SetNextNode(newNode);
		}
		// Sets the new node as the new tail node
		tailNode = newNode;
		std::cout << "Successfully stored " << newNode->GetNodeData() 
			<< " as node " << (GetNodeCount() - 1);
		std::cout << std::endl;
	}
	// Finds node(s) that contain a particular value 
	template<typename T> DblLLNode<T>* Find(T dataToFind)
	{
		// Iterator
		nsDLLIterator<T> myIter(headNode);

		// Loops through the list until a matching value is found
		for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
		{
			if (myIter.GetNodeData() == dataToFind)
			{
				std::cout << "Value " << dataToFind << " found at " << 
					myIter.GetCurrentNode() << std::endl;
				return myIter.GetCurrentNode();
			}
		}
		// If no value is found, returns a nullptr
		std::cout << "Value not found in list." << std::endl;
		return nullptr;
	}

	// Finds node(s) that contain a particular value (can suppress output messages)
	template<typename T> DblLLNode<T>* Find(T dataToFind, bool suppressMsg)
	{
		nsDLLIterator<T> myIter(headNode); // Iterator

		// Loops through the list until a matching value is found
		for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
		{
			if (myIter.GetNodeData() == dataToFind)
			{
				if (!suppressMsg)
				{
					std::cout << "Value " << dataToFind << " found at " << 
						myIter.GetCurrentNode() << std::endl;
				}
				return myIter.GetCurrentNode();
			}
		}
		// If no value is found, returns a nullptr
		if (!suppressMsg)
		{
			std::cout << "Value not found in list." << std::endl;
		}
		return nullptr;
	}
	
	// Deletes a node
	void Delete(DblLLNode<T>* delNode)
	{
		// Stops the function if a nullptr is passed in
		if (delNode == nullptr)
		{
			std::cout << "Value not found in list." << std::endl;
			return;
		}
		// Node is only node in the list
		else if (delNode == headNode && delNode == tailNode)
		{
			headNode = nullptr;
			tailNode = nullptr;
		}
		// Node is the head node
		else if (delNode == headNode && delNode != tailNode)
		{
			headNode = delNode->GetNextNode();
			headNode->ClearPrevNode();
		}
		// Node is the tail node
		else if (delNode != headNode && delNode == tailNode)
		{
			tailNode = delNode->GetPrevNode();
			tailNode->ClearNextNode();
		}
		// Node is somewhere in the middle of the list
		else
		{
			delNode->GetNextNode()->SetPrevNode(delNode->GetPrevNode());
			delNode->GetPrevNode()->SetNextNode(delNode->GetNextNode());
		}
		DecreaseNodeCount();
		std::cout << "Value " << delNode->GetNodeData() << " deleted from the list." << 
			std::endl;
		// Deletes the node
		delete delNode;

	}
	
	// Prints the values stored in the list
	void PrintList(bool reverse) // Prints the values stored in the list
	{
		// As long as there is at least one node in the list, prints the list
		if (!IsEmpty())
		{
			// Prints the list from tail to head
			if (reverse)
			{
				nsDLLIterator<T> myIter(tailNode); // Iterator
				std::cout << "Current list contents (in reverse order): ";

				// Iterates through the list and outputs the contents of each node
				for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetPrevNode())
				{
					std::cout << myIter.GetNodeData() << " ";
				}
				std::cout << std::endl;
			}
			// Prints the list from head to tail
			else
			{
				nsDLLIterator<T> myIter(headNode); // Iterator
				std::cout << "Current list contents: ";

				// Iterates through the list and outputs the contents of each node
				for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
				{
					// Simply shows node's value
					std::cout << myIter.GetNodeData() << " ";
				}
				std::cout << std::endl;
			}
		}
		// The list is empty
		else
		{
			// Do nothing
		}
	}

	// Prints the values stored in the list with details about the adjacent nodes
	void PrintList(bool reverse, bool detailed) // Prints the values stored in the list
	{
		// As long as there is at least one node in the list, prints the list
		if (!IsEmpty())
		{
			// Prints the list from tail to head 
			if (reverse)
			{
				nsDLLIterator<T> myIter(tailNode); // Iterator
				std::cout << "Current list contents (in reverse order): ";

				// Iterates through the list and outputs the contents of each node
				for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetPrevNode())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						// Shows node's value
						std::cout << std::endl << myIter.GetNodeData() << " Prev: ";
						// Shows previous node's value and address
						if (myIter.GetCurrentNode()->GetPrevNode() != nullptr)
						{
							std::cout << myIter.GetCurrentNode()->GetPrevNode()->GetNodeData();
						}
						else
						{
							std::cout << "NULL";
						}
						std::cout << " (" << myIter.GetCurrentNode()->GetPrevNode() << ") Next: ";
						// Shows next node's value and address
						if (myIter.GetCurrentNode()->GetNextNode() != nullptr)
						{
							std::cout << myIter.GetCurrentNode()->GetNextNode()->GetNodeData();
						}
						else
						{
							std::cout << "NULL";
						}
						std::cout << " (" << myIter.GetCurrentNode()->GetNextNode() << ")";

					}
					// Simply shows node's value
					else
					{
						std::cout << myIter.GetNodeData() << " ";
					}
				}
				std::cout << std::endl;
			}
			// Prints the list from head to tail
			else
			{
				nsDLLIterator<T> myIter(headNode); // Iterator
				std::cout << "Current list contents: ";

				// Iterates through the list and outputs the contents of each node
				for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						// Shows node's value
						std::cout << std::endl << myIter.GetNodeData() << " Prev: ";
						// Shows previous node's value and address
						if (myIter.GetCurrentNode()->GetPrevNode() != nullptr)
						{
							std::cout << myIter.GetCurrentNode()->GetPrevNode()->GetNodeData();
						}
						else
						{
							std::cout << "NULL";
						}
						std::cout << " (" << myIter.GetCurrentNode()->GetPrevNode() << ") Next: ";
						// Shows next node's value and address
						if (myIter.GetCurrentNode()->GetNextNode() != nullptr)
						{
							std::cout << myIter.GetCurrentNode()->GetNextNode()->GetNodeData();
						}
						else
						{
							std::cout << "NULL";
						}
						std::cout << " (" << myIter.GetCurrentNode()->GetNextNode() << ")";

					}
					// Simply shows node's value
					else
					{
						std::cout << myIter.GetNodeData() << " ";
					}
				}
				std::cout << std::endl;
			}
		}
		// The list is empty
		else
		{
			// Do nothing
		}
	}
	
	// Finds the minimum value stored in the list
	T Minimum()
	{
		if (!IsEmpty())
		{
			nsDLLIterator<T> myIter(headNode); // Iterator
			// Stores the lowest value and initializes it to the value of the head node
			T minValue = myIter.GetNodeData();

			// Iterates through the list, looking for the lowest value
			for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
			{
				// The current value is lower than the previous minimum
				if (myIter.GetNodeData() < minValue)
				{
					// So it becomes the new low value
					minValue = myIter.GetNodeData();
				}
			}

			// Returns the lowest value
			return minValue;
		}
		else
		{
			return NULL;
		}
	}

	// Finds the maximum value stored in the list
	T Maximum()
	{
		if (!IsEmpty())
		{
			nsDLLIterator<T> myIter(headNode); // Iterator
			// Stores the highest value and initializes it to the value of the head node
			T maxValue = myIter.GetNodeData();

			// Iterates through the list, looking for the highest value
			for (myIter; myIter.GetCurrentNode() != nullptr; myIter.GetNextNode())
			{
				// The current value is higher than the previous minimum
				if (myIter.GetNodeData() > maxValue)
				{
					// So it becomes the new high value
					maxValue = myIter.GetNodeData();
				}
			}

			// Returns the highest value
			return maxValue;
		}
		else
		{
			return NULL;
		}
	}

	// Returns true if the list has no nodes
	bool IsEmpty()
	{
		if (headNode == nullptr && tailNode == nullptr)
		{
			std::cout << "There are no nodes in the list." << std::endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// Gets the number of nodes in the list
	int GetNodeCount()
	{
		return nodeCount;
	}

	// Increases the node count
	void IncreaseNodeCount() 
	{
		nodeCount++;
	}

	// Decreases the node count
	void DecreaseNodeCount()
	{
		nodeCount--;
	}
};

#endif // !nsDblLinkedList_H