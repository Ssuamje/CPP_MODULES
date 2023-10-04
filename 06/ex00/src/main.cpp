#include "ScalarConverter.hpp"

void leaks() {
    system("leaks convert");
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./convert [Numeric]" << std::endl;
        // std::cout << av[0] << std::endl;
        return (EXIT_FAILURE);
    }
    try {
        // std::string unprintable;
        // unprintable += static_cast<char>(7);
        ScalarConverter::convert(av[1]);
    } catch (std::exception &e) {
        std::cout << "\x1b[31m""[ScalarConverter] : Can't execute because of " << e.what() << std::endl;
        return(EXIT_FAILURE);
    }

    // atexit(leaks);
    return EXIT_SUCCESS;
}