#include <iostream>
#include <iomanip>
#include <cmath>

/*
 * Lee Mracek
 * Assignment 4
 * Bundled GCC (CLion IDE)
 */

// prints letter grade and returns message based on percentage
std::string printLetterGrade(short percent) {
    using std::cout;
    switch(static_cast<int>(floor(percent / 10))) { // switch statement to catch letter grades (using 10s digit)
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "F";
            return "You better try again";
        case 6:
            cout << "D";
            return "You better try again";
        case 7:
            cout << "C";
            return "Not bad!";
        case 8:
            cout << "B";
            return "Not bad!";
        case 10:
        case 9:
            cout << "A";
            return "Excellent work";
        default: // should not happen
            cout << "Error";
            return "Error";
    }
}

int main() {
    using std::cout;
    using std::cin;

    const unsigned short total = 400;

    unsigned short points[8]; // array ("list" of variables)
    unsigned short lab;
    unsigned short midterm;
    unsigned short final;

    for(short i = 1; i <= 8; ++i) { // loops through 8 times and gets assignments 1 - 8
        cout << "Enter assignment " << i << " points ";
        cin >> points[i - 1]; // arrays are 0 indexed
    }

    cout << "Enter lab exercise points ";
    cin >> lab;

    cout << "Enter midterm points ";
    cin >> midterm;

    cout << "Enter final points ";
    cin >> final;

    cout << "Assignment Grades:";
    unsigned short sum  = 0;
    unsigned short lowest = points[0];
    for(short i = 0; i < 8; ++i) { // iterates through the 8 assignents
        unsigned short point = points[i]; // gets each assignment point value
        if (point < lowest && i != 7) lowest = point; // sets the lowest assignment if it's less than current lowest
        sum += point; // sums the point values
        cout << std::setw(5) << point;
    }

    sum -= lowest; // removes the lowest score
    cout << std::endl;

    cout << std::left << std::setw(19) << "Assignment Points:" << sum << "\n";
    cout << std::setw(19) << "Lab Exercise:" << lab << "\n";
    cout << std::setw(19) << "Midterm:" << midterm << "\n";
    cout << std::setw(19) << "Final:" << final << "\n";
    cout << std::setw(19) << "Total Points:" << sum + lab + midterm + final << "\n";
    unsigned short percent = static_cast<unsigned short>(round(static_cast<float>(sum + lab + midterm + final) / total * 100));
    cout << std::setw(19) << "Percent of total: " << percent << "%\n";

    cout << "Grade: ";

    std::string message = printLetterGrade(percent); // reference above

    if((percent % 10) == 9 || (percent % 10) == 8 || percent >= 100) {
        cout << "+";
    } else if(percent % 10 == 1 || percent % 10 == 0) {
        cout << "-";
    }

    cout << "\n";
    cout << message << std::endl;

    return 0;
}