#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>

template<class K, class V>

class LinkedList {
	using Pair = std::pair<K, V>;
	struct Node {
		Pair x; //element przechowywany w liście
		Node* prev;
		Node* next;

		Node(Pair val, Node* left, Node* right) : x(val), prev(left), next(right) {}
	};
	Node guard; //wskaźniki na początek i koniec listy
	int no_elements;

public:
	LinkedList() : guard{Pair{}, &guard, &guard}, no_elements{0} {} //lista inicjalizacyjna - guard jako next i prev ma wskaźnik na siebie samego
	~LinkedList() {
		clear();
	}

	void push_front(Pair x) { // Dołącza element na początek listy
		auto left = &guard;
		auto right = guard.next;
		auto node = new Node(x, left, right);
		guard.next = node;
		(node->next)->prev = node;
		++no_elements;
	}

	Pair pop_front() { // Usuwa i zwraca element z początku listy
		if (empty()) throw std::out_of_range("The list is empty");
		Node* node = guard.next;
		Pair temp = node->x;
		guard.next = node->next;
		(node->next)->prev = &guard;
		delete node;
		--no_elements;
		return temp;
	}

	void push_back(Pair x) { // Dołącza element na koniec listy
		auto left = guard.prev;
		auto right = &guard;
		auto node = new Node(x, left, right);
		(node->prev)->next = node;
		guard.prev = node;
		++no_elements;
	}

	Pair pop_back() { // Usuwa i zwraca element z końca listy
		if (empty()) throw std::out_of_range("The list is empty");
		Node* node = guard.prev;
		Pair temp = node->x;
		guard.prev = node->prev;
		(node->prev)->next = &guard;
		delete node;
		--no_elements;
		return temp;
	}

	int size() { // Zwraca liczbę elementów w liście
		return no_elements;
	}

	bool empty() { // Zwraca 'true' gdy lista jest pusta
		return (no_elements == 0);
	}

	void clear() { // Czyści listę
		while (no_elements != 0) {
			Node* node = guard.next;
			guard.next = node->next;
			delete node;
			--no_elements;
		}
		guard.prev = &guard;
	}

	int find(K key) { // Zwraca pozycję pierwszego elementu o wartości 'x'
		Node* node = guard.next;
		for (int index=0; index<no_elements; ++index) {
			if (node->x.first == key) return index;
			node = node->next;
		}
		return -1;
	}

	Pair erase(int i) { // Usuwa i zwraca element na pozycji 'i'
		if (i>=no_elements) throw std::out_of_range("There are too few elements in list, so this index doesn't exist");
		int index = 0;
		Node* node = guard.next;
		while (index < i) {
			node = node->next;
			++index;
		}
		(node->prev)->next = node->next;
		(node->next)->prev = node->prev;
		Pair temp = node->x;
		delete node;
		--no_elements;
		return temp;
	}

	void insert(int i, Pair x) { // Wstawia element 'x' przed pozycję 'i'
		if (i>=no_elements) throw std::out_of_range("There are too few elements in list, so this index doesn't exist");
		int index = 0;
		Node* i_node = guard.next;
		while (index < i) {
			i_node = i_node->next;
			++index;
		}
		auto left = i_node->prev;
		auto right = i_node;
		auto node = new Node(x, left, right);
		(i_node->prev)->next = node;
		i_node->prev = node;
		++no_elements;
	}

	int remove(Pair x) { // Usuwa wystąpienia 'x' i zwraca ich liczbę
		int i = 0;
		int count = 0;
		Node* node = guard.next;
		while ((i = find(x)) != -1) {
			erase(i);
			//T del = erase(i);
			++count;
		}
		no_elements -= count;
		return count;
	}

	V& get_value(int index) {
		if (index>=no_elements) throw std::out_of_range("Invalid index number - too few elements in this list");
		Node* node = guard.next;
		for (int i=0; i < index; ++i) {
			node = node->next;
		}
		return node->x.second;
	}
};

#endif /* LINKEDLIST_HPP_ */
