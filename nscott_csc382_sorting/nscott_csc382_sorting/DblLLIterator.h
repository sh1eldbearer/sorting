#ifndef nsDLLIterator_H
#define nsDLLIterator_H

#include "DblLLNode.h"

template<class T> class DblLLIterator
{
private:
	DblLLNode<T>* currentNode;
public:
	DblLLIterator(DblLLNode<T>* startNode = nullptr) :
		currentNode(startNode) { } // Default constructor
	
	~DblLLIterator() {} // Default destructor	

	// Returns the current node
	DblLLNode<T>* GetCurrentNode() 
	{
		return currentNode;
	}

	// Returns the data stored in the current node
	T GetNodeData() 
	{
		return currentNode->GetNodeData(); 
	}

	// Iterates back to the previous node (if there is one)
	DblLLNode<T>* GetPrevNode() 
	{
		// Returns a null value if there is no previous node (current node is the head)
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// Otherwise, iterates back to the previous node and returns it
		else
		{
			currentNode = currentNode->GetPrevNode();
			return currentNode;
		}
	}

	// Iterates forward to the next node (if there is one)
	DblLLNode<T>* GetNextNode() 
	{
		// Returns a null value if there is no next node (current node is the tail)
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// Otherwise, iterates forward to the next node and returns it
		else
		{
			currentNode = currentNode->GetNextNode();
			return currentNode;
		}
	}
};

#endif // !nsDLLIterator_H

