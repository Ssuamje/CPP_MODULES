#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

class BitcoinExchange {
    private:

    public:
        const static std::string DEFAULT_FILE_DIRECTORY;
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& ref);
        ~BitcoinExchange();

        BitcoinExchange&	operator=(const BitcoinExchange& ref);

        void   readCSV(std::string filename);

        class FileOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif
