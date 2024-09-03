#include <iostream>
#include <random>

int main(int argc, char* argv[]) {
	int n;
	int max;
	if (argc != 3) {
		n = 10000;
		max = 100000;
	}
	else {
		n = atoi(argv[1]);
		max = atoi(argv[2]);
	}

	srand(time(NULL));

	for (int i=0; i<n; ++i) {
		std::cout << rand()%(max+1) << std::endl;
	}
}
