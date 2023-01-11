#include <iostream>
#include <limits>
#include "List.h"

List::List()
{
	head = new Node(std::numeric_limits<int>::max());
    noOfNodes = 0;
}

List::~List()
{

}

void List::addNodeEnd(int myValue)
{
    Node* newNode = new Node(myValue);
    noOfNodes++;

    if (head->next == nullptr)
    {
        head->next = newNode;
        return;
    }

    Node* iterator = head;

    while (iterator->next != nullptr)
        iterator = iterator->next;

    iterator->next = newNode;
}

void List::addNodeBeginning(int myValue)
{
    Node* newNode = new Node(myValue);
    noOfNodes++;

    newNode->next = head->next;
    head->next = newNode;
}

void List::addNodeAtPosition(int myValue, int position)
{
    if (position == 0)
    {
        addNodeBeginning(myValue);
        return;
    }

    if (position == noOfNodes)
    {
        addNodeEnd(myValue);
        return;
    }

    if (position > noOfNodes)
    {
        std::cout << "Position not found!\n";
        return;
    }

    Node* newNode = new Node(myValue);
    noOfNodes++;

    Node* iterator = head;
    int intIterator = 0;

    while (iterator->next != nullptr)
    {
        if (intIterator == position)
        {
            newNode->next = iterator->next;
            iterator->next = newNode;
            break;
        }

        iterator = iterator->next;
        intIterator++;
    }

}

void List::deleteNodeValue(int myValue)
{
    bool done = false;
    bool now = false;
    Node* iterator = head;

    while (iterator->next != nullptr)
    {
        if (myValue == iterator->next->value)
        {
            iterator->next = iterator->next->next;
            noOfNodes--;
            now = true;
            done = true;
        }
        if (now == false)
            iterator = iterator->next;
        else
            now = false;
    }

    if (done == false)
        std::cout << "Value not found!\n";
}

void List::deleteNodeAtPosition(int position)
{
    if (position > noOfNodes)
    {
        std::cout << "Position not found!\n";
        return;
    }

    Node* iterator = head;
    int intIterator = 0;

    while (iterator->next != nullptr)
    {
        if (intIterator == position)
        {
            iterator->next = iterator->next->next;
            noOfNodes--;
            break;
        }

        iterator = iterator->next;
        intIterator++;
    }
}

void List::deleteLessThan(int myValue)
{
    Node* iterator = head;

    bool done = false;

    while (iterator->next != nullptr)
    {
        if (iterator->next->value < myValue)
        {
            iterator->next = iterator->next->next;
            done = true;
            noOfNodes--;
        }
       
        if (iterator->next == nullptr)
            break;
        
        if (done == false)
            iterator = iterator->next;
        else
            done = false;
    }

}

void List::averageOfElements()
{
    if (noOfNodes == 0)
    {
        std::cout << "No elements in list! Couldn't compute the average!\n";
        return;
    }

    double average = 0;
    
    Node* iterator = head;

    while (iterator->next != nullptr)
    {
        average += iterator->next->value;
        iterator = iterator->next;
    }

    average = average / noOfNodes;

    std::cout << "The average of list elements is: " << average << "\n";
}

void List::printList()
{
    Node* iterator = head;

    std::cout << "List elements: ";

    while (iterator->next != nullptr)
    {
        std::cout << iterator->next->value << " ";
        iterator = iterator->next;
    }
    
    std::cout << "\n";
}

void List::menu()
{
        int opt = 0;

        while (opt != 9)
        {
            options();
            std::cin >> opt;

            switch (opt)
            {
            case 1:
                system("cls");
                std::cout << "Add a node at the end of the list" << "\n";
                addNodeEnd(getValue());
                break;
            case 2:
                system("cls");
                std::cout << "Add a node at the beginnig of the list" << "\n";
                addNodeBeginning(getValue());
                break;
            case 3:
                system("cls");
                std::cout << "Add a node at a certain position in the list (first position is considered 0) <position, value>" << "\n";
                addNodeAtPosition(getValue(), getValue());
                break;
            case 4:
                system("cls");
                std::cout << "Delete a node from a certain position from the list" << "\n";
                deleteNodeAtPosition(getValue());
                break;
            case 5:
                system("cls");
                std::cout << "Delete a certain value" << "\n";
                deleteNodeValue(getValue());
                break;
            case 6:
                system("cls");
                std::cout << "Delete elements smaller than a certain value" << "\n";
                deleteLessThan(getValue());
                break;
            case 7:
                system("cls");
                averageOfElements();
                break;
            case 8:
                system("cls");
                printList();
                break;
            case 9:
                break;
            default:
                std::cout << "Incorrect value!" << "\n";
            }

            std::cout << "\n";
        }

    }

void List::options()
{
    std::cout << "1. Add a node at the end of the list" << "\n";
    std::cout << "2. Add a node at the beginnig of the list" << "\n";
    std::cout << "3. Add a node at a certain position in the list" << "\n";
    std::cout << "4. Delete a node from a certain position from the list" << "\n";
    std::cout << "5. Delete a certain value" << "\n";
    std::cout << "6. Delete elements smaller than a certain value" << "\n";
    std::cout << "7. Compute the average of list elements" << "\n";
    std::cout << "8. Print list elements" << "\n";
    std::cout << "9. Exit the menu" << "\n";
    std::cout << "Your option: ";
}

int List::getValue()
{
    int myValue;

    std::cout << "Your value: ";
    std::cin >> myValue;

    return myValue;
}
