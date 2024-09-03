#include <iostream>

#include "BinaryTree.hpp"

int main() {
	int size, number;
	std::cin >> size;

	BinaryTree tree;

	for (int i=0; i<size; ++i) {
		std::cin >> number;
		tree.insert(number);
	}

	std::cout << tree.size() << " " << tree.depth() << " " << tree.minimum() << " " << tree.maximum() << std::endl;

	tree.preorder();

	for (int i=1; i<10; ++i) {
		if (tree.search(i)) std::cout << "Yes" << std::endl;
		else std::cout << "No" << std::endl;
	}
}
