#include <iostream>

#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int nums[100];
int length = 0;

void test_array_based_list() {
	ArrayList list;
	for (int i=0; i < length; ++i) {
		list.add(nums[i]);
	}
	cout << "Added " << length << " values to the Array-based list." << endl;
	cout << "The sum is: " << list.sum() << endl;
	cout << "Initial List:" << endl;
	list.print();
	cout << "Removing values larger than 15:" << endl;
	list.filter(15);
	cout << "Filtered List:" << endl;
	list.print();
	cout << "Sorted Lsit:" << endl;
	list.sort();
	list.print();
}

void test_linked_list() {
	LinkedList list;
	for (int i=0; i < length; ++i) {
		list.add(nums[i]);
	}
	cout << "Added " << length << " values to the Linked list." << endl;
	cout << "The sum is: " << list.sum() << endl;
	cout << "Initial List:" << endl;
	list.print();
	cout << "Removing values larger than 15:" << endl;
	list.filter(15);
	cout << "Filtered List:" << endl;
	list.print();
}

int main(int argc, char* argv[])
{
	int num = 0;
	cout << "Please enter up to 100 numbers.  Press CTRL-D to stop." << endl;
	while (cin >> num) {
		nums[length] = num;
		++length;	
	}
	test_array_based_list();
	test_linked_list();
}
