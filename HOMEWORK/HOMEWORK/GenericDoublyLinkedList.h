#pragma once
#include <iostream>

template<typename T>
class DNode
{
	T value;
	DNode* prev;
	DNode* next;

	template<typename T>
	friend class GenericDoublyLinkedList;
};

template<typename T>
class GenericDoublyLinkedList
{
private:
	DNode<T>* head;
	DNode<T>* tail;
	size_t length;

	void swap(DNode<T>*& Current)
	{
		DNode<T>* temp;

		temp = Current->prev;
		Current->prev = Current->next;
		Current->next = temp;

		temp = NULL;
		delete[] temp;
	}

public:
	GenericDoublyLinkedList(DNode<T>* Head = NULL, DNode<T>* Tail = NULL)
	{
		head = Head;
		tail = Tail;
		length = 0;
	}

	size_t Size() const
	{
		return length;
	}

	void InsertAtBeginning(T val)
	{
		DNode<T>* NewNode = new DNode<T>;

		NewNode->value = val;
		NewNode->next = head;
		NewNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = NewNode;
			head = NewNode;
		}
		else
		{
			head = NewNode;
			tail = NewNode;
		}

		length++;
	}

	void InsertAtEnd(T val)
	{
		DNode<T>* NewNode = new DNode<T>;

		NewNode->value = val;
		NewNode->next = NULL;
		NewNode->prev = tail;

		if (tail != NULL)
		{
			tail->next = NewNode;
			tail = NewNode;
		}
		else
		{
			tail = NewNode;
			head = NewNode;
		}

		length++;
	}

	void InsertAfter(DNode<T>*& Target_Node, T val)
	{
		if (head == NULL || Target_Node == NULL)
		{
			return;
		}

		if (Target_Node == tail)
		{
			InsertAtEnd(val);
			return;
		}

		DNode<T>* NewNode = new DNode<T>;
		NewNode->value = val;

		DNode<T>* Current = head;

		while (Current != Target_Node)
		{
			Current = Current->next;
		}

		NewNode->next = Current->next;
		Current->next->prev = NewNode;
		Current->next = NewNode;
		NewNode->prev = Current;

		length++;
	}

	DNode<T>* FindNode(T val) const
	{
		DNode<T>* Current = head;

		while (Current != NULL)
		{
			if (Current->value == val)
				return Current;

			Current = Current->next;
		}

		return NULL;
	}

	void DeleteFirstNode()
	{
		DNode<T>* target = head;
		DeleteNode(target, true);
	}

	void DeleteLastNode()
	{
		DNode<T>* target = tail;
		DeleteNode(target, true);
	}

	void DeleteNode(DNode<T>*& node, bool Sure_Exist = false)
	{
		if (head == NULL || node == NULL)
		{
			return;
		}

		if (head == tail)
		{
			if (head == node)
			{
				head = NULL;
				tail = NULL;

				length--;
			}

			return;
		}

		if (!Sure_Exist) // This to check if I'm sure a 100% that the node I'm looking for exist in the linked list
			// The purpose is to reduce the time complexity
		{
			if (FindNode(node->value) == NULL)
			{
				return;
			}
		}

		DNode<T>* Previous_Node = node->prev;
		DNode<T>* Next_Node = node->next;

		if (Next_Node == NULL)
		{
			Previous_Node->next = Next_Node;
			tail = Previous_Node;
		}
		else if (Previous_Node == NULL)
		{
			Next_Node->prev = Previous_Node;
			head = Next_Node;
		}
		else
		{
			Previous_Node->next = Next_Node;
			Next_Node->prev = Previous_Node;
		}

		node->next = NULL;
		node->prev = NULL;

		delete node;

		length--;
	}

	void PrintList() const
	{
		if (head == NULL)
		{
			std::cout << "List is empty!!" << endl;
			return;
		}

		DNode<T>* Current = head;

		std::cout << "Elements are:  ";

		while (Current != NULL)
		{
			std::cout << Current->value << "    ";
			Current = Current->next;
		}

		std::cout << std::endl;

		delete[] Current;
	}

	bool IsEmpty() const
	{
		return (head == NULL);
	}

	void Clear()
	{
		while (Size() > 0)
			DeleteFirstNode();
	}

	void Reverse()
	{
		DNode<T>* Current = head;

		while (Current != NULL)
		{
			swap(Current);
			Current = Current->prev;
		}

		DNode<T>* temp;

		temp = head;
		head = tail;
		tail = temp;

		temp = NULL;
		delete[] temp;
	}

	DNode<T>* GetNode(unsigned short index) const
	{
		if (head == nullptr)
		{
			return NULL;
		}

		if (index >= Size())
		{
			return NULL;
		}

		DNode<T>* Current = head;
		unsigned short counter = 0;

		while ((Current != nullptr) && (counter != index))
		{
			Current = Current->next;
			counter++;
		}

		return Current;
	}

	T GetItem(unsigned short index) const
	{
		DNode<T>* N = GetNode(index);

		if (N != NULL)
			return N->value;

		return NULL;
	}

	bool UpdateItem(unsigned short index, T new_value)
	{
		DNode<T>* N = GetNode(index);

		if (N != NULL)
		{
			N->value = new_value;
			return true;
		}

		return false;
	}

	bool InsertAfter(unsigned short index, T val)
	{
		DNode<T>* N = GetNode(index);

		if (N != NULL)
		{
			InsertAfter(N, val);
			return true;
		}

		return false;

	}

	template<typename T>
	static GenericDoublyLinkedList<T> Concatenate_DLinkedList(GenericDoublyLinkedList<T> L, GenericDoublyLinkedList<T> M)
	{
		if (L.IsEmpty() && M.IsEmpty())
			return L;

		if (L.IsEmpty())
			return M;

		if (M.IsEmpty())
			return L;

		L.tail->next = M.head;
		M.head->prev = L.tail;

		GenericDoublyLinkedList<T> LM(L.head, M.tail);

		return LM;
	}
};