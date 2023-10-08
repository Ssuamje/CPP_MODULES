#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {
    private:

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        ~PmergeMe();

        PmergeMe&	operator=(const PmergeMe& ref);

        std::string* split(std::string str, std::string delimiter);
        int     countSplitted(std::string* splitted);
        bool    isInCharset(std::string str, std::string charset);
        bool    isPositiveNumeric(std::string str);
        bool    isIntRanged(std::string str);
        void    checkArgs(int argc, char** argv);
        void    doMerge(int argc, char** argv);
        void    sort();
        void    print();
};

#endif
