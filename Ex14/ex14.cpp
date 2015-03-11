#include <iostream>

/* Exercise 14
 * Lee Mracek
 * GNU Compiler Collection
 */

void addTo(int &x, int add=5);
void print(int &x);

int main() {
    int x = 1;
    addTo(x,3);
    print(x);
    addTo(x, 7);
    print(x);
    addTo(x);
    print(x);
    addTo(x,x);
    print(x);
    return 0;
}

void addTo(int &x, int add) {
    x+=add;
}

void print(int &x) {
    std::cout << x << std::endl;
}
