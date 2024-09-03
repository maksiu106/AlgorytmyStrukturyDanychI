#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

class Stack
{
private:
	int capacity;
	int* data; //dynamiczne alokowanie tablicy
	int top;
public:
	Stack(int cap) // Konstruktor. Argumentem jest rozmiar tablicy.
	{
		capacity = cap;
		data = new int[capacity];
		top = 0;
	}
	~Stack()
	{
		delete[] data;
	}
	void push(int x) // Wstawia element na stos
	{
		if (top==(capacity-1)) {throw std::out_of_range("Error - the stack is full"); return;}
		else
		{
			data[top] = x;
			top++;
		}
		return;
	}
	int pop() // Usuwa element ze stosu i zwraca jego wartość
	{
		if (top==0) {throw std::out_of_range("Error - the stack is empty"); return 0;}
		else
		{
			int val = data[top-1];
			top--;
			return val;
		}
	}
	int size() // Zwraca liczbę elementów na stosie
	{
		return top;
	}
	bool empty() // Sprawdza czy stos jest pusty
	{
		if (top==0) return 1;
		else return 0;
	}
};

#endif
