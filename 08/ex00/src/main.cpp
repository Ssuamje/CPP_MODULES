#include "easyfind.hpp"

int main() {
    std::vector<int> v;

    for (size_t i = 0; i < 1000; i++) {
        v.push_back(i);
    }
    std::cout << "Found 42: " << *easyfind(v, 42) << "\n";
    std::cout << "Found 999: " << *easyfind(v, 999) << "\n";
    try {
        std::cout << "Found 1000: " << *easyfind(v, 1000) << "\n";
    } catch (std::exception &e) {
        std::cout << "not found" << std::endl;
    }

    return 0;
}