#include <iostream>
#include <vector>
#include <chrono>

template<class T>
void swap(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
} 

template<class T>
void sort(std::vector<T>& v) {
    int i, j;
    for  (i = 0; i < v.size() - 1; i++) {
        for (j = v.size() - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                swap(&v[j], &v[j - 1]);
            }
        }
    }
    for(const auto& i : v) {
        std::cout << i << std::endl;
    }
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