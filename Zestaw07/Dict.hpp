#include <iostream>
#include <string>
#include <utility>
#include <string>
#include <sstream>

#include "LinkedList.hpp"

#define BUCKETS_SIZE 1024

//funkcja wykonująca hashowanie za pomocą algorytmu FNV
template <class K>
unsigned int hash (const K& argument) {
	//konwersja argumentu na string
	std::stringstream ss;
	ss << argument;
	std::string key = ss.str();

	unsigned int hash = 2166136261; //wartość bazowa FNV

	for (int i=0; i<(int)key.length(); ++i) {
		hash ^= static_cast<unsigned int>(key[i]); //robienie XOR na kolejnym znaku oraz dotychczasowym hashu
		hash *= 16777619; //mnożenie przez liczbę pierwszą FNV
	}

	return hash;
}

template <class K, class V>
class Dict
{
private:
	using Pair = std::pair<K, V>;
	LinkedList<K, V> bucket_list[BUCKETS_SIZE]; //tablica list wskaźnikowych
	int no_elements;

public:
    Dict() {
        no_elements = 0;
	}

	void clear() { // Czyści słownik
		for (int i=0; i<BUCKETS_SIZE; ++i) {
			bucket_list[i].clear();
		}
		no_elements = 0;
	}

	bool insert(const Pair& p) { // Dodaje parę klucz-wartość do słownika
		int bucket_no = hash(p.first) & (BUCKETS_SIZE-1);
		int index = bucket_list[bucket_no].find(p.first); //szukanie, czy słowo już jest w słowniku

		if (index != -1) { //jeśli słowo jest w słowniku, nadpisujemy
			bucket_list[bucket_no].erase(index);
		}

		bucket_list[bucket_no].push_back(p);
		++ no_elements;
		return true;
	}

	bool find(const K& k) { // Sprawdza czy słownik zawiera klucz
		int bucket_no = hash(k) & (BUCKETS_SIZE-1); //znajdujemy odpowiedni kubełek dla klucza
		return (bucket_list[bucket_no].find(k) != -1); //szukamy klucza w kubełku
	}

	V& operator[](const K& k) { // Zwraca wartość dla klucza
		int bucket_no = hash(k) & (BUCKETS_SIZE-1); //znajdujemy kubełek
		int index = bucket_list[bucket_no].find(k); //szukamy w kubełku

		if (index == -1) { //jeśli w słowniku nie ma tego klucza
			++no_elements;
			bucket_list[bucket_no].push_back(Pair(k, V()));
			return bucket_list[bucket_no].get_value(bucket_list[bucket_no].size()-1);
		}

		return bucket_list[bucket_no].get_value(index);
	}

	bool erase(const K& k) { // Usuwa parę od danym kluczu
		int bucket_no = hash(k) & (BUCKETS_SIZE-1); //znajdujemy kubełek dla klucza
		int index = bucket_list[bucket_no].find(k); //szukamy w kubełku

		if (index != -1) {
			bucket_list[bucket_no].erase(index);
			--no_elements;
			return true;
		} else return false;
	}

	int size() { // Zwraca liczbę par
		return no_elements;
	}

	bool empty() { // Sprawdza czy słownik jest pusty
		return (no_elements == 0);
	}

	void buckets() { // Wypisuje informację o słowniku
		int minimum = 0;
		int maximum = 0;
		for (int i=0; i < BUCKETS_SIZE; ++i) {
			int length = bucket_list[i].size();
			if (minimum > length) minimum = length;
			if (maximum < length) maximum = length;
		}

		std::cout << "# " << size() << " " << BUCKETS_SIZE << " " << minimum << " " << maximum << std::endl;
	}
};
