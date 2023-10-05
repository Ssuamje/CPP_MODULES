#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
    private:
        T* store;
        unsigned int _size;

    public:
        Array() {
            std::cout << "Array default constructor called" << std::endl;
            this->store = new T[0];
            this->_size = 0;
        };
        Array(const Array& ref) {
            std::cout << "Array copy constructor called" << std::endl;
            this->store = new T[ref._size];
            this->_size = ref._size;
            for (unsigned int i = 0; i < ref._size; i++)
                this->store[i] = ref.store[i];
        };
        Array(unsigned int n) {
            std::cout << "Array constructor called" << std::endl;
            this->store = new T[n];
            this->_size = n;
        };
        ~Array() {
            std::cout << "Array destructor called" << std::endl;
            delete[] this->store;
        };

        Array&	operator=(const Array& ref) {
            std::cout << "Array assignation operator called" << std::endl;
            if (this == &ref)
                return *this;
            delete[] this->store;
            this->store = new T[ref._size];
            this->_size = ref._size;
            for (unsigned int i = 0; i < ref._size; i++)
                this->store[i] = ref.store[i];
            return *this;
        };

        T&  operator[](unsigned int i) {
            if (i >= this->_size)
                throw OutOfBoundsException();
            return this->store[i];
        };

        unsigned int size() const {
            return this->_size;
        };

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Out of bounds";
                };
        };
};

#endif
