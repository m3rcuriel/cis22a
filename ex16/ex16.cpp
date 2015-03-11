#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

/*
 * Lee Mracek
 * Exercise 16
 * GNU Compiler Collection
 */

void seperate(const std::string&, std::vector<std::string>&, const std::string&);
float sum(int data[]);

int main() {
    std::ifstream read("djidata.txt");
    if(!read.is_open()) {
        std::cerr << "File couldn't open" << std::endl;
        return -1;
    }

    int arr[50];
    std::string line;
    std::vector<std::string> line_split;
    int i = 0;

    while(read) {
        getline(read, line);
        seperate(line, line_split, " ");
        if(line_split.size() > 0)
            arr[i] = atoi(line_split.at(5).c_str());
        i++;
        line_split.clear();
    }
    std::cout << "Average => " << sum(arr) / 50. << std::endl;    
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

float sum(int data[]) {
    float total = 0;
    for(int i = 0; i < 50; i++)
        total += data[i];
    return total;
}
