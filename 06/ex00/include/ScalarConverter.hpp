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

    public:
        static void convert(std::string input);
        
        class IllegalArgumentException: public std::exception {
            virtual const char* what() const throw();
        };
        class ImpossibleConversionException: public std::exception {
            virtual const char* what() const throw();
        };
        class NonDisplayableInputException: public std::exception {
            virtual const char* what() const throw();
        };

};

#endif
