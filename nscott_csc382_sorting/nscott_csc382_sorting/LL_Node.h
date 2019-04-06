#ifndef LLNODE_H
#define LLNODE_H

#include <iostream>

template <typename T> class LL_Node
{
private:
	T nodeData = NULL; // The data being held by the this node
	LL_Node<T>* prevNode = nullptr; // A pointer to the previous node in the linked list
	LL_Node<T>* nextNode = nullptr; // A pointer to the next node in the linked list
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	LL_Node() { }

	/// <summary>
	/// Default destructor.

	/// </summary>
	~LL_Node() { }

	/// <summary>
	/// Returns the key value stored in this node.
	/// </summary>
	/// <returns>The key value stored in this node.</returns>
	T GetNodeData()
	{
		return nodeData;
	}

	/// <summary>
	/// Changes the key value to be stored in this node.
	/// </summary>
	/// <param name="dataToStore">The key value to store in this node.</param>
	void SetNodeData(T dataToStore)
	{
		nodeData = dataToStore;
	}

	/// <summary>
	/// Returns a pointer to the node immediately preceding this node in the linked list.
	/// </summary>
	/// <returns>A pointer to the node immediately preceding this node in the linked 
	/// list.</returns>
	LL_Node<T>* GetPrevNode()
	{
		return prevNode;
	}

	/// <summary>
	/// Changes the pointer to the node immediately preceding this node in the linked list.
	/// </summary>
	/// <param name="nodePtr">A pointer to the node that will be designated as immediately 
	/// preceding the current node in the linked list.</param>
	void SetPrevNode(LL_Node<T>* nodePtr)
	{
		prevNode = nodePtr;
	}

	/// <summary>
	/// Sets the pointer to the node immediately preceding this node in the linked list to 
	/// nullptr.
	/// </summary>
	void ClearPrevNode()
	{
		prevNode = nullptr;
	}

	/// <summary>
	/// Returns a pointer to the node immediately following this node in the linked list.
	/// </summary>
	/// <param name="newValue"></param>
	/// <returns>A pointer to the node immediately following this node in the linked 
	/// list.</returns>
	LL_Node<T>* GetNextNode()
	{
		return nextNode;
	}

	/// <summary>
	/// Changes the pointer to the node immediately following this node in the linked list.
	/// </summary>
	/// <param name="newValue">A pointer to the node that will be designated as immediately 
	/// following the current node in the linked list.</param>
	void SetNextNode(LL_Node<T>* nodePtr)
	{
		nextNode = nodePtr;
	}

	/// <summary>
	/// Sets the pointer to the node immediately following this node in the linked list to 
	/// nullptr.
	/// </summary>
	void ClearNextNode()
	{
		nextNode = nullptr;
	}
};
#endif // !LLNODE_H