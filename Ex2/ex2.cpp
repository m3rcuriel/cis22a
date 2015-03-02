#include <iostream>
#include <cstdlib>
#include <string>

/**
 * Lee Mracek
 * Lab Exercise 2
 * GNU Compiler Collection
 */

int main() {
    std::string name = "Lee Mracek";
    float age = 16.83;

    std::locale loc("");
    std::cout.imbue(loc);
    std::cout << "My name is " << name << " and my age is " << age << ".\n";
    return 0;
}
    
