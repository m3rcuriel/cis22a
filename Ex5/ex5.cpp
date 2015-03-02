#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

/* Lee Mracek
 * Lab Exercise 5
 * GNU Compiler Collection
 */

int main() {

    std::srand(std::time(0));

    float a = std::rand();
    float b = log(a);
    float c = sqrt(a);

    std::cout << a << b << c << std::endl;

    std::cout << std::setw(10) << a << std::setw(10) << b << std::setw(10) << c << std::endl;

    std::cout << std::fixed << std::setprecision(2) << std::left << std::setw(10) << a << std::setw(10) << b << std::setw(10) << c << std::endl;

    return 0;
}
