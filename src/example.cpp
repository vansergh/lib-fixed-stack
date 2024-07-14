#include <iostream>
#include "../lib/fixed_stack.hpp"

int main() {
    FixedStack<int> a(5);
    std::cout << "==============================\n";
    a.Push(5);
    std::cout << a.Top() << std::endl;
    a.Push(7);
    std::cout << a.Top() << std::endl;
    a.Push(12);
    std::cout << a.Top() << std::endl;
    a.Pop();
    std::cout << a.Top() << std::endl;
    return 0;
}