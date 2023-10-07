#include <iostream>

#include "../include/RPN.hpp"

RPN::RPN() {
    std::cout << "\x1b[33m""[RPN]: default constructor has called!""\x1b[0m" << std::endl;
}

RPN::RPN(RPN const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[RPN]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

RPN::~RPN() {
    std::cout << "\x1b[31m""[RPN]: destructor has called!""\x1b[0m" << std::endl;
}

RPN&	RPN::operator=(RPN const &ref) {
    if (this != &ref) {
        this->operandStack = ref.operandStack;
        std::cout << "\x1b[34m""[RPN]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[RPN]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

// Parsing
std::string* RPN::split(std::string str, std::string delimiter) {
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

int     RPN::countSplitted(std::string* splitted) {
    int count = 0;
    while (splitted[count] != "")
        count++;
    return (count);
}

bool    RPN::isInCharset(std::string str, std::string charset) {
    for (size_t i = 0; i < str.length(); i++) {
        if (charset.find(str[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

bool    RPN::isOperands(std::string str) {
    if (str.length() == 1 && isInCharset(str, "0123456789"))
        return (true);
    return (false);
}

bool    RPN::isOperator(std::string str) {
    if (str.length() == 1 && isInCharset(str, "+-*/"))
        return (true);
    return (false);
}

bool    RPN::isValidToken(std::string str) {
    if (isOperands(str) || isOperator(str))
        return (true);
    return (false);
}

void    RPN::checkTokens(std::string* tokens) {
    int count = countSplitted(tokens);
    int operands = 0;
    int operators = 0;
    for (int i = 0; i < count; i++) {
        if (isOperands(tokens[i]))
            operands++;
        if (isOperator(tokens[i]))
            operators++;
        if (!isValidToken(tokens[i]))
            throw std::runtime_error("Invalid token!");
    }
    if (operands - operators != 1)
        throw std::runtime_error("Invalid number of operands and operators!");
}

void    RPN::doPostfixCalculate(std::string argument) {
    std::string* args = split(argument, " ");

    try {
        checkTokens(args);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return ;
    }

    int count = countSplitted(args);
    for (int i = 0; i < count; i++) {
        if (isOperands(args[i]))
            operandStack.push(std::strtod(args[i].c_str(), NULL));
        if (isOperator(args[i])) {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            if (args[i] == "+")
                operandStack.push(operand2 + operand1);
            if (args[i] == "-")
                operandStack.push(operand2 - operand1);
            if (args[i] == "*") 
                operandStack.push(operand2 * operand1);
            if (args[i] == "/") {
                if (operand1 == 0)
                    throw std::runtime_error("Division by zero!");
                operandStack.push(operand2 / operand1);
            }
        }
    }
    std::cout << "\x1b[35m""Result: " << operandStack.top() << "\x1b[0m" << std::endl;
    operandStack.pop();
    delete[] args;
}
