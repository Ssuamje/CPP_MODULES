#include <iostream>
#include <Array.hpp>

// #define MAX_VAL 750
#define MAX_VAL 5

void iterTemplateArray(Array<int> &array, int size, void (*f)(int&))
{
    for (int i = 0; i < size; i++)
        f(array[i]);
}

void iterIntArray(int* array, int size, void (*f)(int&))
{
    for (int i = 0; i < size; i++)
        f(array[i]);
}

void print(int& i)
{
    std::cout << i << " ";
}

void leaks() {
    system("leaks array");
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "*************************" << std::endl;
    iterTemplateArray(numbers, MAX_VAL, print);
    std::cout << std::endl;
    std::cout << "****must same as below***" << std::endl;
    iterIntArray(mirror, MAX_VAL, print);
    std::cout << std::endl;
    std::cout << "*************************" << std::endl;
    std::cout << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "*************************" << std::endl;
        iterTemplateArray(tmp, MAX_VAL, print);
        std::cout << std::endl;
        std::cout << "****must same as below***" << std::endl;
        iterTemplateArray(test, MAX_VAL, print);
        std::cout << std::endl;
        std::cout << "*************************" << std::endl;
    }
    std::cout << "*********scope end**********" << std::endl;
    std::cout << std::endl;

    std::cout << "*compare to mirror and numbers*" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "********done**********" << std::endl;
    std::cout << std::endl;

    std::cout << "********exception**********" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "********done**********" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "*************************" << std::endl;
    iterTemplateArray(numbers, MAX_VAL, print);
    std::cout << std::endl;
    std::cout << "*************************" << std::endl;

    delete [] mirror;//
    // atexit(leaks);
    return 0;
}