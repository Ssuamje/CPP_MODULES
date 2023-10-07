#include "../include/BitcoinExchange.hpp"

const std::string BitcoinExchange::DEFAULT_FILE_DIRECTORY = "./data.csv";

BitcoinExchange::BitcoinExchange() {
    this->data = std::map<std::string, double>();
    std::cout << "\x1b[33m""[BitcoinExchange]: default constructor has called!""\x1b[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) {
    std::cout << "\x1b[35m""[BitcoinExchange]: deep-copy constructor has called!""\x1b[0m" << std::endl;
    *this = ref;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "\x1b[31m""[BitcoinExchange]: destructor has called!""\x1b[0m" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &ref) {
    if (this != &ref) {
        std::cout << "\x1b[34m""[BitcoinExchange]: assign operator has called!""\x1b[0m" << std::endl;
        this->data = ref.data;
    }
    else
        std::cout << "\x1b[34m""[BitcoinExchange]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string* BitcoinExchange::split(std::string str, std::string delimiter) {
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

bool    BitcoinExchange::isInCharset(std::string str, std::string charset) {
    for (size_t i = 0; i < str.length(); i++) {
        if (charset.find(str[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

bool    BitcoinExchange::isFirstLineValid(std::string line, std::string delimiter) {
    std::string* splitted = split(line, delimiter);

    if (splitted == NULL || countSplitted(splitted) != 2)
        return (false);
    delete[] splitted;
    return (true);
}

int     BitcoinExchange::countSplitted(std::string* splitted) {
    int count = 0;

    while (splitted[count] != "") {
        count++;
    }
    return (count);
}

std::string BitcoinExchange::trimWhiteSpaces(std::string str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    while (str[start] == ' ')
        start++;
    while (str[end] == ' ')
        end--;
    return (str.substr(start, end - start + 1));
}

void    BitcoinExchange::checkDateFormatted(std::string line) {
    std::string* splitted = split(line, "-");
    if (splitted == NULL)
        throw BadInputException();
    if (countSplitted(splitted) != 3) {
        delete[] splitted;
        throw BadInputException();
    }
    if (!isInCharset(splitted[0], "0123456789")
    || !isInCharset(splitted[1], "0123456789")
    || !isInCharset(splitted[2], "0123456789")) {
        delete[] splitted;
        throw BadInputException();
    }
    if (splitted[0].length() != 4 || splitted[1].length() != 2 || splitted[2].length() != 2) {
        delete[] splitted;
        throw BadInputException();
    }

    long year = std::strtol(splitted[0].c_str(), NULL, 10);
    long month = std::strtol(splitted[1].c_str(), NULL, 10);
    long day = std::strtol(splitted[2].c_str(), NULL, 10);

    if (year < 2009
    || (month < 1 || month > 12)
    || (day < 1 || day > 31)) {
        delete[] splitted;
        throw BadInputException();
    }

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch (month) {
        case 2:
            if (isLeapYear && day > 29) {
                delete[] splitted;
                throw BadInputException();
            }
            else if (!isLeapYear && day > 28) {
                delete[] splitted;
                throw BadInputException();
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                delete[] splitted;
                throw BadInputException();
            }
            break;
        default:
            if (day > 31) {
                delete[] splitted;
                throw BadInputException();
            }
    }
    delete[] splitted;
}

bool    BitcoinExchange::isNumericChar(char c) {
    return ('0' <= c && c <= '9');
}

void    BitcoinExchange::checkFloatFormatted(std::string str) {
    if (!isInCharset(str, "0123456789.")
    ||  !isNumericChar(str[0])
    || !isNumericChar(str[str.length() - 1]))
        throw IllegalValueException();

    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == '.')
            count++;
    if (count > 1)
        throw IllegalValueException();
}

void	BitcoinExchange::readCsv(std::string directory) {
    std::ifstream ifs;

    ifs.open(directory);
    if (!ifs.is_open())
        throw FileOpenException();
    std::string line;
    std::getline(ifs, line);
    if (!isFirstLineValid(line, ","))
        throw InvalidDataException();
    while (std::getline(ifs, line)) {
        std::string* splitted = split(line, ",");
        if (splitted == NULL)
            throw InvalidDataException();
        std::string key = splitted[0];
        std::string value = splitted[1];
        if (countSplitted(splitted) != 2)
            throw InvalidDataException();
        try {
            checkDateFormatted(key);
            checkFloatFormatted(value);
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete[] splitted;
        this->data.insert(std::pair<std::string, double>(key, std::strtod(value.c_str(), NULL)));
    }
    ifs.close();
}

void    BitcoinExchange::checkIntRangedNumericFloat(std::string str) {
    double value = std::strtod(str.c_str(), NULL);
    if (value < 0 || value > INT_MAX)
        throw IllegalValueException();
}

void    BitcoinExchange::printDataByLowerBound(std::string key, std::string value) {
    std::map<std::string, double>::iterator it = this->data.lower_bound(key);
    if (it == this->data.begin())
        throw BadInputException();
    else if (it->first == key)
        std::cout << key << " => " << it->second << std::endl;
    else if (it == this->data.end())
        std::cout << "No data" << std::endl;
    else {
        double processedValue = (--it)->second * std::strtod(value.c_str(), NULL);
        std::cout << key << " => " << processedValue << std::endl;
    }
}

void    BitcoinExchange::readArgumentFile(std::string directory) {
    std::ifstream ifs;

    ifs.open(directory);
    if (!ifs.is_open())
        throw FileOpenException();
    std::string line;
    std::getline(ifs, line);
    if (!isFirstLineValid(line, "|"))
        throw InvalidDataException();

    while (std::getline(ifs, line)) {
        std::string* splitted = split(line, "|");
        try {
            if (splitted == NULL)
                throw BadInputException();
        } catch (const std::exception& e) {
            std::cerr << e.what() << "\"" << line << "\""  << std::endl;
            continue;
        }
        std::string key = trimWhiteSpaces(splitted[0]);
        std::string value = trimWhiteSpaces(splitted[1]);
        try {
            if (countSplitted(splitted) != 2)
                throw BadInputException();
            checkDateFormatted(key);
            checkFloatFormatted(value);
            checkIntRangedNumericFloat(value);
            printDataByLowerBound(key, value);
        } catch(const std::exception& e) {
            std::cerr << e.what() << "(key : " << "\"" << key << "\"" << ", value : " << "\"" << value << "\")" << std::endl;
        }
        delete[] splitted;
    }
    ifs.close();
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return ("[BitcoinExchange]: file open error!");
}

const char* BitcoinExchange::InvalidDataException::what() const throw() {
    return ("[BitcoinExchange]: data is invalid!");
}

const char* BitcoinExchange::BadInputException::what() const throw() {
    return ("[BitcoinExchange]: bad input => ");
}

const char* BitcoinExchange::IllegalValueException::what() const throw() {
    return ("[BitcoinExchange]: value is not valid!");
}
