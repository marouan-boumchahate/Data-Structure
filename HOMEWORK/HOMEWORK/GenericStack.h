#pragma once

#include <iostream>
#include "GenericDoublyLinkedList.h"

template<typename T>

class GenericStack
{
protected:
	GenericDoublyLinkedList<T> Stack;

public:
	// add element to the last
	void push(T value)
	{
		Stack.InsertAtEnd(value);
	}

	// print all items
	void Print()
	{
		Stack.PrintList();
	}

	// returning the size of the stack
	unsigned short Size()
	{
		return Stack.Size();
	}

	// return the top item which is the back in this case
	T top()
	{
		return Stack.GetItem(Stack.Size() - 1);
	}

	// return the bottom item which is the front in this case
	T bottom()
	{
		return Stack.GetItem(0);
	}

	// delete the last item
	void pop()
	{
		Stack.DeleteLastNode();
	}

	// returning true if the stack has no item
	bool IsEmpty()
	{
		return Stack.IsEmpty();
	}

	// returning the reverse items of a stack
	void Reverse()
	{
		Stack.Reverse();
	}

	// update an item by a new one for a specific index
	bool UpdateItem(unsigned short index, T new_value)
	{
		return Stack.UpdateItem(index, new_value);
	}

	// add an item after an index
	void InsertAfter(unsigned short index, T value)
	{
		Stack.InsertAfter(index, value);
	}

	// add an item at the beginning
	void InsertAtFront(T value)
	{
		Stack.InsertAtBeginning(value);
	}

	// add an item at the end
	void InsertAtBack(T value)
	{
		Stack.InsertAtEnd(value);
	}

	// empty the stck
	void Clear()
	{
		if(!IsEmpty())
		{
			pop();
			Clear();
		}
	}

	// Get item by index
	T GetItem(unsigned short index)
	{
		return Stack.GetItem(index);
	}
};

