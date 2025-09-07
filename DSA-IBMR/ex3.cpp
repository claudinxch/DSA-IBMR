#include <iostream>
#include <stack>
#include <string>

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
	std::string expression;
	std::cout << "type the expression: ";
	std::getline(std::cin, expression);

	bool isExpressionBalanced = isBalanced(expression);

	if (isExpressionBalanced) {
		std::cout << "It is indeed balanced";
	}
	else {
		std::cout << "It is not balanced";
	}

	return 0;
}