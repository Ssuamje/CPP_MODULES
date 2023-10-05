#include "iter.hpp"

void print_int(int const &i) {
    std::cout << i << " ";
}

int main() {
    int intArray[5] = {1, 2, 3, 4, 5};

    std::cout << "intArray before iter: ";
    for (int i = 0; i < 5; i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    ::iter(intArray, 5, print_int);
    return 0;
}