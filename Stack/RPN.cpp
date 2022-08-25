#include "ArrayStack.h"

#include <iostream>
#include <vector>
 
bool isDigit(const std::string &str) {
    bool isD = false;
    for (size_t i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            isD = true;
        }
        else {
            isD = false;
        }
    }
    return isD;
}

int operatorPriority(const std::string &op) {
    if(op == "+" || op == "-") {
        return 1;
    }
    if(op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

bool isOperator(const std::string &op) {
    return (op == "*" || op == "/" || op == "+" || op == "-");
}

int main() {
    Stack stack;
    std::string input_data;
    std::string outputString;

    while (std::cin >> input_data) {
        if (isDigit(input_data)) {
            outputString += input_data + " ";
        }

        if (input_data == "(") {
            stack.push(input_data);
        }

        if (input_data == ")") {
            while (!stack.empty() && stack.top() != "(") {
                outputString += stack.top() + " ";
                stack.pop();
            }
            stack.pop();
        }

        if (isOperator(input_data)) {
            while (!stack.empty() && operatorPriority(stack.top()) >= operatorPriority(input_data)) {
                outputString += stack.top() + " ";
                stack.pop();
            }
            stack.push(input_data);
        }
    }
    
    for (size_t i = 0; i < outputString.length() - 1; i++) {
        std::cout << outputString[i];
    }
    return 0;
}