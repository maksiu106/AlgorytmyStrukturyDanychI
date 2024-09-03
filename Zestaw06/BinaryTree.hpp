#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include <iostream>

class BinaryTree {
private:
	struct Node {
		int x;
		Node* left;
		Node* right;

		Node(int element) : x{element}, left{nullptr}, right{nullptr} {}
	};
	Node* root;
	int no_elements;

public:
	BinaryTree() : root{nullptr}, no_elements{0} {}

	~BinaryTree() {
		removeNodes(root);
	}

	void insert(int element) {
		Node* node = new Node(element);
		if (no_elements == 0) root = node;
		else {
			Node* position = root;
			Node* parent = nullptr;
			while (position != nullptr) {
				parent = position;
				if (element < position->x) position = position->left;
				else position = position->right;
			}
			if (element < parent->x) parent->left = node;
			else parent->right = node;
		}
		++no_elements;
	}

	Node* search(int element) {
		Node* result = root;
		while (result != nullptr) {
			if (result->x == element) return result;
			else if (element < result->x) result = result->left;
			else result = result->right;
		}
		return nullptr;
	}

	Node* searchRecursive(Node* node, int x) {
		if (node == nullptr) return nullptr;
		else if (node->x == x) return node;
		else if (x < node->x) return searchRecursive(node->left, x);
		else return searchRecursive(node->right, x);
	}

	int size() {
		return no_elements;
	}

	int minimum() {
		Node* node = root;
		while (node->left != nullptr) node = node->left;
		return node->x;
	}

	int maximum() {
		Node* node = root;
		while (node->right != nullptr) node = node->right;
		return node->x;
	}

	int depth() {
		return count_depth(root);
	}

	void inorder() {
		inorder(root);
	}

	void inorder(Node* node) {
		if (node != nullptr) {
			inorder(node->left);
			std::cout << node->x << std::endl;
			inorder(node->right);
		}
	}

	void preorder() {
		preorder(root);
	}

	void preorder(Node* node) {
		if (node != nullptr) {
			std::cout << node->x << std::endl;
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder() {
		postorder(root);
	}

	void postorder(Node* node) {
		if (node != nullptr) {
			postorder(node->left);
			postorder(node->right);
			std::cout << node->x << std::endl;
		}
	}

private:
	void removeNodes(Node* node) {
		if (node != nullptr) {
			removeNodes(node->left);
			removeNodes(node->right);
			delete node;
			--no_elements;
		}
	}

	int count_depth(Node* node) {
		if (node == nullptr) return 0;
		int left = count_depth(node->left);
		int right = count_depth(node->right);
		if (left > right) return left+1;
		else return right+1;
	}
};
#endif /* BINARYTREE_HPP_ */
