#ifndef nsNode_H
#define nsNode_H

#include <iostream>

// TODO: Test MyNode class

template <typename T> class DblLLNode
{
private:
	T nodeData = NULL; // The data being held by the this node
	DblLLNode<T>* prevNode = nullptr; // A pointer to the previous node in the linked list
	DblLLNode<T>* nextNode = nullptr; // A pointer to the next node in the linked list
public:
	DblLLNode() {} // Default constructor
	~DblLLNode() {} // Default destructor

	T GetNodeData() // Getter for the node's stored data
	{
		return nodeData;
	}

	// Seteter for the node's stored data
	template <typename T> void SetNodeData(T dataToStore)
	{
		nodeData = dataToStore;
	}

	// Getter for the previous node in the linked list
	DblLLNode<T>* GetPrevNode()
	{
		return prevNode;
	}

	// Setter for the previous node in the linked list
	template <typename T> void SetPrevNode(DblLLNode<T>* nodePtr)
	{
		prevNode = nodePtr;
	}

	// Sets the previous node to null
	void ClearPrevNode()
	{
		prevNode = nullptr;
	}

	// Getter for the next node in the linked list
	DblLLNode<T>* GetNextNode()
	{
		return nextNode;
	}

	// Setter for the previous node in the linked list
	template <typename T> void SetNextNode(DblLLNode<T>* nodePtr)
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