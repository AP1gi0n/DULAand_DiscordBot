#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

class Node {
	public:
		int value;
		Node* next;
};

class LinkedList {
	private:
		Node* m_head;
	public:
		LinkedList();
		~LinkedList();
		void add(const int num);
		bool contains(const int num) const;
		bool remove(const int num);
		int size() const;
		int sum() const;
		void filter(const int cutoff);
		void print() const;
		void save_to(ostream& out);
		void load_from(istream& in, int count);
};

#endif
