//TODO!!!
//TODO!!!
//TODO!!!
//TODO!!!
/*           CSV파일 지우기              */
//TODO!!!
//TODO!!!
//TODO!!!
//TODO!!!

#include "BitcoinExchange.hpp"

void leaks() {
    system("leaks btc");
}

int main(int ac, char** av) {
    // atexit(leaks);
    if (ac != 2) {
        std::cout << "Usage: ./btc [path_to_file]" << std::endl;
        return (1);
    }
    BitcoinExchange be = BitcoinExchange();
    be.readCsv(BitcoinExchange::DEFAULT_FILE_DIRECTORY);
    be.readArgumentFile(av[1]);

    return 0;
}