
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

LinkedList::LinkedList() : m_head{nullptr}
{ }

LinkedList::~LinkedList()
{
	while (m_head) {
		Node* cur = m_head->next;
		delete m_head;
		m_head = cur;
	}
}

void LinkedList::add(const int num)
{	
	Node* new_Node = new Node();
	new_Node->value = num;
	new_Node->next = nullptr;
	if (m_head == nullptr)
	{
		m_head = new_Node;
	}
	else
	{
		Node* cur = m_head;
		while (cur-> next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new_Node;
	}
}

bool LinkedList::contains(const int num) const
{
	Node* cur = m_head;
	while(cur->next != nullptr)
	{
		if (cur->value == num)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool LinkedList::remove(const int num)
{
	if (m_head == nullptr)
	{
		return false;
	}
	if (m_head->value == num)
	{
		Node* temp = m_head;
		m_head = m_head->next;
		delete temp;
		return true;
	}
	Node* cur = m_head;
	while(cur->next != nullptr)
	{
		if (cur->next->value == num)
		{
			Node* temp = cur->next;
			cur->next = temp->next;
			delete temp;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

int LinkedList::size() const
{
	int list_size = 0;
	Node* cur = m_head;
	while(cur != nullptr)
	{
		list_size += 1;
		cur = cur->next;
	}
	return list_size;
}

int LinkedList::sum() const
{
	int sum = 0;
	Node* cur = m_head;
	while(cur != nullptr)
	{
		sum += cur->value;
		cur = cur->next;
	}
	return sum;
}

void LinkedList::filter(const int cutoff) 
{
	while (m_head != nullptr && m_head->value > cutoff)
	{
		Node* temp = m_head;
		m_head = m_head->next;
		delete temp;
	}
	if (m_head == nullptr) return;
	Node* cur = m_head;
	while (cur->next != nullptr)
	{
		if (cur->next->value > cutoff)
		{
			Node* temp = cur->next;
			cur->next = temp->next;
			delete temp;
		}
		else
		{
			cur = cur->next;
		}
	}
}

void LinkedList::print() const
{
	Node* cur = m_head;

	//If the list isn't empty, print out the first element
	if (cur) {
		cout << cur->value;
		cur = cur->next;
	}

	//As long as there are more elements, print a space and then the next element
	while (cur) {
		cout << " " << cur->value;
		cur = cur->next;
	}

	//At the end of the list, move the cursor to the next line.
	cout << endl;
}

void LinkedList::save_to(ostream& out)
{
	Node* cur = m_head;
	while (cur)
	{
		out << cur->value << " ";
	       cur = cur->next;	
	}
	out << endl;
}

void LinkedList::load_from(istream& in, int count)
{
	int value;
	for (int a = 0; a < count; ++a)
	{
		if (in >> value)
		{
			this->add(value);
		}
	}
}
