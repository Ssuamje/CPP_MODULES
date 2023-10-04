#include "ScalarConverter.hpp"

void leaks() {
    system("leaks convert");
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./convert [Numeric]" << std::endl;
        return (EXIT_FAILURE);
    }
    ScalarConverter::convert(av[1]);

    // atexit(leaks);
    return 0;
}