#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
        ~ScalarConverter();

        ScalarConverter&	operator=(const ScalarConverter& ref);

        static double stringToDouble(std::string input);
        static bool isPrintable(char c);
        static bool isNan(std::string input);
        static bool isInf(std::string input);
        static bool isAvailablePseudoLiteral(std::string input);
        static bool isNotEmptyAndStartsWithConvertable(std::string input);
        static bool isSignedMoreThanOnce(std::string input);
        static bool isDottedCorrectly(std::string input);
        static bool isEndsWithFOrNumber(std::string input);
        static bool isStartsWithAlphabetAndEndsWithNumeric(std::string input);
        static bool isAscii(char c);
        static bool isSigned(std::string input);
        static void putAsChar(double value);
        static void putAsInt(double value);
        static void putAsFloat(double value);
        static void putAsDouble(double value);

    public:
        static void convert(std::string input);
        
        class IllegalArgumentException: public std::exception {
            virtual const char* what() const throw();
        };
};

#endif
