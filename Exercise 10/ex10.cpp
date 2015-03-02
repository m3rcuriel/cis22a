#include <iostream>
#include <string>

/*
 * Lee Mracek
 * Exercise 10
 * GCC (Bundled with CLion IDE)
 */

void print(int*);
std::string suffix(int);

int main() {
    int i = 1; // initializes counter
    while (i <= 10)
        print(&i); // prints the correct text for each number (pointer to i because I will not use curly braces dammit
    return 0;
}

void print(int *i) { // argument is pointer to int
    std::cout << "This is the " << *i << suffix(*i) << " iteration of the loop\n"; // properly formatted output string (gets value from pointer)
    (*i)++; // increments the i in main as a memory address
}

std::string suffix(int i) { // returns the proper suffix based on i
    switch(i) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
    i++;
}
