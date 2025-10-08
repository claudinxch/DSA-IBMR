#include <iostream>

class LinkedList {
	class Node {
	public:
		int value;
		Node* next;
		Node(int val) : value(val), next(nullptr) {}
	};

	Node* head;

public:
	LinkedList() : head(nullptr) {}

	void append(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void prepend(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			return;
		}

		newNode->next = head;
		head = newNode;
	}

	void removeByValue(int val) {
		if (!head) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		if (head->value == val) {
			Node* temp = head;
			head = temp->next;
			delete temp;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			if (temp->next->value == val) {
				Node* nodeToDelete = temp->next;
				temp->next = temp->next->next;
				delete nodeToDelete; // Prevent memory leak
				break;
			}
			temp = temp->next;
		}
	}

	void traverse() {
		if (!head) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		std::cout << "\nList elements:\n";

		Node* current = head;
		while (current) {
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}

	void freeList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
	}
};