#include <iostream> // for std::cout, std::cin, std::endl
#include <cstring> // for std::string, std::strlen
#include <iomanip> // for std::setw, std::left, std::setprecision
#include <locale> // for std::locale;

/*
 * Lee Mracek
 * Assignment 2
 * GNU Compiler Collection (from Arch core repository)
 */

int main() {
    using std::cout;
    using std::cin;
    using std::setw;
    using std::left;

    // establish current locale to properly format output
    std::locale loc("");
    std::cout.imbue(loc);

    // initialize const std::string for repeated parts of prompt
    const std::string prompt = "Enter points for assignment ";
    const std::string close = " => ";

    // define assignment and exam variables
    double ass1, ass2, ass3, ass4, ass5, ass6, ass7, lab, mid, fin;

    // output the first 7 prompts and input to the first 7 assignment variables
    cout << prompt << 1 << close;
    cin >> ass1;
    cout << prompt << 2 << close;
    cin >> ass2;
    cout << prompt << 3 << close;
    cin >> ass3;
    cout << prompt << 4 << close;
    cin >> ass4;
    cout << prompt << 5 << close;
    cin >> ass5;
    cout << prompt << 6 << close;
    cin >> ass6;
    cout << prompt << 7 << close;
    cin >> ass7;

    // output and input irregular prompts
    cout << "Enter total points for lab exercises" << close;
    cin >> lab;
    cout << "Enter total points for midterm" << close;
    cin >> mid;
    cout << "Enter points for final" << close;
    cin >> fin;

    cout << "\n";

    // output total assignment points
    // NOTE: Chose not to use std;:setw because sample output looked like tab
    cout << "The assignment points are " << ass1 << "\t" << ass2 << "\t" << ass3 << "\t" << ass4 << "\t" << ass5 << "\t" << ass6 << "\t" << ass7 << "\n";

    cout << "\n";

    // initalize variable for the total assignment score
    double total = ass1 + ass2 + ass3 + ass4 + ass5 + ass6 + ass7;

    // set precision to match example output
    cout << std::setprecision(6) << "The average assignment grade is " << total/7 << "\n";

    cout << "\n";
    
    // calculate maximum necessary setw value
    int width = std::strlen("Total assignment points") + 1;

    // output final values using setw to align columns
    cout << left << setw(width) << "Total assignment points" << "= " << total << "\n";
    cout << setw(width) << "Lab exercise points" << "= " << lab << "\n";
    cout << setw(width) << "Midterm points" << "= " << mid << "\n";
    cout << setw(width) << "Final points" << "= " << fin << "\n";
    cout << setw(width + 2) << ""  << "---\n";
    cout << setw(width) << "Total points" << "= " << total + lab + mid + fin << "\n";

    cout << "\n";
    cout << std::setprecision(3) << setw(width) << "Percent of total" << "= " << (total + lab + mid + fin) / 4 << "%" << std::endl;

    return 0;
}
