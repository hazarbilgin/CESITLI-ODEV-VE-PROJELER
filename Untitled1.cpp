#include <iostream>

int x = 5;

void foo() {
    std::cout << x << std::endl;
}

void bar(void (*func)()) {
    int x = 10;
    func();
}

int main() {
    bar(foo);

    return 0;
}
