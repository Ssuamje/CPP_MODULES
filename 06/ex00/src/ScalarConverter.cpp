#include <iostream>

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "\x1b[33m""[ScalarConverter]: default constructor has called!""\x1b[0m" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[ScalarConverter]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "\x1b[31m""[ScalarConverter]: destructor has called!""\x1b[0m" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &ref) {
    if (this != &ref) {
        std::cout << "\x1b[34m""[ScalarConverter]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[ScalarConverter]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

//header
bool isNan(std::string input) {
    if (input == "nan" || input == "nanf")
        return (true);
    return (false);
}

bool isInf(std::string input) {
    if (input == "inf" || input == "inff")
        return (true);
    return (false);
}

bool isAvailablePseudoLiteral(std::string input) {
    if (input == "nan" || input == "nanf"
    || input == "inf" || input == "inff"
    || input == "+inf" || input == "+inff"
    || input == "-inf" || input == "-inff")
        return (true);
    return (false);
}

bool isSigned(std::string input) {
    if (input[0] == '-' || input[0] == '+')
        return (true);
    return (false);
}

bool isPrintable(char c) {
    if (32 <= c && c <= 126)
        return (true);
    return (false);
}

bool isNotEmptyAndStartsWithConvertable(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isNotEmptyAndStartsWithConvertable function has called!""\x1b[0m" << std::endl;
    if (input.size() > 0 && (
        std::isdigit(input[0]) || isSigned(input) || isPrintable(input[0])))
        return (true);
    return (false);
}

bool isSignedMoreThanOnce(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isSignedMoreThanOnce function has called!""\x1b[0m" << std::endl;
    unsigned int signCount = 0;

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '-' || input[i] == '+')
            signCount++;
    }
    return (signCount > 1);
}

bool isDottedCorrectly(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isDottedCorrectly function has called!""\x1b[0m" << std::endl;
    int dotCount = 0;
    std::string det = input;

    if (isSigned(input))
        det.erase(0, 1);
    for (size_t i = 0; i < det.size(); i++) {
        if ((i == 0 || i == det.size() - 1) 
        && det[i] == '.')
            return (false);
        else if (det[i] == '.')
            dotCount++;
    }
    return (dotCount == 0 || dotCount == 1);
}

bool isEndsWithFOrNumber(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isEndsWithFOrNumber function has called!""\x1b[0m" << std::endl;
    if ((input.length() == 1 && isPrintable(input[0]))
    || input[input.size() - 1] == 'f'
    || input[input.size() - 1] == 'F'
    || std::isdigit(input[input.size() - 1]))
        return (true);
    return (false);
}

bool isStartsWithAlphabetAndEndsWithNumeric(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isStartsWithPrintableAndEndsWithOther function has called!""\x1b[0m" << std::endl;
    if ((('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z'))
    && std::isdigit(input[input.size() - 1]))
        return (true);
    return (false);
}

bool isPrintableChar(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: isChar function has called!""\x1b[0m" << std::endl;
    if (input.length() == 1 && isPrintable(input[0]))
        return (true);
    return (false);
}

double ScalarConverter::stringToDouble(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: stringToDouble function has called!""\x1b[0m" << std::endl;

    std::string det = input;
    double value;
    char *end = NULL;

    std::cout << "det = " << det << std::endl;
    if (isAvailablePseudoLiteral(det) || 
    (isNotEmptyAndStartsWithConvertable(det) 
    && !isSignedMoreThanOnce(det)
    && isDottedCorrectly(det)
    && isEndsWithFOrNumber(det)
    && !isStartsWithAlphabetAndEndsWithNumeric(det))
    ) {
        if (isPrintableChar(det))
            value = static_cast<double>(det[0]);
        else
            value = std::strtod(det.c_str(), &end);
    }
    else throw IllegalArgumentException();

    return (value);
}

void ScalarConverter::convert(std::string input) {
    std::cout << "\x1b[32m""[ScalarConverter]: convert function has called!""\x1b[0m" << std::endl;
    double value;

    value = stringToDouble(input);
    std::cout << "value = " << value << std::endl;
}

const char* ScalarConverter::IllegalArgumentException::what() const throw() {
    return ("illegal argument");
}

const char* ScalarConverter::ImpossibleConversionException::what() const throw() {
    return ("impossible");
}

const char* ScalarConverter::NonDisplayableInputException::what() const throw() {
    return ("Non displayable");
}
