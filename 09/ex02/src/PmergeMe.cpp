#include <iostream>

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "\x1b[33m""[PmergeMe]: default constructor has called!""\x1b[0m" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[PmergeMe]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

PmergeMe::~PmergeMe() {
    std::cout << "\x1b[31m""[PmergeMe]: destructor has called!""\x1b[0m" << std::endl;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[PmergeMe]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[PmergeMe]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string* PmergeMe::split(std::string str, std::string delimiter) {
    size_t count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == delimiter[0])
            count++;
    }
    if (count == 0)
        return (NULL);
    std::string* ret = new std::string[count + 2];
    ret[count + 1] = "";
    for (size_t i = 0; i < count; i++) {
        ret[i] = str.substr(0, str.find(delimiter));
        str = str.substr(str.find(delimiter) + 1);
    }
    ret[count] = str;
    return (ret);
}

int     PmergeMe::countSplitted(std::string* splitted) {
    int count = 0;
    while (splitted[count] != "")
        count++;
    return (count);
}

bool    PmergeMe::isInCharset(std::string str, std::string charset) {
    for (size_t i = 0; i < str.length(); i++) {
        if (charset.find(str[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

bool    PmergeMe::isIntRanged(std::string str) {
    if (str.length() == 0)
        return (false);
    if (str.length() > 10)
        return (false);
    if (str.length() == 10 && str > "2147483647")
        return (false);
    return (true);
}

bool    PmergeMe::isPositiveNumeric(std::string str) {
    if (str.length() == 0)
        return (false);
    if (str[0] == '-')
        return (false);
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

void    PmergeMe::checkArgs(int ac, char** av) {
    for (int i = 1; i < ac; i++) {
        std::string arg = av[i];
        if (arg.empty() || !isPositiveNumeric(arg) || !isIntRanged(arg))
            throw std::runtime_error("Invalid argument!");
    }
}
