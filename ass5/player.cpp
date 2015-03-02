#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Player::Player(std::string name, int turnlength = 3) // constructor for a player - name and turnlength. -1 goes forever.
: turnlength{turnlength}
, name{name}
{
    std::srand(time(0)); // seed random number generator. ignore cast because we really don't care
}

std::vector<std::array<int, 2>> Player::doTurn() { // main function of Player - does a turn
    std::vector<std::array<int, 2>> rollset; // initializes a vector of arrays to hold the rolls

    turn playerturn = roll(); // stores a rollSum into a struct
    rollset.clear(); // clears the vector
    do {
        rollset.push_back(playerturn.roll); // adds the rollSum to the rollset vector
        if(playerturn.result == 7) { score = 0; return rollset; }; // returns out and sets the score to 0 if 7
        score += playerturn.result; // adds the result to the score
        if(score >= 100) return rollset; // returns out if they win!
        playerturn = roll(); // stores another rollSum
    } while(rollset.size() < turnlength || turnlength == -1); // loops until enough rolls are done, or forever if -1
    return rollset; // returns the rolls if turnlength expires
}

Player::turn Player::roll() { // calculates a rollSum (two dice)
    std::array<int, 2> rolls = {rollDice(), rollDice()}; // creates an array to contain two rolls
    return turn(rolls, rolls[0] == rolls[1] ? 13 : rolls[0] + rolls[1]); // returns the rolls and total in a struct
}

int Player::rollSum(int one, int two) { // calculates the sum of a rollSum
    return one + two != 7 ? one == two ? 13 : one + two : 0; // returns the score from the rollSum based on rules
}
int Player::rollDice() { // returns a number from 1 to 6
    return rand() % 6 + 1, rand() % 6 + 1;
}

int Player::sum(std::vector<std::array<int, 2>> rollset) {
    int total = 0;
    for(std::array<int, 2> roll : rollset) {
        int rollsum = Player::rollSum(roll.at(0), roll.at(1));
        if(rollsum == 0) return 0;
        total += rollsum;
    }
    return total;
}
