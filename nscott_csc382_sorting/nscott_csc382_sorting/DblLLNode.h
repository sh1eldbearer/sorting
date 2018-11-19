#ifndef nsNode_H
#define nsNode_H

#include <iostream>

// TODO: Test MyNode class

template <typename Type> class DblLLNode
{
private:
	Type nodeData = NULL; // The data being held by the this node
	DblLLNode<Type>* prevNode = nullptr; // A pointer to the previous node in the linked list
	DblLLNode<Type>* nextNode = nullptr; // A pointer to the next node in the linked list
public:
	DblLLNode() {} // Default constructor
	~DblLLNode() {} // Default destructor

	Type GetNodeData() // Getter for the node's stored data
	{
		return nodeData;
	}

	// Seteter for the node's stored data
	template <typename Type> void SetNodeData(Type dataToStore)
	{
		nodeData = dataToStore;
	}

	// Getter for the previous node in the linked list
	DblLLNode<Type>* GetPrevNode()
	{
		return prevNode;
	}

	// Setter for the previous node in the linked list
	template <typename Type> void SetPrevNode(DblLLNode<Type>* nodePtr)
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
	template <typename Type> void SetNextNode(DblLLNode<Type>* nodePtr)
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