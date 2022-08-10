#include <iostream>
#include <chrono>
#include <vector>

template<class T>
void swap(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
}

template<class T>
int min(std::vector<T>& v, int idx) {
    int minIdx = idx;
    for (int i = idx; i < v.size(); i++) {
        if (v[i] < v[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

template<class T>
void sort(std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        swap(&v[min(v, i)], &v[i]);
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