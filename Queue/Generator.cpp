#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

#define N 1000000

enum OperationOnQueue : std::int8_t {
    ENQUEUE = 1,
    DEQUEUE,
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

        OperationOnQueue enqueue = OperationOnQueue::ENQUEUE;
        OperationOnQueue dequeue = OperationOnQueue::DEQUEUE;
        OperationOnQueue size = OperationOnQueue::SIZE;

        for (size_t i = 0; i < n; i++) {
            int random_operation = std::rand() % 3 + 1;

            if (random_operation == enqueue) {
                int random_x = std::rand() % (N + 1);
                std::cout << "A" << " " << random_x << std::endl;
            }

            else if (random_operation == dequeue) {
                std::cout << "D" << std::endl;
            }

            else if (random_operation == size) {
                std::cout << "S" << std::endl;
            }
        }
    }
    return 0;
}