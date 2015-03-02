#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int funk(char);

int main() {
    srand(static_cast<unsigned long>(std::time(0)));
    std::cout << funk('B') << std::endl;
    std::cout << funk('I') << std::endl;
    std::cout << funk('N') << std::endl;
    std::cout << funk('G') << std::endl;
    std::cout << funk('O') << std::endl;
    std::cout << funk('Z') << std::endl;
    return 0;
}

int funk(char a) {
    int rand = std::rand() % 15 + 1;
    switch(a) {
        case 'B':
            return rand;
        case 'I':
            return rand + 15;
        case 'N':
            return rand + 30;
        case 'G':
            return rand + 45;
        case 'O':
            return rand + 60;
        default:
            return 0;
    }
}

