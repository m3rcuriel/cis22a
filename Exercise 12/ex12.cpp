#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>

/*
 * Lee Mracek
 * Exercise 12
 * GNU Compiler Collection
 */

void seperate(const std::string& in, std::vector<std::string>& tokens, const std::string& delim = " ");

int main() {
    std::ifstream data("data.txt", std::ios::in); // open aptly named data file
    if(!data.is_open()) { // check if file opened properly
        std::cout << "File did not open successfully!";
        return -1;
    }

    double average; // initialize double to store the incremental average
    std::string line; // initialize string to store each line
    std::vector<std::string> split; // initialize vector to store the components of each line
    double counter = 0; // counter for incremental average

    while(data) {
        counter++;
        getline(data, line);
        seperate(line, split); // splits line based on delim (default is " ")
        if(split.size() != 0) { // discard some problems (checking for EOF is another header)
            average += (atoi(split.at(10).c_str()) - average) / counter; // incrementally calculate the average
            split.clear(); // clear the vector
        }
    }
    std::cout << "The average final grade is "
            << std::setw(10) << std::setfill('0') << std::fixed << std::setprecision(6) << average << std::endl;
    return 0;
}

void seperate(const std::string& in, std::vector<std::string>& tokens, const std::string& delim) {
    std::string::size_type last = in.find_first_not_of(delim, 0); // discard any delim at the beginning
    std::string::size_type position = in.find_first_of(delim, last); // find first non delim

    while (std::string::npos != position || std::string::npos != last) {
        tokens.push_back(in.substr(last, position - last));
        last = in.find_first_not_of(delim, position); // start from position
        position = in.find_first_of(delim, last); // start from end of substring
    }
}
