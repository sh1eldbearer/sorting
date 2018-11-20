#ifndef nsNode_H
#define nsNode_H

#include <iostream>

// TODO: Test MyNode class

template <typename Type> class DblLLNode
{
private:
	Type nodeValue = NULL; // The data being held by the this node
	DblLLNode<Type>* prevNode = nullptr; // A pointer to the previous node in the linked list
	DblLLNode<Type>* nextNode = nullptr; // A pointer to the next node in the linked list
public:
	DblLLNode() {} // Default constructor
	~DblLLNode() {} // Default destructor

	Type GetNodeValue() // Getter for the node's stored data
	{
		return nodeValue;
	}

	// Seteter for the node's stored data
	void SetNodeValue(Type valueToStore)
	{
		nodeValue = valueToStore;
	}

	// Getter for the previous node in the linked list
	DblLLNode<Type>* GetPrevNode()
	{
		return prevNode;
	}

	// Setter for the previous node in the linked list
	void SetPrevNode(DblLLNode<Type>* nodePtr)
	{
		prevNode = nodePtr;
	}

	// Sets the previous node to null
	void ClearPrevNode()
	{
		prevNode = nullptr;
	}

	// Getter for the next node in the linked list
	DblLLNode<Type>* GetNextNode()
	{
		return nextNode;
	}

	// Setter for the previous node in the linked list
	void SetNextNode(DblLLNode<Type>* nodePtr)
	{
		nextNode = nodePtr;
	}

	// Sets the next node to null
	void ClearNextNode()
	{
		nextNode = nullptr;
	}
};
#endif // !nsNode_H