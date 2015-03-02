#include <iostream>

/*
 * Lee Mracek
 * Exercise 6
 * GNU Compiler Collection (from Arch Official Repositories)
 */

int main() {
    using std::cin;
    using std::cout;

    int input [2]; 

    cout << "Enter an odd number => ";
    cin >> input[0];

    if(input[0] % 2 == 1) 
        cout << "Thank you very much" << std::endl;
    else {
        cout << "Enter an odd number => ";
        cin >> input[1];
        
        if(input[1] % 2 == 1)
            cout << "Thanks" << std::endl;
        else
            cout << "You dummy!" << std::endl;
    }
    return 0;
}
