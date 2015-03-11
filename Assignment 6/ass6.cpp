#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <iostream>

void seperate(const std::string&, std::vector<std::string>&, const std::string& delim = " ");
int total(std::vector<int>&);
int lowest(std::vector<int>&);
char grade(int total, int (&counter)[5]);
char letter(int total);

const int MIDTERM = 9;                  // These used to be #define directives
const int ASSIGN_START = 1;             // But then I thought to Google it
const int ASSIGN_END = 8;               // and realized that it's very much
const int FINAL = 10;                   // my old C programmer showing
const int LAB = 11;                     // And now I can yell at my friend
const int ID = 0;                       // who uses them all the time.

int main() {
    std::ifstream input("ass6data.txt", std::ios::in);
    std::ofstream output("ass6out.txt", std::ios::out | std::ios::trunc);
    std::ofstream summary("ass6sum.txt", std::ios::out | std::ios::trunc);
    if (!input.is_open() || !output.is_open() || !summary.is_open()) {
        std::cerr << "Failed to load file" << std::endl;
        exit(-1);
    }

    int average = 0;
    int counter = 0;
    int grade_counter[5] = {0, 0, 0, 0, 0};

    output << std::left;
    output << std::setw(9) << "Student" << std::setw(24) << "--- Asignment Grades --";
    output << std::setw(4) << "Ass" << std::setw(4) << "Mid" << std::setw(4) << "Fin" << std::setw(4) << "LEx";
    output << std::setw(6) << "Total" << std::setw(4) << "Pct" << std::setw(2) << "Gr" << std::endl;

    output << std::right << std::setfill('-') << std::setw(9) << " ";
    for(int i = 0; i < 8; i++)
        output << std::setw(3) << " ";
    for(int i = 0; i < 4; i++)
        output << std::setw(4) << " ";
    output << std::setw(6) << " ";
    output << std::setw(4) << " ";
    output << std::setw(3) << " ";

    output << std::endl << std::setfill(' ');

    std::string line;
    std::vector<std::string> split;
    std::vector<int> assignments;

    while(input) {
        counter++;

        getline(input, line);
        seperate(line, split);

        if(split.size() != 0) {
            std::string id = split.at(ID);
            for(std::vector<int>::size_type i = ASSIGN_START; i <= ASSIGN_END; i++)
                assignments.push_back(atoi(split.at(i).c_str()));

            int asstotal = total(assignments);
            asstotal -= lowest(assignments);

            int midterm = atoi(split.at(MIDTERM).c_str());
            int lab = atoi(split.at(LAB).c_str());
            int final = atoi(split.at(FINAL).c_str());

            int total = asstotal + lab + final + midterm;

            average += (total - average) / counter; // calculate average incrementally

            output << std::left << std::setw(9) << id;
            for(int assignment : assignments)
                output << std::setw(3) << assignment;
            output << std::setw(4) << asstotal;
            output << std::right << std::setw(3) << midterm << std::right << std::setfill(' ') << std::setw(4) << final;
            output << std::right << std::setw(4) << lab << std::setw(6) << total;
            output << std::setw(4) << static_cast<int>(round(total / 4.));
            output << " ";
            output << grade(total, grade_counter);
            output << letter(total);
        }
        output << std::endl;
        split.clear();
        assignments.clear();
    }

    summary << "The average total points = " << average << std::endl;
    summary << "The average percent total = " << std::fixed << std::setprecision(0) << round(average / 4.) << std::endl;
    summary << std::setfill('0') << std::right;
    summary << "Number of A's = " << std::setw(2) << grade_counter[0] << std::endl;
    summary << "Number of B's = " << std::setw(2) << grade_counter[1] << std::endl;
    summary << "Number of C's = " << std::setw(2) << grade_counter[2] << std::endl;
    summary << "Number of D's = " << std::setw(2) << grade_counter[3] << std::endl;
    summary << "Number of F's = " << std::setw(2) << grade_counter[4] << std::endl;
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

int total(std::vector<int>& sum) {
    int total = 0;
    for(int i : sum) {
        total += i;
    }
    return total;
}

int lowest(std::vector<int>& list) {
    return *std::min_element(list.begin(), list.end());
}

char grade(int total, int (&counter)[5]) {
    switch(static_cast<int>(round((total / 4.)) / 10)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            counter[4]++;
            return 'F';
        case 6:
            counter[3]++;
            return 'D';
        case 7:
            counter[2]++;
            return 'C';
        case 8:
            counter[1]++;
            return 'B';
        case 9:
        case 10:
            counter[0]++;
            return 'A';
        default:
            return 'E';
    }
}

char letter(int total) {
    int percent = static_cast<int>(round(total / 4.));
    if(percent >= 55) { // no need to add more below 58% - F range
        if(percent % 10 == 9 || percent % 10 == 8 || percent >= 100)
            return '+';
        else if(percent % 10 == 1 || percent % 10 == 0)
            return '-';
    }
    return '\0';
}
