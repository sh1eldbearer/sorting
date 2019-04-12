#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "LL_Iterator.h"
#include "LL_Node.h"

template <typename T> class LinkedList
{
private:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="newValue"></param>
	/// <returns></returns>
	int nodeCount = 0; // Stores a count of the number of nodes in the list
	LL_Node<T>* headNode = nullptr; // Stores a pointer to the first node in the list
	LL_Node<T>* tailNode = nullptr; // Stores a pointer to the last node in the list

	/// <summary>
	/// Decreases the count of the number of nodes stored in the linked list.
	/// </summary>
	void DecreaseNodeCount()
	{
		nodeCount--;
	}

	/// <summary>
	/// Increases the count of the number of nodes stored in the linked list.
	/// </summary>
	void IncreaseNodeCount()
	{
		nodeCount++;
	}

	/// <summary>
	/// Outputs the key values and addresses of the current node and its adjacent nodes.
	/// </summary>
	/// <param name="targetNode">A pointer to the node object that will have its details printed to the console.</param>
	void PrintDetails(LL_Node<T>* targetNode)
	{
		// Shows node's value
		std::cout << std::endl << targetNode->GetNodeData() << " Prev: ";
		// Shows previous node's value and address
		if (targetNode->GetPrevNode() != nullptr)
		{
			std::cout << targetNode->GetPrevNode()->GetNodeData();
		}
		else
		{
			std::cout << "NULL";
		}
		std::cout << " (" << targetNode->GetPrevNode() << ") Next: ";
		// Shows next node's value and address
		if (targetNode->GetNextNode() != nullptr)
		{
			std::cout << targetNode->GetNextNode()->GetNodeData();
		}
		else
		{
			std::cout << "NULL";
		}
		std::cout << " (" << targetNode->GetNextNode() << ")";
	}
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	LinkedList() { } 

	/// <summary>
	/// Default destructor.
	/// </summary>
	~LinkedList() { }

	/// <summary>
	/// Gets the head node of this linked list.
	/// </summary>
	/// <returns>The pointer to the head node of this linked list.</returns>
	LL_Node<T>* GetHeadNode()
	{
		return headNode;
	}

	/// <summary>
	/// Gets the tail node of this linked list.
	/// </summary>
	/// <returns>The pointer to the tail node of this linked list.</returns>
	LL_Node<T>* GetTailNode()
	{
		return tailNode;
	}

	/// <summary>
	/// Creates a new node, and inserts it at the end the linked list.
	/// </summary>
	/// <param name="newData">The key value to look for in the linked list.</param>
	/// <param name="verbose">Whether or not to output status messages to the console.</param>
	void Insert(T newData, bool verbose = true)
	{
		// Creates a new node
		LL_Node<T>* newNode = new LL_Node<T>();

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
		if (verbose)
		{
			std::cout << "Successfully stored " << newNode->GetNodeData()
				<< " as node " << (GetNodeCount() - 1);
			std::cout << std::endl;
		}
	}

	/// <summary>
	/// Finds the first instance of a key value in the linked list.
	/// </summary>
	/// <param name="dataToFind">The key value to look for in the linked list.</param>
	/// <param name="verbose">Whether or not to output status messages to the console.</param>
	/// <returns>A pointer to the node containing the key value. If no match is found, returns 
	/// nullptr.</returns>
	LL_Node<T>* Find(T dataToFind, bool verbose = true)
	{
		LL_Iterator<T> listIterator(headNode); // Iterator

		// Loops through the list until a matching value is found
		for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
		{
			if (listIterator.GetNodeData() == dataToFind)
			{
				if (!verbose)
				{
					std::cout << "Value " << dataToFind << " found at " << 
						listIterator.GetCurrentNode() << std::endl;
				}
				return listIterator.GetCurrentNode();
			}
		}
		// If no value is found, returns a nullptr
		if (!verbose)
		{
			std::cout << "Value " << dataToFind << " not found in list." << std::endl;
		}
		return nullptr;
	}

	/// <summary>
	/// Deletes a node from the linked list.
	/// </summary>
	/// <param name="newValue">The key value to look for in the linked list. If this value is 
	/// found in a node, that node will be deleted.</param>
	void Delete(T dataToFind)
	{
		LL_Node<T>* delNode = Find(dataToFind, true);

		// Stops the function if a nullptr is passed in
		if (delNode == nullptr)
		{
			std::cout << "Value " << dataToFind << " not found in list." << std::endl;
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

	/// <summary>
	/// Outputs the key values of each node to the console.
	/// </summary>
	/// <param name="reverse">Determines the order in which to print the list. false prints 
	/// from head to tail; true prints from tail to head (reverse).</param>
	/// <param name="detailed">Detailed mode will display each node’s value, as well as the 
	/// value and address of the current node’s adjacent nodes, if desired. true prints the 
	/// extra data; false only prints the key values.</param>
	void PrintList(bool reverse = false, bool detailed = true)
	{
		// As long as there is at least one node in the list, prints the list
		if (!IsEmpty())
		{
			// Prints the list from tail to head 
			if (reverse)
			{
				LL_Iterator<T> listIterator(tailNode); // Iterator
				std::cout << "Current list contents (in reverse order): ";

				// Iterates through the list and outputs the contents of each node
				for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateBack())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						PrintDetails(listIterator.GetCurrentNode());
					}
					// Simply shows node's value
					else
					{
						std::cout << listIterator.GetNodeData() << " ";
					}
				}
				std::cout << std::endl;
			}
			// Prints the list from head to tail
			else
			{
				LL_Iterator<T> listIterator(headNode); // Iterator
				std::cout << "Current list contents: ";

				// Iterates through the list and outputs the contents of each node
				for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						PrintDetails(listIterator.GetCurrentNode());
					}
					// Simply shows node's value
					else
					{
						std::cout << listIterator.GetNodeData() << " ";
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

	/// <summary>
	/// Finds and returns the smallest value stored in the nodes contained in 
	/// the linked list.
	/// </summary>
	/// <returns>Returns the smallest value stored in the nodes contained in 
	/// the linked list.</returns>
	T Minimum()
	{
		if (!IsEmpty())
		{
			LL_Iterator<T> listIterator(headNode); // Iterator
			// Stores the lowest value and initializes it to the value of the head node
			T minValue = listIterator.GetNodeData();

			// Iterates through the list, looking for the lowest value
			for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
			{
				// The current value is lower than the previous minimum
				if (listIterator.GetNodeData() < minValue)
				{
					// So it becomes the new low value
					minValue = listIterator.GetNodeData();
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

	/// <summary>
	/// Finds and returns the largest value stored in the nodes contained in 
	/// the linked list
	/// </summary>
	/// <returns>The largest value stored in the nodes contained in the linked 
	/// list.</returns>
	T Maximum()
	{
		if (!IsEmpty())
		{
			LL_Iterator<T> listIterator(headNode); // Iterator
			// Stores the highest value and initializes it to the value of the head node
			T maxValue = listIterator.GetNodeData();

			// Iterates through the list, looking for the highest value
			for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
			{
				// The current value is higher than the previous minimum
				if (listIterator.GetNodeData() > maxValue)
				{
					// So it becomes the new high value
					maxValue = listIterator.GetNodeData();
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

	/// <summary>
	/// Swaps two key values between two different nodes.
	/// </summary>
	/// <param name="node1">A node that will be switching key values with node2.</param>
	/// <param name="node2">A node that will be switching key values with node1.</param>
	/// <param name="verbose">Whether or not to output status messages to the console.</param>
	void SwapValues(LL_Node<T>* node1, LL_Node<T>* node2, bool verbose = true)
	{
		if (node1 == node2)
		{
			if (verbose)
			{
				std::cout << "Cannot switch values between the same node.\n\n";
			}
			return;
		}
		else if (node1 == nullptr || node2 == nullptr)
		{
			if (verbose)
			{
				std::cout << "Cannot switch the value of a null pointer.\n\n";
			}
			return;
		}

		// Swaps the values in place
		node1->SetNodeData(node1->GetNodeData() + node2->GetNodeData());
		node2->SetNodeData(node1->GetNodeData() - node2->GetNodeData());
		node1->SetNodeData(node1->GetNodeData() - node2->GetNodeData());
	}

	/// <summary>
	/// Determines if the linked list is empty.
	/// </summary>
	/// <returns>True if empty, returns false if not.</returns>
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

	/// <summary>
	/// Returns the current count of the number of nodes in the linked list.
	/// </summary>
	/// <returns>The current count of the number of nodes in the linked list.</returns>
	int GetNodeCount()
	{
		return nodeCount;
	}

	/// <summary>
	/// Gets the index position of a node in the linked list.
	/// </summary>
	/// <param name="nodeToFind">The node to look for in the linked list.</param>
	/// <returns>The index position of the node. Returns -1 if the node is not found.</returns>
	int IndexOf(LL_Node<T>* nodeToFind)
	{
		LL_Iterator<T> myIter(headNode);
		int index = 0;

		for (myIter; myIter.GetCurrentNode() != nullptr; myIter.IterateFwd())
		{
			if (myIter.GetCurrentNode() == nodeToFind)
			{
				return index;
			}
			else
			{
				index++;
			}
		}

		// If the node isn't found in the list, return a negative value as a failure signal
		return -1;
	}

	/// <summary>
	/// Find a node by its index position
	/// </summary>
	/// <param name="index">The index of the node to be found.</param>
	/// <returns>The node found at the given index. Returns nullptr if no node exists at that position.</return>
	LL_Node<T>* FindByIndex(int index)
	{
		LL_Iterator<T> myIter(headNode);
		int loopCount = 0;
		for (index; loopCount < index; myIter.IterateFwd())
		{
			loopCount++;
		}
		return myIter.GetCurrentNode();
	}
};

#endif // !LINKEDLIST_H