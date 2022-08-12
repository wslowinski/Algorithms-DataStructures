#include "Dict.h"

#include <fstream>
#include <sstream>
#include <vector>

constexpr int MAX = 1000000;

int main(int argc, char *argv[]) {
    std::vector<int> v;

    Dict dict(MAX);
    std::string path(argv[1]);
    std::ifstream words(path);
    std::string line;
    while (getline(words, line)) {
        std::istringstream st(line);
        std::string key, value;
        while (st >> key >> value) {
            dict.insert(std::make_pair(key, value));
            v.push_back(dict.hash_function(key));
        }
    }
    words.close();
    std::string input;
    while (std::cin >> input) {
        if (dict.find(input)) {
            std::cout << dict[input] << std::endl;
        }
        else {
            std::cout << "-" << std::endl;
        }
    }
    return 0;
}
