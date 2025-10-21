#include <iostream>
#include <stack>
#include <string>
#include "LinkedList.cpp"
#include "SortMethods.cpp"

#define ARRAY_SIZE 7

bool isBalanced(const std::string& expression) {
	std::stack<char> parenthesis;

	for (char ch : expression) {
		if (ch == '(') {
			parenthesis.push(ch);
		}
		else if (ch == ')') {
			if (parenthesis.empty()) {
				return false;
			}
			parenthesis.pop();
		}
	}

	if (parenthesis.empty()) {
		return true;
	}
	return false;
}

int main() {
	/*std::string expression;
	std::cout << "type the expression: ";
	std::getline(std::cin, expression);

	bool isExpressionBalanced = isBalanced(expression);

	if (isExpressionBalanced) {
		std::cout << "It is indeed balanced";
	}
	else {
		std::cout << "It is not balanced";
	}*/

	LinkedList list;
	int option, value;

	do {
		std::cout << "\n=== MENU ===\n";
		std::cout << "\n1. Insert element at front\n";
		std::cout << "\n2. Insert element at end\n";
		std::cout << "\n3. Remove element\n";
		std::cout << "\n4. See list\n";
		std::cout << "\n0. Leave\n";
		std::cout << "\nChoose an option\n";
		std::cin >> option;

		switch (option) {
		case 1:
			std::cout << "Type the value to insert: ";
			std::cin >> value;
			list.prepend(value);
			break;
		case 2:
			std::cout << "Type the value to insert: ";
			std::cin >> value;
			list.append(value);
			break;
		case 3:
			std::cout << "Type the value to remove: ";
			std::cin >> value;
			list.removeByValue(value);
			break;
		case 4:
			list.traverse();
			break;
		case 0:
			std::cout << "Finishing program...\n" << std::endl;
		default:
			std::cout << "Invalid option. Try again.\n";
		}
	} while (option != 0);

	list.freeList();

	int arr[ARRAY_SIZE] = {2,1,4,3,7,5, 0};
	SortMethods sort;
	sort.QuickSort(arr, 0, ARRAY_SIZE - 1);
	for (int n : arr)
	{
		std::cout << n << std::endl;
	}
	return 0;
}