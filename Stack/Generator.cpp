#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

#define N 1000000

enum OperationOnStack : std::int8_t {
    PUSH = 1,
    POP,
    SIZE
};

int main()
{
    int n;
    std::cin >> n;
    std::cout << n << std::endl;
    srand(time(NULL));

    if (n > N) {
        throw std::out_of_range("Wprowadz mniejsza liczbe!");
    }

    else {
        OperationOnStack push = OperationOnStack::PUSH;
        OperationOnStack pop = OperationOnStack::POP;
        OperationOnStack size = OperationOnStack::SIZE;

        for (size_t i = 0; i < n; i++) {
            int random_operation = std::rand() % 3 + 1;
            if (random_operation == push) {
                int random_x = std::rand() % (N + 1);
                std::cout << "A" << " " << random_x << std::endl;
            }
            else if (random_operation == pop) {
                std::cout << "D" << std::endl;
            }
            else if (random_operation == size) {
                std::cout << "S" << std::endl;
            }
        }
    }
    return 0;
}