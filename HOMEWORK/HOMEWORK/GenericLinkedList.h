#pragma once

#include <iostream>

using namespace std;

// Template class to represent a Node in a linked list
template <typename T>
class Node
{
public:
    T data;      // Data stored in the node
    Node* next;  // Pointer to the next node
};

// Template class to represent a singly linked list
template <typename T>
class List
{
private:
    Node<T>* head;          // Pointer to the first node in the list
    unsigned int size;      // Number of nodes in the list

    void sort_items(Node<T>* current, List<T>& SL)
    {
        if (SL.isEmpty())
            SL.Add_Back(current->data);
        else if (current->data >= SL.Back())
            SL.Add_Back(current->data);
        else if (current->data <= SL.Front())
            SL.Add_Front(current->data);
        else
        {
            Node<T>* n = SL.head;

            while (n->next != NULL)
            {
                if ((n->data <= current->data) && (n->next->data >= current->data))
                {
                    Node<T>* new_node = new Node<T>;
                    new_node->data = current->data;

                    SL.InsertAfter(n, new_node);
                    return;
                }

                n = n->next;
            }

            SL.Add_Back(current->data);
        }
    }

public:
    // Constructor to initialize an empty list
    List() : head(NULL), size(0) {}

    // Check if the list is empty
    bool isEmpty() const
    {
        return (size == 0);
    }

    // Return The head Node
    Node<T>* GetHead()
    {
        return head;
    }

    // Change the head pointer
    void Update_Head(Node<T>* new_head)
    {
        head = new_head;
    }

    // Get the current size of the list
    const unsigned int& List_Size() const
    {
        return size;
    }

    // Add a new node with data to the front of the list
    void Add_Front(const T& data, Node<T>* NewNode = new Node<T>)
    {
        NewNode->data = data;  // Store data in the new node
        NewNode->next = NULL;  // Set the next pointer of the new node

        if (isEmpty())
        {
            head = NewNode;  // If the list is empty, the new node becomes the head
        }
        else
        {
            NewNode->next = head;  // Update the new node's next pointer
            head = NewNode;       // Update the head to point to the new node
        }

        size++;  // Increase the size of the list
    }

    // Add a new node with data to the back of the list
    void Add_Back(const T& data, Node<T>* New_Node = new Node<T>)
    {
        New_Node->data = data;  // Store data in the new node
        New_Node->next = NULL;  // Set the next pointer of the new node

        if (isEmpty())
        {
            head = New_Node;  // If the list is empty, the new node becomes the head
        }
        else
        {
            Node<T>* Current = head;

            while (Current->next != NULL)
                Current = Current->next;

            Current->next = New_Node;  // Insert the new node at the end of the list
        }

        size++;  // Increase the size of the list
    }

    // Delete the node at the front of the list
    void Delete_Front()
    {
        if (isEmpty())
            cout << "The list is empty!!!" << endl;
        else
        {
            Node<T>* current = head;  // Assign the head to a new node

            head = current->next;  // Replace the head with the next node

            delete current;  // Delete the original head node

            size--;  // Decrease the size of the list
        }
    }

    // Delete the node at the back of the list
    void Delete_Back()
    {
        if (isEmpty())
            cout << "The list is empty!!!" << endl;
        else
        {
            Node<T>* Current = head;  // Assign the head to a new node
            Node<T>* Prev = head;

            while (Current->next != NULL)
            {
                Prev = Current;
                Current = Current->next;
            }

            Prev->next = Current->next;  // Remove the last node from the list
            delete Current;

            size--;  // Decrease the size of the list
        }
    }

    // Display the elements in the list
    void Display()
    {
        if (head == NULL)
        {
            cout << "List is empty!!" << endl;
            return;
        }

        Node<T>* Current = head;

        while (Current->next != NULL)
        {
            cout << Current->data << "  ";
            Current = Current->next;
        }

        cout << Current->data << endl;
    }

    // Get the data of the front node
    const T& Front() const
    {
        return head->data;
    }

    // Get the data of the back node
    const T& Back() const
    {
        Node<T>* Current = head;

        while (Current->next != NULL)
        {
            Current = Current->next;
        }

        return Current->data;
    }

    // Search for a node with a specific value
    bool Find(const T& val) const
    {
        Node<T>* Current = head;

        while (Current->next != NULL)
        {
            if (Current->data == val)
                return 1;  // Return the node if the value matches

            Current = Current->next;
        }

        return 0;  // Return NULL if the value is not found in the list
    }

    // Clear List
    void destroyList()
    {
        while (!isEmpty())
            Delete_Back();
    }

    // Get Item by using index
    Node<T>* GetNode(unsigned short index) const
    {
        if ((head == nullptr) || (index >= List_Size()))
        {
            cout << "index NOT FOUND" << endl;
            return NULL;
        }

        Node<T>* Current = head;
        unsigned short counter = 0;

        while ((Current != nullptr) && (counter != index))
        {
            Current = Current->next;
            counter++;
        }

        return Current;
    }

    // Insert after a node
    void InsertAfter(Node<T>*& Target_Node, Node<T>*& New_Node)
    {
        if (head == NULL || Target_Node == NULL)
        {
            return;
        }

        if (Target_Node->next == NULL)
        {
            Add_Back(New_Node->data, New_Node);
            return;
        }

        New_Node->next = Target_Node->next;
        Target_Node->next = New_Node;

        size++;
    }

    // Sort items in increasing way
    void Sorting_List()
    {
        Node<T>* current = head;
        List<T> sorted_list;

        while (current != NULL)
        {
            sort_items(current, sorted_list);
            current = current->next;
        }

        *this = sorted_list;
    }

    // Find the previous of the last node
    Node<T>* penultimate()
    {
        if (isEmpty() || List_Size() == 1)
        {
            cout << "No penultimate for this list!!" << endl;
            return NULL;
        }

        Node<T>* prev = head;
        Node<T>* current = head;

        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        return prev;
    }

    // Reverse a list
    void Reverse()
    {
        List<T> new_list = *this;
        List<T> Reversed_Version;

        while (!new_list.isEmpty())
        {
            Reversed_Version.Add_Front(new_list.Front());
            new_list.Delete_Front();
        }

        *this = Reversed_Version;
    }
};


