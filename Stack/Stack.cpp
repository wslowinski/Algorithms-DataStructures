#include "LinkedStack.h"

#define SIZE 1000000

int main()
{
    char operation;
    int input_size, value;

    std::cin >> input_size;
        if (input_size > SIZE) {
        throw std::out_of_range("Zmniejsz rozmiar danych wejsciowych!");
    }

    Stack *stack = new Stack();
    for (int i = 0; i < input_size; i++) {
        std::cin >> operation;
        if (operation == 'A') {
            std::cin >> value;
            stack->push(value);
        }

        else if (operation == 'D') {
            int result = stack->pop();
            if (result == -1) {
                std::cout << "EMPTY" << std::endl;
            }
            else {
                std::cout << result << std::endl;
            }
        }
        else if (operation == 'S') {
            std::cout << stack->size() << std::endl;
        }
    }
    return 0;
}
