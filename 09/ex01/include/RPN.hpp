#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<double>    operandStack;

    public:
        RPN();
        RPN(const RPN& ref);
        ~RPN();

        RPN&	operator=(const RPN& ref);

        // Parsing
        std::string* split(std::string str, std::string delimiter);
        int     countSplitted(std::string* splitted);
        bool    isInCharset(std::string str, std::string charset);
        bool    isOperands(std::string str);
        bool    isOperator(std::string str);
        void    checkTokens(std::string* tokens);
        bool    isValidToken(std::string str);

        void    doPostfixCalculate(std::string argument);
};

#endif
