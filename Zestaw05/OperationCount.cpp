//program zliczający operacje dominujące w algorytmie Bubble Sort
//jako operację dominującą przyjęto porównywanie liczb

#include <iostream>
#include <vector>
#include <random>

template <class T> int sort(std::vector<T>& v) {
	int size = v.size();
	int count = 0;
	bool changes;
	for (int i=0; i<size-1; ++i) {
		changes = 0;
		for (int j=0; j<(size-i-1); ++j) {
			//porównywanie
			++count; //wykonywane porównanie
			if (v[j] > v[j+1]) {
				std::swap(v[j], v[j+1]);
				changes = 1;
			}
		}
		if (changes == 0) break;
	}
	return count;
}

int main() {
	std::vector<int> vctr;

	//wektor posortowany
	for (int i=0; i<10000; ++i) vctr.push_back(i);
	std::cout << "Dla posortowanego wektora o rozmiarze 10 000 wykonano " << sort<int>(vctr) << " operacji porownania" << std::endl;

	vctr.clear();
	//wektor odwrotnie posortowany
	for (int i=10000; i>0; --i) vctr.push_back(i);
	std::cout << "Dla odwrotnie posortowanego wektora o rozmiarze 10 000 wykonano " << sort<int>(vctr) << " operacji porownania" << std::endl;

	//wektor z losowymi wartościami; uśredniona wartość ze 100 powtórzeń
	int arr[100];
	srand(time(NULL));
	for (int n=0; n<100; ++n) {
		vctr.clear();
		for (int i=0; i<10000; ++i) vctr.push_back(rand());
		arr[n] = sort<int>(vctr);
	}
	int suma = 0;
	for (int n=0; n<100; ++n) suma += arr[n];
	std::cout << "Dla stu losowych wektorow o rozmiarze 10 000 wykonano srednio " << suma/100 << " operacji porownania" << std::endl;
}
