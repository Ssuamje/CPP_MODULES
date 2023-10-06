#include "../include/BitcoinExchange.hpp"

const std::string BitcoinExchange::DEFAULT_FILE_DIRECTORY = "./data.csv";

BitcoinExchange::BitcoinExchange() {
    std::cout << "\x1b[33m""[BitcoinExchange]: default constructor has called!""\x1b[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[BitcoinExchange]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "\x1b[31m""[BitcoinExchange]: destructor has called!""\x1b[0m" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[BitcoinExchange]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[BitcoinExchange]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

void	BitcoinExchange::readCSV(std::string directory) {
    std::cout << "directory : " << directory << std::endl;
    std::ifstream ifs;
    
    ifs.open(directory);
    if (!ifs.is_open())
        throw FileOpenException();
    std::string line;
    while (std::getline(ifs, line)) {
        std::cout << line << std::endl;
    }
    ifs.close();
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return ("[BitcoinExchange]: file open error!");
}

