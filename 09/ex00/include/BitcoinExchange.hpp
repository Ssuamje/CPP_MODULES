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

        void   readCsv(std::string filename);

        class FileOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidDataException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif
