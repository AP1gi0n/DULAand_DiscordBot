#ifndef __ARRAY_LIST_H
#define __ARRAY_LIST_H

class ArrayList {
	private:
		int* m_data;
		int m_size;
		int m_capacity;
		int find(const int num) const;

	public:
		ArrayList(int capacity = 100);
		~ArrayList();
		void add(const int num);
		bool contains(const int num) const;
		bool remove(const int num);
		int sum();
		void filter(const int cutoff);
		void sort();
		int size() const;
		void print() const;
		int& operator[](int index);
};
#endif
