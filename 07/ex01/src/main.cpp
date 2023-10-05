#include "iter.hpp"

void print_int(int const &i) {
    std::cout << i << " ";
}

int main() {
    int int_array[5] = {1, 2, 3, 4, 5};

    std::cout << "int_array before iter: ";
    for (int i = 0; i < 5; i++)
        std::cout << int_array[i] << " ";
    std::cout << std::endl;

    ::iter(int_array, 5, print_int);
    return 0;
}