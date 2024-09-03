#ifndef ARRAYQUEUE_HPP_
#define ARRAYQUEUE_HPP_

#include <iostream>

class Queue
{
private:
	int capacity;
	int* data;
	int tail;
	int head;
	int no_elem;

public:
	Queue(int cap = 100000) //Konstruktor domyślny
	{
		int x = 2;
		while (cap > x) x*=2; //Rozmiar tablicy będzie najmniejszą potęgą dwójki większą od rozmiaru zadanego w konstruktorze
		capacity = x;
		data = new int[capacity];
		head = 0;
		tail = 0;
		no_elem = 0;
	}

	~Queue()
	{
		delete[] data;
	}

	void push(int x) // Wstawia element x do kolejki (także enqueue)
	{
		if (capacity == no_elem) {throw std::out_of_range("Error - the queue is full"); return;}
		data[tail] = x;
		tail = (tail+1) & (capacity-1); //można to rozwiązać w ten sposób, ponieważ pojemność tablicy zawsze będzie potęgą dwójki
		++no_elem;
	}

	int pop() // Usuwa element z kolejki i zwraca jego wartość (dequeue)
	{
		if (no_elem == 0) {throw std::out_of_range("Error - the queue is empty"); return 0;}
		int x = data[head];
		head = (head+1) & (capacity-1);
		--no_elem;
		return x;
	}

	int size() {return no_elem;}

	bool empty() {return (no_elem == 0);}
};

#endif /* ARRAYQUEUE_HPP_ */
