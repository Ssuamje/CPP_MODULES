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

bool ScalarConverter::isNan(std::string input) {
    return (input == "nan" || input == "nanf");
}

bool ScalarConverter::isInf(std::string input) {
    return (input == "inf" || input == "inff");
}

bool ScalarConverter::isAvailablePseudoLiteral(std::string input) {
    return (input == "nan" || input == "nanf"
    || input == "inf" || input == "inff"
    || input == "+inf" || input == "+inff"
    || input == "-inf" || input == "-inff");
}

bool ScalarConverter::isSigned(std::string input) {
    return (input[0] == '-' || input[0] == '+');
}

bool ScalarConverter::isPrintable(char c) {
    return (32 <= c && c <= 126);
}

bool ScalarConverter::isAscii(char c) {
    return (0 <= c && c <= 127);
}

bool ScalarConverter::isNotEmptyAndStartsWithConvertable(std::string input) {
    return (input.size() > 0 && 
    (std::isdigit(input[0]) || isSigned(input) || isAscii(input[0])));
}

bool ScalarConverter::isSignedMoreThanOnce(std::string input) {
    int signCount = 0;

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '-' || input[i] == '+')
            signCount++;
    }
    return (signCount > 1);
}

bool ScalarConverter::isDottedCorrectly(std::string input) {
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

bool ScalarConverter::isEndsWithFOrNumber(std::string input) {
    return ((input.length() == 1 && (isAscii(input[0])))
    || (isSigned(input) && isAvailablePseudoLiteral(input.substr(1, input.size() - 1)))
    || input[input.size() - 1] == 'f'
    || input[input.size() - 1] == 'F'
    || std::isdigit(input[input.size() - 1]));
}

bool ScalarConverter::isStartsWithAlphabetAndEndsWithNumeric(std::string input) {
    return ((('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z'))
        && std::isdigit(input[input.size() - 1]));
}

double ScalarConverter::stringToDouble(std::string input) {
    std::string det = input;
    double value;
    char *end = NULL;

    if (isAvailablePseudoLiteral(det) || 
    (isNotEmptyAndStartsWithConvertable(det) 
    && !isSignedMoreThanOnce(det)
    && isDottedCorrectly(det)
    && isEndsWithFOrNumber(det)
    && !isStartsWithAlphabetAndEndsWithNumeric(det))
    ) {
        if (input.length() == 1 && !std::isdigit(det[0]))
            value = static_cast<double>(det[0]);
        else
            value = std::strtod(det.c_str(), &end);
    }
    else throw IllegalArgumentException();

    return (value);
}

void ScalarConverter::putAsChar(double value) {
    if (std::isnan(value) || std::isinf(value)
    || (value < 0 
        || value > std::numeric_limits<char>::max()))
        std::cout << "char: impossible" << std::endl;
    else if (!isPrintable(value))
        std::cout << "char: Non Displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::putAsInt(double value) {
    if (std::isnan(value) || std::isinf(value)
    || (value < std::numeric_limits<int>::min() 
        || value > std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::putAsFloat(double value) {
    if (std::isnan(value) || std::isinf(value))
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else if (value < -__FLT_MAX__|| value > __FLT_MAX__)
        std::cout << "float: impossible" << std::endl;
    else if (value == static_cast<int>(value))
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::putAsDouble(double value) {
    if (std::isnan(value) || std::isinf(value))
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    else if (value < -__DBL_MAX__ || value > __DBL_MAX__)
        std::cout << "double: impossible" << std::endl;
    else if (value == static_cast<int>(value))
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string input) {
    double value;

    value = stringToDouble(input);
    putAsChar(value);
    putAsInt(value);
    putAsFloat(value);
    putAsDouble(value);
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
