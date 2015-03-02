#include <iostream> //for std::cout, std::cin, std::endl, std::streamsize (by C++11 standard)
#include <limits> //std::numeric_limits

/* Lee Mracek
 * Lab Exercise #4
 * GNU Compiler Collection (from Arch Linux core repository)
 */

int main() {
    
    double base, height;

    while(true) {
        std::cout << "Enter base and height => ";
        std::cin >> base >> height;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid floating point value for base and height (space delimited)" << std::endl;
            continue;
        }
        break;
    }
    std::cout << base * height * 1/2 << std::endl;


    return 0;
}
