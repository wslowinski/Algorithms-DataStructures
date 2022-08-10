#include <iostream>
#include <vector>
#include <chrono>

template<class T>
std::pair<bool, int> lessThen(T x, T y, int counter) {
    return std::make_pair(x < y, counter);
}

template<class T>
void swap(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
} 

template<class T>
void sort(std::vector<T>& v) {
    int i, j, counter = 0;
    std::pair<bool, int> p;
    for  (i = 0; i < v.size() - 1; i++) {
        for (j = v.size() - 1; j > i; j--) {
            p = lessThen(v[j], v[j - 1], counter++);
            if (p.first) {
                swap(&v[j], &v[j - 1]);
            }
        }
    }
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }
    std::cerr << "\nNumber of dominant operations: " << p.second + 1 << std::endl;
}

int main() {
    int x;
    std::vector<int> v;
    while (std::cin >> x) {
        v.push_back(x);
    }
    auto start = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << v.size() << "\t" << elapsed.count() << std::endl;
    return 0;
}