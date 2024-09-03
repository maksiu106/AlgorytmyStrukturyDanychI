#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_

#define CAPACITY 1024

#include <iostream>

template<class T>

class ArrayList {
private:
	int head; //indeks pierwszej zajętej komórki
	int tail; //indeks ostatniej zajętej komórki
	int no_elements;
	T arr[CAPACITY];
public:
	ArrayList() : head{0}, tail{0}, no_elements{0} {}

	int increase(int index) {
		return (index+1) & (CAPACITY-1);
	}

	int decrease(int index) {
		return (index-1) & (CAPACITY-1);
	}

	void push_front(T x) { // Dołącza element na początek listy
		if (no_elements == CAPACITY) throw std::out_of_range("The list is full - unable to push");
		if (no_elements != 0) head = decrease(head);
		arr[head] = x;
		++no_elements;
	}

	T pop_front() { // Usuwa i zwraca element z początku listy
		if (no_elements == 0) throw std::out_of_range("No elements in list - unable to pop");
		T temp = arr[head];
		--no_elements;
		if (no_elements != 0) head = increase(head);
		return temp;
	}

	void push_back(T x) { // Dołącza element na koniec listy
		if (no_elements == CAPACITY) throw std::out_of_range("The list is full - unable to push");
		if (no_elements != 0) tail = increase(tail);
		arr[tail] = x;
		++no_elements;
	}

	T pop_back() { // Usuwa i zwraca element z końca listy
		if (no_elements == 0) throw std::out_of_range("No elements in list - unable to pop");
		T temp = arr[tail];
		--no_elements;
		if (no_elements != 0) tail = decrease(tail);
		return temp;
	}

	int size() { // Zwraca liczbę elementów w liście
		return no_elements;
	}

	bool empty() { // Zwraca `true` gdy lista jest pusta
		return (no_elements == 0);
	}

	void clear() { // Czyści listę
		head = 0;
		tail = 0;
		no_elements = 0;
	}

	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		int index = head;
		int end_index = increase(tail);
		while (arr[index] != x) {
			if (index == end_index) return -1;
			index = increase(index);
		}
		return index;
	}

	T erase(int i) { // Usuwa i zwraca element na pozycji `i`
		T temp = arr[i];
		int end_index = increase(tail);
		for (int x = i; x != end_index; x = increase(x)) {
			arr[x] = arr[increase(x)];
		}
		--no_elements;
		if (no_elements != 0) tail = decrease(tail);
		return temp;
	}

	void insert(int i, T x) { // Wstawia element `x` przed pozycję `i`
		if (no_elements == CAPACITY) throw std::out_of_range("The list is full - unable to push");
		for (int index = decrease(head); index != i; index = increase(index)) {
			arr[index] = arr[increase(index)];
		}
		arr[decrease(i)] = x;
		head = decrease(head);
		++no_elements;
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

#endif /* ARRAYLIST_HPP_ */
