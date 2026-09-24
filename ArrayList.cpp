#include "ArrayList.h"
#include <algorithm>
#include <iostream>

using namespace std;

ArrayList::ArrayList(int capacity) : m_size{0}, m_capacity(capacity)
{ 
	m_data = new int[capacity];
}

ArrayList::~ArrayList()
{
	delete[] m_data;
}

void ArrayList::add(const int num)
{
	if (m_size == m_capacity)
	{

		return;
	}
	m_data[m_size] += num;
	m_size += 1;


}

int ArrayList::find(const int num) const
{
	for (int a = 0; a <= m_size; ++a)
	{
		if (m_data[a] == num)
		{
			return a;
		}
	}
	return -1;
}

bool ArrayList::contains(const int num) const
{
	int num_find = find(num);
	if (num_find > -1)
	{
		return true;
	}
	return false;
}

bool ArrayList::remove(const int num)
{
	bool is_in_list = contains(num);
	if (is_in_list)
	{
		for (int a = find(num); a < m_size; ++a)
		{
			m_data[a] = m_data[a + 1];
		}
		m_size -= 1;
		return true;
	}
	return false;
}

int ArrayList::size() const
{
	return m_size;
}

int ArrayList::sum()
{
	int sum = 0;
	for (int a = 0; a <m_size; ++a)
	{
		sum += m_data[a];
	}
	return sum;
}

void ArrayList::filter(const int cutoff)
{
	for (int a = 0; a < m_size;)
	{
		if(m_data[a] > cutoff)
		{
			for (int b = a; b < m_size - 1; ++b)
			{
			m_data[b] = m_data[b + 1];
			}
			m_size--;
		}
		else
		{
			++a;
		}
	}
}

void ArrayList::sort()
{
	for (int a = 0; a < m_size; ++a)
	{
		for (int b = 0; b < m_size - a - 1; ++b)
		{
			if (m_data[b] > m_data[b + 1])
			{
				swap(m_data[b], m_data[b +1]);
			}
		}
	}
}

void ArrayList::print() const
{
	//If the list isn't empty, print out the first element
	if (m_size > 0) {
		cout << m_data[0];
	}

	//As long as there are more elements, print a space and then the next element
	for (int i = 1; i < m_size; ++i) {
		cout << " " << m_data[i]; 
	}

	//At the end of the list, move the cursor to the next line.
	cout << endl;
}

// Needed getter for glitter
int& ArrayList::operator[](int index)
{
	if (index < 0 || index >= m_size)
	{
		throw out_of_range("ArrayList index is out of bounds");
	}
	return m_data[index];
}
