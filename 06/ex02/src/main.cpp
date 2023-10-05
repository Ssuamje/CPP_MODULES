#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base base = Base();
    Base *instance = base.generate();
    Base &ref = *instance;
    
    base.identify(*instance);
    base.identify(ref);
    
    delete instance;
    return (0);
}