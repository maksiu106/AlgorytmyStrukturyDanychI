#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template <class T> void BubbleSort(std::vector<T>& v);
template <class T> void SelectionSort(std::vector<T>& v);
template <class T> void InsertionSort(std::vector<T>& v);
double time_counter(int size, int method);

int main() {
	srandom(time(NULL));

	//BubbleSort
	std::cout << "Bubble sort - pomiar czasu wykonania sortowania dla losowego wektora o zmiennym rozmiarze danych wejsciowych" << std::endl;
	std::cout << "Rozmiar wektora\tBubbleSort\tSelectionSort\tInsertionSort" << std::endl;
	int data_size = 40000;
	for (int i=0; i<10; ++i) {
			std::cout << data_size << "\t" << time_counter(data_size, 0) << "\t" << time_counter(data_size, 1) << "\t" << time_counter(data_size, 2) << std::endl;
			data_size += 40000;
	}
}


double time_counter(int size, int method) {
	std::vector<int> vctr;
	for (int i=0; i<size; ++i) {
		vctr.push_back(random());
	}

	auto start = std::chrono::high_resolution_clock::now();

	switch(method)
	{
	case 0: {BubbleSort<int>(vctr); break;}
	case 1: {SelectionSort<int>(vctr); break;}
	case 2: {InsertionSort<int>(vctr); break;}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}

template <class T> void BubbleSort(std::vector<T>& v) {
	int size = v.size();
	bool changes;
	for (int i=0; i<size-1; ++i) {
		changes = 0;
		for (int j=0; j<(size-i-1); ++j) {
			if (v[j] > v[j+1]) {
				std::swap(v[j], v[j+1]);
				changes = 1;
			}
		}
		if (changes == 0) break;
	}
}

template <class T> void SelectionSort(std::vector<T>& v) {
	int size = v.size();
	int maximum = 0;
	for (int i=0; i<size; ++i) {
		for (int j=0; j<(size-i); ++j) {
			if (v[j] > v[maximum]) maximum = j;
		}
		std::swap(v[size-i-1], v[maximum]);
	}
}

template <class T> void InsertionSort(std::vector<T>& v) {
	int size = v.size();
	int j;
	for (int i=1; i<size; ++i) {
		T element = v[i];
		for (j = i-1; (j>=0 && v[j] > element); --j) {
			v[j+1] = v[j];
		}
		v[j+1] = element;
	}
}
