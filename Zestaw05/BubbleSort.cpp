#include <iostream>
#include <vector>

template <class T> void sort(std::vector<T>& v) {
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

int main() {
	std::vector<int> vctr;
	int x;

	while (std::cin >> x) {
		vctr.push_back(x);
	}

	sort<int>(vctr);
	for(const auto& i : vctr) std::cout << i << std::endl;
}
