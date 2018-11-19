#ifndef nsDLLIterator_H
#define nsDLLIterator_H

#include "DblLLNode.h"

template<class Type> class DblLLIterator
{
private:
	DblLLNode<Type>* currentNode;
public:
	DblLLIterator(DblLLNode<Type>* startNode = nullptr) :
		currentNode(startNode) { } // Default constructor
	
	~DblLLIterator() {} // Default destructor	

	// Returns the current node
	DblLLNode<Type>* GetCurrentNode() 
	{
		return currentNode;
	}

	// Returns the data stored in the current node
	Type GetNodeData() 
	{
		return currentNode->GetNodeData(); 
	}

	// Iterates back to the previous node (if there is one)
	DblLLNode<Type>* GetPrevNode() 
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
	DblLLNode<Type>* GetNextNode() 
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

