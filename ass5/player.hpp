#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <array>

class Player { // class declaration
public: // public facing members
    struct turn { // struct for a single turn
    public:
        std::array<int, 2> roll; // std::array for rolls
        int result; // resultant score
        turn(std::array<int, 2> roll, int result) : result{result}, roll(roll) { } // constructor for score
    };
    std::string name; // name of the player
    int score = 0; // initializes score to 0
    std::vector<std::array<int, 2>> doTurn(); // defines doTurn function
    Player(std::string, int); // defines constructor
    static int rollSum(int, int); // defines rollSum() (static because independent of instance
    static int sum(std::vector<std::array<int, 2>>); // defines function to sum a rollset
private:
    int turnlength; // stores the turnlength
    turn roll(); // defines private function to rollSum
    int rollDice(); // defines private function to rollSum dice
};

#endif