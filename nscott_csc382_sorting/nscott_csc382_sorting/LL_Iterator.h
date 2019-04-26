#ifndef LL_ITERATOR_H
#define LL_ITERATOR_H

#include "LL_Node.h"

template<class T> class LL_Iterator
{
private:
	LL_Node<T>* currentNode;
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	/// <param name="startNode">The node at which this iterator should point to upon 
	/// creation.</param>
	LL_Iterator(LL_Node<T>* startNode = nullptr) : currentNode(startNode) { }

	/// <summary>
	/// Default destructor.
	/// </summary>
	~LL_Iterator() { }

	/// <summary>
	/// Sets the node this iterator is pointing to.
	/// </summary>
	/// <param name="targetNode">The node at which this iterator should point to upon 
	/// creation.</param>
	void SetCurrentNode(LL_Node<T>* targetNode)
	{
		currentNode = targetNode;
	}

	/// <summary>
	/// Returns a pointer to the current node the iterator is referencing.
	/// </summary>
	/// <returns>A pointer to the current node the iterator is referencing</returns>
	// 
	LL_Node<T>* GetCurrentNode() 
	{
		return currentNode;
	}

	/// <summary>
	/// Returns the key value stored in the current node the iterator is referencing.
	/// </summary>
	/// <param name="newValue"></param>
	/// <returns>The key value stored in the current node the iterator is referencing.</returns>
	T GetNodeData() 
	{
		return currentNode->GetNodeData(); 
	}

	/// <summary>
	/// Returns the next node in the linked list without moving the iterator forward.
	/// </summary>
	LL_Node<T>* GetNextNode()
	{
		return currentNode->GetNextNode();
	}

	/// <summary>
	/// Returns the previous node in the linked list without moving the iterator backward.
	/// </summary>
	LL_Node<T>* GetPrevNode()
	{
		return currentNode->GetPrevNode();
	}

	/// <summary>
	/// Attempts to move to the previous node in the linked list.
	/// </summary>
	LL_Node<T>* IterateBack() 
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

	/// <summary>
	/// Attempts to move to the next node in the linked list.
	/// </summary>
	LL_Node<T>* IterateFwd() 
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

#endif // !LL_ITERATOR_H

