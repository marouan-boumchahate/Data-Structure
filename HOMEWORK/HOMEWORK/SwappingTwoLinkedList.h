#pragma once

#include "GenericLinkedList.h"

template<typename T>

void Swap_Two_Nodes(Node<T>*& x, Node<T>*& y, List<T>& L)
{
	if (x == y)
		return;

	if (x == NULL || y == NULL)
		return;

	Node<T>* current = L.GetHead();
	Node<T>* prev = NULL;

	Node<T>* x_prev = new Node<T>;
	Node<T>* y_prev = new Node<T>;

	Node<T>* x_next = new Node<T>;
	Node<T>* y_next = new Node<T>;

	// These two booleans will help us to ignore the rest nodes if we already find what we need
	// which sometimes maybe we are looking only for the two first nodes which is O(2)
	bool xprev_filled = false;
	bool yprev_filled = false;

	// Finding the prev and next nodes for each node (x and y)
	while (current != NULL)
	{
		if (current == x)
		{
			x_prev = prev;
			x_next = current->next;
			xprev_filled = true;
		}
		else if (current == y)
		{
			y_prev = prev;
			y_next = current->next;
			yprev_filled = true;
		}

		if (xprev_filled && yprev_filled)
			break;

		prev = current;
		current = current->next;
	}

	// if two nodes are next to each other but x before y
	if (x_next == y)
	{
		y->next = x;
		x->next = y_next;

		if (x_prev == NULL)
			L.Update_Head(y);
		else
			x_prev->next = y;

		return;
	} 

	// if two nodes are next to each other but y before x
	if (y_next == x)
	{
		x->next = y;
		y->next = x_next;

		if (y_prev == NULL)
			L.Update_Head(x);
		else
			y_prev->next = x;

		return;
	}

	// if the prev is NULL
	if (x_prev == NULL)
	{
		x->next = y_next;
		y->next = x_next;
		y_prev->next = x;

		L.Update_Head(y);
		return;
	}

	// other cases
	x_prev->next = y;
	y->next = x_next;

	y_prev->next = x;
	x->next = y_next;
}