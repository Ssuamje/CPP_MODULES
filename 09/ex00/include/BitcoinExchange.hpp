#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> data;

    public:
        const static std::string DEFAULT_FILE_DIRECTORY;
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& ref);
        ~BitcoinExchange();

        BitcoinExchange&	operator=(const BitcoinExchange& ref);

        void   readCsv(std::string directory);
        void   readArgumentFile(std::string directory);
        std::string* split(std::string str, std::string delimiter);
        bool    isInCharset(std::string str, std::string charset);
        bool    isFirstLineValid(std::string line, std::string delimiter);
        int     countSplitted(std::string* splitted);
        bool    isNumericChar(char c);
        void    checkDateFormatted(std::string line);
        void    checkFloatFormatted(std::string line);

        class FileOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidDataException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class IllegalValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif
