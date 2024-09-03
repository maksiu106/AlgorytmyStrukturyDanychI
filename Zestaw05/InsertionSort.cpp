#include <iostream>
#include <vector>

template <class T> void sort(std::vector<T>& v) {
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

int main() {
	std::vector<int> vctr;
	int x;

	while (std::cin >> x) {
		vctr.push_back(x);
	}

	sort<int>(vctr);
	for(const auto& i : vctr) std::cout << i << std::endl;
}
