#ifndef LINKEDSTACK_HPP_
#define LINKEDSTACK_HPP_

#include <iostream>

class Stack
{
private:
	struct Node
	{
		int data;
		Node* last;
	};
	int no_elements;
	Node* top;
	int capacity; //niepotrzebne - ale używane dla kompatybilności z programami napisanymi do użycia ArrayStack
public:
	Stack(int cap) // Konstruktor
	{
		no_elements = 0;
		top = NULL;
		capacity = cap; //niepotrzebne - użyte po to, aby kompilator nie wyrzucał ostrzeżenia
	}
	~Stack()
	{
		while (no_elements > 0) //usuwam wszystkie węzły
		{
			Node* temporary = top->last; //przepinam wskaźnik na przedostatni element
			delete top; //usuwam ostatni element
			top = temporary; //przedostatni element staje się ostatni
			--no_elements;
		}
	}

	void push(int x) // Wstawia element na stos
	{
		Node* ptr = new Node; //tworzę nowy węzeł
		ptr->data = x; //przypisuję atrybutowi data wartość
		ptr->last = top; //dla niego poprzedni element to dotychczasowy top
		top = ptr; //nowo stworzony węzeł jest na wierzchu
		++no_elements;
	}

	int pop() // Usuwa element ze stosu i zwraca jego wartość
	{
		int out = top->data; //odczytuję wartość na wyjście
		Node* temp = top->last; //przepinam znacznik na nowy węzeł na górze
		delete top; //usuwam dotychczasowy węzeł na górze
		top = temp;
		--no_elements;
		return out;
	}
	int size() // Zwraca liczbę elementów na stosie
	{
		return no_elements;
	}
	bool empty() // Sprawdza czy stos jest pusty
	{
		if (no_elements == 0) return 1;
		else return 0;
	}
};

#endif
