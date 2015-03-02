#include <iostream>
#include <ctime>

/*
 * Lee Mracek
 * Exercise 7
 * GNU Compiler Collection(from CLion EAP)
 */

int main() {
    using std::cout;

    srand(static_cast<unsigned>(time(0)));

    int number = rand() % 9 + 1;

    cout << number << " ";

    switch (number) {
        case 1:
            cout << "one";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        default:
            cout << "some other number";
    }

    cout << std::endl;
    return 0;
}