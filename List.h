#pragma once
class Node;

class List
{
public:
	List();
	~List();
	void addNodeEnd(int);
	void addNodeBeginning(int);
	void addNodeAtPosition(int, int);
	void deleteNodeValue(int);
	void deleteNodeAtPosition(int);
	void deleteLessThan(int);
	void averageOfElements();
	void printList();
	void menu();
	void options();
	int getValue();

private:
	class Node
	{
	public:
		Node();
		Node(int);
		~Node();

	private:
		int value;
		Node* next;
		friend void List::addNodeEnd(int);
		friend void List::printList();
		friend void List::addNodeBeginning(int);
		friend void List::addNodeAtPosition(int, int);
		friend void List::deleteNodeAtPosition(int);
		friend void List::deleteNodeValue(int);
		friend void List::deleteLessThan(int);
		friend void List::averageOfElements();
	};

	Node* head;
	int noOfNodes;
};