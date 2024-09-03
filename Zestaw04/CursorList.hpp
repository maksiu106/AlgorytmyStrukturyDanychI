#ifndef CURSORLIST_HPP_
#define CURSORLIST_HPP_

#define CAPACITY 1000

#include <iostream>

template<class T>

class CursorList {
private:
	struct Node {
		T x;
		int next;
	};
	Node arr[CAPACITY];
	int head; // Indeks pierwszego węzła
	int tail; // Indeks ostatniego węzła (na potrzeby push_back())
	int no_elements; // Rozmiar listy
	int spare; // Indeks pierwszego nieużytego elementu tablicy

	int allocate() { // zwraca indeks pierwszego wolnego węzła i wypina go z listy wolnych węzłów
		int temp = spare;
		spare = arr[spare].next;
		return temp;
	}

	void deallocate(int n) { // wpina zwolniony węzeł do listy wolnych węzłów
		arr[n].next = spare;
		spare = n;
	}

public:
	CursorList() { //konstruktor
		head = -1;
		tail = -1;
		spare = 0;
		no_elements = 0;
		for (int i=0; i<CAPACITY-1; ++i) {
			arr[i].next = i+1;
		}
		arr[CAPACITY-1].next = -1;
	}

	~CursorList() {} //destruktor

	void push_front(T x) { // Dołącza element na początek listy
		if (no_elements == CAPACITY) throw std::out_of_range("The list is full - unable to push");
		int node = allocate();
		arr[node].x = x;
		arr[node].next = head;
		head = node;
		if (no_elements == 0) tail = node;
		++no_elements;
	}

	T pop_front() { // Usuwa i zwraca element z początku listy
		if (no_elements == 0) throw std::out_of_range("No elements in list - unable to pop");
		T x = arr[head].x;
		int node = head;
		head = arr[head].next;
		deallocate(node);
		--no_elements;
		if (no_elements == 0) tail = -1;
		return x;
	}

	void push_back(T x) { // Dołącza element na koniec listy
		if (no_elements == CAPACITY) throw std::out_of_range("The list is full - unable to push");
		int node = allocate();
		arr[node].x = x;
		arr[tail].next = node;
		arr[node].next = -1;
		tail = node;
		if (no_elements == 0) head = node;
		++no_elements;
	}

	T pop_back() { // Usuwa i zwraca element z końca listy
		if (no_elements == 0) throw std::out_of_range("No elements in list - unable to pop");
		T x = arr[tail].x;
		deallocate(tail);
		--no_elements;

		//szukanie nowego tail
		if (no_elements == 0) {
			tail = -1;
			head = -1;
		}
		else {
			int i = head; //indeks potrzebny do szukania nowego tail
			while (arr[i].next != tail) {
				i = arr[i].next;
			}
			tail = i;
			arr[tail].next = -1;
		}

		return x;
	}

	int size() { // Zwraca liczbę elementów w liście
		return no_elements;
	}

	bool empty() { // Zwraca `true` gdy lista jest pusta
		return (no_elements == 0);
	}

	void clear() { // Czyści listę
		while (no_elements != 0) {
			int i = head;
			head = arr[head].next;
			deallocate(i);
			--no_elements;
		}
		head = -1;
		tail = -1;
	}

	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		if (no_elements == 0) return -1;
		int i = head;
		while (arr[i].x != x) {
			if (arr[i].next == -1) return -1;
			else i = arr[i].next;
		}
		return i;
	}

	T erase(int i) { // Usuwa i zwraca element na pozycji `i`
		T x;
		if (i == head) x = pop_front();
		else {
			int index = head; //indeks pierwszego elementu przed i
			while (arr[index].next != i) {
				if (arr[index].next == -1) throw std::out_of_range("Unable to find element with specified index");
				else index = arr[index].next;
			}
			x = arr[i].x;
			arr[index].next = arr[i].next;
			deallocate(i);
			--no_elements;
		}
		return x;
	}

	void insert(int i, T x) { // Wstawia element `x` przed pozycję `i`
		if (i == head) push_front(x);
		else {
			int index = head; //indeks pierwszego elementu przed i
					while (arr[index].next != i) {
						if (arr[index].next == -1) throw std::out_of_range("Unable to find element with specified index");
						else index = arr[index].next;
					}
					int node = allocate();
					arr[index].next = node;
					arr[node].next = i;
					arr[node].x = x;
					++no_elements;
		}
	}

	int remove(T x) { // Usuwa wystąpienia `x` i zwraca ich liczbę
		int count = 0;
		int i = 0;
		while ((i = find(x)) != -1) {
			erase(i);
			++count;
		}
		return count;
	}
};

#endif /* CURSORLIST_HPP_ */
