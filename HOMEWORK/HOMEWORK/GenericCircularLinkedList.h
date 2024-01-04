#pragma once

#include <iostream>

using namespace std;

template<typename T>

class CNode
{
private:
	T elem;
	CNode* next;

	template<typename T>
	friend class GenericCircularLinkedList;
};

template<typename T>

class GenericCircularLinkedList
{
private:
	CNode<T>* cursor;
	size_t size;

public:
	GenericCircularLinkedList() : cursor(nullptr), size(0) {}

	~GenericCircularLinkedList()
	{
		while (!empty())
			remove();
	}

	bool empty() const
	{
		return cursor == NULL;
	}

	const T& front() const
	{
		return cursor->elem;
	}

	const T& back() const
	{
		return cursor->next->elem;
	}

	void advance()
	{
		cursor = cursor->next;
	}

	void add(const T& e)
	{
		CNode<T>* v = new CNode<T>;

		v->elem = e;

		if (cursor == NULL) 
		{
			v->next = v;
			cursor = v;
		}
		else 
		{
			v->next = cursor->next;
			cursor->next = v;
		}

		size++;

	}

	void remove()
	{
		if (empty())
			return;

		CNode<T>* old = cursor->next;

		if (old == cursor)
			cursor = NULL;
		else
			cursor->next = old->next;

		delete old;
		size--;
	}

	size_t Size()
	{
		return size;
	}

	void Display()
	{
		if (empty())
		{
			cout << "The list is empty!!!" << endl;
			return;
		}

		CNode<T>* fisrt = cursor;

		do
		{
			cout << front() << "   ";

			advance();

		} while (fisrt != cursor);
	}
};


