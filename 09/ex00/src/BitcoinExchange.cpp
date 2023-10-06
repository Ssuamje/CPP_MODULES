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

std::string* split(std::string str, std::string delimiter) {
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

bool    isInCharset(std::string str, std::string charset) {
    for (size_t i = 0; i < str.length(); i++) {
        if (charset.find(str[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

bool    isFirstLineValid(std::string line) {
    std::string* splited = split(line, ",");
    if (splited == NULL)
        return (false);
    delete[] splited;
    return (true);
}

int     countSplitted(std::string* splitted) {
    int count = 0;
    while (!splitted[count].empty()) {
        count++;
    }
    return (count);
}

bool    isDateFormatted(std::string line) {
    std::string* splitted = split(line, "-");
    if (splitted == NULL)
        return (false);
    if (countSplitted(splitted) != 3) {
        delete[] splitted;
        return (false);
    }
    if (!isInCharset(splitted[0], "0123456789") 
    || !isInCharset(splitted[1], "0123456789") 
    || !isInCharset(splitted[2], "0123456789")) {
        delete[] splitted;
        return (false);
    }
    if (splitted[0].length() != 4 || splitted[1].length() != 2 || splitted[2].length() != 2) {
        delete[] splitted;
        return (false);
    }

    long year = std::strtol(splitted[0].c_str(), NULL, 10);
    long month = std::strtol(splitted[1].c_str(), NULL, 10);
    long day = std::strtol(splitted[2].c_str(), NULL, 10);

    if (year < 2009
    || (month < 1 || month > 12)
    || (day < 1 || day > 31)) {
        delete[] splitted;
        return (false);
    }

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch (month) {
        case 2:
            if (isLeapYear && day > 29) {
                delete[] splitted;
                return (false);
            }
            else if (!isLeapYear && day > 28) {
                delete[] splitted;
                return (false);
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                delete[] splitted;
                return (false);
            }
            break;
        default:
            if (day > 31) {
                delete[] splitted;
                return (false);
            }
    }

    delete[] splitted;
    return (true);
}

bool    isNumericChar(char c) {
    return ('0' <= c && c <= '9');
}

bool    isFloatFormatted(std::string str) {
    if (!isInCharset(str, "0123456789."))
        return (false);
    if (!isNumericChar(str[0]) || !isNumericChar(str[str.length() - 1]))
        return (false);
    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.')
            count++;
    }
    if (count > 1)
        return (false);
    return (true);
}

bool    isValidEntry(std::string* splitted) {
    std::string key = splitted[0];
    std::string value = splitted[1];
    return (isDateFormatted(key) && isFloatFormatted(value));
}

void	BitcoinExchange::readCsv(std::string directory) {
    std::ifstream ifs;
    
    ifs.open(directory);
    if (!ifs.is_open())
        throw FileOpenException();
    std::string line;
    std::getline(ifs, line);
    if (!isFirstLineValid(line))
        throw InvalidDataException();
    while (std::getline(ifs, line)) {
        std::string* splitted = split(line, ",");
        std::string key = splitted[0];
        std::string value = splitted[1];
        if (countSplitted(splitted) != 2
        ||  !isDateFormatted(key)
        ||  !isFloatFormatted(value))
            throw InvalidDataException();
        delete[] splitted;
        this->data.insert(std::pair<std::string, double>(key, std::strtod(value.c_str(), NULL)));
    }
    ifs.close();
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return ("[BitcoinExchange]: file open error!");
}

const char* BitcoinExchange::InvalidDataException::what() const throw() {
    return ("[BitcoinExchange]: data is invalid!");
}


//strcmp를 이용한 문자열 비교 후에 lower_bound를 이용해서 해당 근사 값을 찾아주자.