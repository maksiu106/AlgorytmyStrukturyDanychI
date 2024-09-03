#ifndef LINKEDQUEUE_HPP_
#define LINKEDQUEUE_HPP_

#include <iostream>

class Queue
{
private:
	struct Node
	{
		int val;
		Node* next;

		Node(int val) : val(val), next(nullptr) { }
	};
	Node* head; //wskaźnik na pierwszy element do wyciągnięcia
	Node* tail;
	int no_elem;
	//int capacity; //zupełnie niepotrzebne do działania - ale potrzebne, żeby było kompatybilnie z programami napisanymi pod ArrayQueue

public:
	Queue(int cap = 0) : head{nullptr}, tail{nullptr}, no_elem{} { }

	~Queue()
	{
		while (no_elem > 0) //iteracyjne usuwanie wszystkich węzłów
		{
			Node* temp = head->next; //zapamiętujemy wskaźnik na następny element
			delete head; //usuwamy ogom
			head = temp; //następny element staje się ogonem
			--no_elem;
		}
	}

	void push(int x)
	{
//if (capacity == no_elem) {throw std::out_of_range("Error - the queue is full"); return;}
		Node* ptr = new Node; //tworzenie nowego węzła
		ptr->val = x;
		if (no_elem > 0) tail->next = ptr; //jeśli jest już coś w kolejce, to za ostatnim elementem doczepiamy nowy
		else head = ptr; //jeśli to jest pierwszy element, to staje się równocześnie początkiem kolejki
		tail = ptr; //nowym końcem kolejki jest nowy węzeł
		++no_elem;
	}

	int pop()
	{
//if (no_elem == 0) {throw std::out_of_range("Error - the queue is empty"); return 0;}
		int temp = head->val; //odczytanie wartości głowy
		Node* ptr = head; //tworzenie wskaźnika na miejsce w pamięci, gdzie jest węzeł głowy
		head = head->next; //przepinanie głowy
		delete ptr; //usuwanie z pamięci dotychczasowego węzła-głowy
		--no_elem;
		return temp;
	}

	int size() {return no_elem;}
	int empty() {return (no_elem == 0);}

};

#endif /* LINKEDQUEUE_HPP_ */
