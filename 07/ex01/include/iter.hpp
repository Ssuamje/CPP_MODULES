#include <iostream>

template <typename T>
void iter(const T *array, size_t length, void (*f)(const T &))
{
    std::cout << "calling iter with const" << std::endl;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
    std::cout << "calling iter without const" << std::endl;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
