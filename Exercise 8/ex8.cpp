#include <iostream>
#include <cstdlib>

/*
 * Lee Mracek
 * Exercise 8
 * Bundled GCC (CLion IDE)
 */

int rollDice();
int addTwoRolls();

int main() {
    srand(time(0));

    for(short i = 0; i < 5; ++i)
        std::cout << addTwoRolls() << std::endl;
}

int addTwoRolls() {
    return rollDice() + rollDice();
}

int rollDice() {
    return std::rand() % 5 + 1;
}
