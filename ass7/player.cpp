#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Player::Player(std::string name, int turnlength = 3) : name{name}, turnlength{turnlength} {
        std::srand(time(0));
}

std::vector<std::array<int, 2> > Player::doTurn() {
    std::vector<std::array<int, 2> > rollset;

    turn playerturn = roll();
    rollset.clear();
    do {
        rollset.push_back(playerturn.roll);
        if(playerturn.result == -1) { score = 0; return rollset; }
        if(playerturn.result == 0) return rollset;
        score += playerturn.result;
        if(score >= 100) return rollset;
        playerturn = roll();
    } while(rollset.size() < static_cast<unsigned int>(turnlength) || turnlength == -1);

    return rollset;
}

void Player::clear() {
    score = 0;
}

Player::turn Player::roll() {
    std::array<int, 2> rolls = {rollDice(), rollDice()};
    return turn(rolls, rollSum(rolls[0], rolls[1]));
}

int Player::rollDice() {
    return rand() % 6 + 1;
}

int Player::rollSum(int one, int two) {
    return (one == 1) || (two == 1) ? (one == two) == 1 ? -1 : 0 : one + two;
}

int Player::sum(std::vector<std::array<int, 2> > rollset) {
    int total = 0;
    for(std::array<int, 2> roll : rollset) {
        int rollsum = Player::rollSum(roll.at(0), roll.at(1));
        if(rollsum == 0) return 0;
        total += rollsum;
    }
    return total;
}

