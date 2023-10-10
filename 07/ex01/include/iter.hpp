#include <iostream>

template <typename T>
void iter(const T *array, size_t length, void (*f)(const T &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(T const &t)
{
    std::cout << t << " ";
}