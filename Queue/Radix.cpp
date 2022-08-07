#include "LinkedQueue.h"

#include <vector>
#include <iostream>

void radix(std::vector<int> v) {
    constexpr int radix = 10;
    constexpr int digits = 10;

    int i, j, k;
    int factor;

    Queue queue[radix];
    
    for (i = 0, factor = 1; i < digits; factor *= radix, i++) {
        for (j = 0; j < v.size(); j++) {
            queue[(v[j] / factor) % radix].enqueue(v[j]);
        }
        for (j = k = 0; j < radix; j++) {
            while (!queue[j].empty())
            {
                v[k++] = queue[j].dequeue();
            }
        }
    }
    for (const auto &i: v) {
        std::cout << i << std::endl;
    }
}

int main() {
    int x;
    std::vector<int> input_data;
    while (std::cin >> x) {
        input_data.push_back(x);
    }
    radix(input_data);
    return 0;
}