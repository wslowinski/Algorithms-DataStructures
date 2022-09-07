#include <iostream>
#include <chrono>
#include <vector>

template<class T>
void sort(std::vector<T>& v) {
    int index, var;
    for (int i = 1; i < v.size(); i++) {
        var = v[i];
        index = i - 1;
        while (var < v[index] && index >= 0) {
            v[index + 1] = v[index];
            index -= 1;
        }
        v[index + 1] = var;
    }
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }
}

int main() {
    int x;
    std::vector<int> v;
    while(std::cin >> x) {
        v.push_back(x);
    }
    auto start = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << v.size() << "\t" << elapsed.count() << std::endl;
    return 0;
}