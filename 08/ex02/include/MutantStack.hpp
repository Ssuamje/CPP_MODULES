#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack() {
            std::cout << "MutantStack default constructor called" << std::endl;
        };
        MutantStack(const MutantStack& ref) {
            std::cout << "MutantStack copy constructor called" << std::endl;
            this->c = ref.c;
        };
        ~MutantStack() {
            std::cout << "MutantStack destructor called" << std::endl;
            this->c.clear();
        };

        MutantStack&	operator=(const MutantStack& ref) {
            this->c = ref.c;
            return *this;
        };

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};

        typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
        const_iterator begin() const {return this->c.cbegin();};
        const_iterator end() const {return this->c.cend();};

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {return this->c.rbegin();};
        reverse_iterator rend() {return this->c.rend();};

        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin() const {return this->c.crbegin();};
        const_reverse_iterator rend() const {return this->c.crend();};
};

#endif
