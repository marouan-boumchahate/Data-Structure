#include <iostream>

#include "Game.h"
#include "GenericLinkedList.h"
#include "GenericDoublyLinkedList.h"
#include "GenericCircularLinkedList.h"
#include "GenericStack.h"
#include "SwappingTwoLinkedList.h"

using namespace std;

int main() {
    // TEST QUESTION - 1
    
    /*GenericDoublyLinkedList<int> myList;

    myList.InsertAtBeginning(10);
    myList.InsertAtBeginning(20);
    myList.InsertAtBeginning(30);

    myList.InsertAtEnd(40);
    myList.InsertAtEnd(50);

    DNode<int>* targetNode = myList.FindNode(30);
    if (targetNode != nullptr) {
        myList.InsertAfter(targetNode, 35);
    }

    myList.PrintList();

    myList.UpdateItem(2, 25);

    myList.PrintList();

    myList.DeleteFirstNode();

    myList.DeleteLastNode();

    myList.PrintList();

    myList.Reverse();

    myList.PrintList();

    myList.Clear();

    myList.PrintList();*/

    // TEST QUESTION - 2

    /*GenericCircularLinkedList<int> myCircularList;

    myCircularList.add(10);
    myCircularList.add(20);
    myCircularList.add(30);
    myCircularList.add(40);

    cout << "Initial list: ";
    myCircularList.Display();
    cout << endl;

    myCircularList.remove();

    cout << "Updated list after removal: ";
    myCircularList.Display();
    cout << endl;

    cout << "Size of the list: " << myCircularList.Size() << endl;

    myCircularList.add(50);
    myCircularList.add(60);

    cout << "Final list: ";
    myCircularList.Display();
    cout << endl;*/

    // TEST QUESTION - 3

    /*GenericStack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Initial stack: ";
    myStack.Print();
    cout << endl;

    cout << "Size of the stack: " << myStack.Size() << endl;

    cout << "Top element: " << myStack.top() << endl;
    cout << "Bottom element: " << myStack.bottom() << endl;

    myStack.pop();

    cout << "stack after pop\n";
    myStack.Print();
    cout << endl;

    myStack.Reverse();

    cout << "Reversed stack\n";
    myStack.Print();
    cout << endl;

    myStack.UpdateItem(1, 25);

    cout << "stack after item update\n";
    myStack.Print();
    cout << endl;

    myStack.InsertAfter(0, 15);

    cout << "Stack after insertion\n";
    myStack.Print();
    cout << endl;

    myStack.InsertAtFront(5);
    myStack.InsertAtBack(35);

    cout << "Final stack\n";
    myStack.Print();
    cout << endl;

    myStack.Clear();

    cout << "Cleared stack\n";
    myStack.Print();
    cout << endl;*/

    // TEST QUESTION - 4

    /*List<int> myList;

    myList.Add_Back(10);
    myList.Add_Back(20);
    myList.Add_Back(30);
    myList.Add_Back(40);

    cout << "Initial list: ";
    myList.Display();
    cout << endl;

    unsigned short indexX = 1;
    unsigned short indexY = 3;

    Node<int>* nodeX = myList.GetNode(indexX);
    Node<int>* nodeY = myList.GetNode(indexY);

    Swap_Two_Nodes(nodeX, nodeY, myList);

    cout << "List after swapping nodes at indices " << indexX << " and " << indexY << ": ";
    myList.Display();
    cout << endl;

    cout << "Before Swapping --> X: " << nodeX << "   |   " << "Y: " << nodeY << endl;
    cout << "After Swapping -->  X: " << myList.GetNode(indexY) << "   |   " << "Y: " << myList.GetNode(indexX) << endl;

    cout << "\nEVEN AFTER SWAPPING REFERENCES DIDN'T CHANGE" << endl;*/

    // TEST QUESTION - 5

    /*Game game;

    game.add_score(150);
    game.add_score(200);
    game.add_score(180);
    game.add_score(250);
    game.add_score(120);
    game.add_score(300);
    game.add_score(220);
    game.add_score(170);
    game.add_score(190);
    game.add_score(240);
    game.add_score(160);

    List<int> topScores = game.Top_10_Scores();*/

    // TEST QUESTION - 6

    /*GenericDoublyLinkedList<int> list1;
    GenericDoublyLinkedList<int> list2;

    list1.InsertAtEnd(1);
    list1.InsertAtEnd(2);
    list1.InsertAtEnd(3);

    list2.InsertAtEnd(4);
    list2.InsertAtEnd(5);
    list2.InsertAtEnd(6);

    cout << "List 1 ";
    list1.PrintList();
    cout << "List 2 ";
    list2.PrintList();

    GenericDoublyLinkedList<int> concatenatedList = GenericDoublyLinkedList<int>::Concatenate_DLinkedList(list1, list2);

    cout << "Concatenated List ";
    concatenatedList.PrintList();*/

    // TEST QUESTION - 7

    /*List<int> myList;

    myList.Add_Back(1);
    myList.Add_Back(2);
    myList.Add_Back(3);
    myList.Add_Back(4);

    cout << "Original List: ";
    myList.Display();

    Node<int>* penultimateNode = myList.penultimate();

    if (penultimateNode != NULL) 
        cout << "Penultimate Node: " << penultimateNode->data << endl;
    else
        cout << "The list is empty or has only one element." << endl;*/

    // TEST QUESTION - 8

    /*GenericCircularLinkedList<int> myList;

    myList.add(1);
    myList.add(2);
    myList.add(3);

    cout << "Original List: ";
    myList.Display();

    size_t listSize = myList.Size();

    cout << "\nSize of the list: " << listSize << endl;*/

    // TEST QUESTION - 9

    /*GenericStack<string> str_stack;

    str_stack.push("Linked List");
    str_stack.push("Doubly Linked List");
    str_stack.push("Stack");
    str_stack.push("Queue");
    str_stack.push("Tree");
    str_stack.push("Hash Table");
    str_stack.push("Graph");

    str_stack.Print();

    str_stack.Clear();

    cout << "\nAfter Removing all elements\n";
    str_stack.Print();*/

    // TEST QUESTION - 10

    /*List<int> myList;

    myList.Add_Back(10);
    myList.Add_Front(5);
    myList.Add_Back(20);

    cout << "List elements are: ";
    myList.Display();

    myList.Reverse();

    cout << "\nAfter Reversing\nList elements are: ";
    myList.Display();*/
}
