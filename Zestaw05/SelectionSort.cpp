#include <iostream>
#include <vector>

template <class T> void sort(std::vector<T>& v) {
	int size = v.size();
	int maximum = 0;
	for (int i=0; i<size; ++i) {
		maximum=0;
		for (int j=0; j<(size-i); ++j) {
			if (v[j] > v[maximum]) maximum = j;
		}
		std::swap(v[size-i-1], v[maximum]);
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
