#include "MutantStack.hpp"
#include <list>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "mstack content : " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "mstack content end!" << std::endl;
    std::cout << std::endl;

    std::stack<int> s(mstack);
    std::cout << "mstack copied : " << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << std::endl;
    std::cout << "compare with mstack and list!" << std::endl;
    std::cout << std::endl;
    
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << "l back : " << l.back() << std::endl;
    l.pop_back();
    std::cout << "l size : " << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    //[...]
    l.push_back(0);
    
    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    ++lit;
    --lit;
    
    std::cout << "l content : " << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::cout << "l content end!" << std::endl;
    std::cout << std::endl;

    return 0;
}