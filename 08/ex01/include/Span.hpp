#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span {
    private:
        Span();
        unsigned int size;
        std::vector<int> store;

    public:
        Span(unsigned int n);
        Span(Span const &ref);
        ~Span(void);
    
        Span &operator=(Span const &ref);
    
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
    
        class NoSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
    
        class FullSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };    
};

#endif
