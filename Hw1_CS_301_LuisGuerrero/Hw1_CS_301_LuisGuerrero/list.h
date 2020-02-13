#pragma once
#include<string>

#include"node.h"

class list
{
public:
	list();
	~list();

	bool isEmpty() const;
	int getCount() const;

	node* insert(std::string&, const int);
	node* insertFirst(std::string&);
	node* insertLast(std::string&);
	void removeNode(const int);
	void removeNodeByName(std::string&);
	void removeAllNodes();
	std::string getAvailable();
	std::string& getData(const int);
	std::string& getFirstData();
	bool checkAvailable();

	void printLinkedList();
	void printListCus_Hol();

protected:
	int count;
	node* head;

};


list::list() : count(0), head(nullptr)
{
}


list::~list()
{
}


bool list::isEmpty() const
{
	return count == 0;
}


int list::getCount() const
{
	return count;
}


node* list::insert(std::string& names, const int position)
{
	if (position < 0 || position > count)
	{
		throw "error";
	}

	node* returnNode;

	if (head == nullptr) //list is empty
	{ 
		head = new node(names);

		returnNode = head;
	}
	else if (position == 0)//replacing head
	{
		node* temp = head;
		head = new node(names, temp);

		returnNode = head;
	}
	else
	{
		node* currentNode = head;
		for (int i = 0; i < position - 1; i++)
		{
			currentNode = currentNode->next;
		}

		node* temp = currentNode->next;
		currentNode->next = new node(names, temp);

		returnNode = currentNode->next;
	}
	count++;

	return returnNode;
}

node* list::insertFirst(std::string& name)
{
	return insert(name, 0);
}


node* list::insertLast(std::string& name)
{
	return insert(name, count);
}


void list::removeNode(const int position)
{
	if (position < 0 || position > count - 1)
	{
		throw "Error: Out of rage";
	}
	else if (head == nullptr)
	{
		throw "List is already empty";
	}

	if (position == 0)
	{
		node* currentNode = head->next;
		delete head;

		head = currentNode;
	}
	else
	{
		node* prevNode = nullptr;
		node* currNode = head;
		for (int i = 0; i < position; i++)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		prevNode->next = currNode->next;
		delete currNode;
	}
	count--;
	return;
}


void list::removeNodeByName(std::string& nameToDelete)
{
	node* currentNode = head;

	for (int i = 0; i < count; i++)
	{
		if (currentNode->data == nameToDelete)
		{
			
			removeNode(i);
			return;
		}
		else
		{
			currentNode = currentNode->next;
		}
	}
	std::cout << "Data could not be found..." << std::endl;
}

void list::removeAllNodes()
{
	if (head == nullptr)
	{
		return;
	}
	else
	{
		node* currentNode = head;
		while (currentNode->next != nullptr)
		{
			node* previousNode = currentNode;
			currentNode = currentNode->next;
			delete previousNode;
		}
		delete currentNode;
	}
	count = 0; 
	head = nullptr;

	return;
}


std::string list::getAvailable()
{
	node* currentNode = head;
	std::string temp;

	while (currentNode->data == "0" && currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	temp = currentNode->data;
	currentNode->data = "0";
	return temp;
}


std::string& list::getData(const int pos)
{
	if (head == nullptr) //The list is empty
	{
		throw "List is empty";
	}

	if (pos < 0 || pos > count - 1)
	{
		throw "Index out of range.";
	}

	node* currentNode = head;
	for (int i = 0; i < pos; i++)
	{
		currentNode = currentNode->next;
	}

	return currentNode->data;
}


std::string& list::getFirstData()
{
	return getData(0);
}


bool list::checkAvailable()
{
	node* tempNode = head;
	bool available = false;
	while (tempNode->data == "0")
	{
		if(tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}
		else 
		{
			return available;
		}
	}
	available = true;
	return available;
}


void list::printLinkedList()
{
	node* currentNode = head;
	std::string space = " ";
	space.resize(20, ' ');
	while (currentNode->next != nullptr)
	{
		std::cout << space << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

void list::printListCus_Hol()
{
	node* currentNode = head;
	node* previousNode = currentNode->next;
	
	while (currentNode->next != nullptr )
	{
		std::string c = currentNode->data;
		c.resize(20, ' ');
		std::string h = previousNode->data;
		h.resize(20, ' ');
		std::cout << "CUSTOMER: " << c << "HOLIDAY: " << h << std::endl;
		currentNode = previousNode->next;
		previousNode->next = currentNode->next;
	}
}
