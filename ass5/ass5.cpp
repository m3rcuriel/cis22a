#include <iostream>
#include "player.hpp"

/*
 * Lee Mracek
 * Assignment 5
 * GCC (Bundled with CLion IDEA)
 */
bool win(std::array<Player, 3>); // defines function to determine if someone won
// defines function to print and exit when a player wins
void printWin(Player* /*pass by reference - passes the location of the parameter*/);

int main() { // main function
    std::array<Player, 3> players = {Player("Harry", 1), Player("Mary", 7), Player("Larry", -1)}; // array of Players
    std::vector<std::array<int, 2>> rollset; // defines a rollset
    Player *winner = new Player("Error", -1);
    while(1) { // loop forever!
        for (int i = 0; i < players.size(); ++i) { // loop through players
            std::cout << players[i].name << ", it is your turn\n"; // print name of player
            rollset = players[i].doTurn(); // do turn of player
            for (int j = 0; j < rollset.size(); ++j) { // loop through returned rollset
                std::array<int, 2> roll = rollset.at(j); // define an array of rollSum values
                std::cout << "* You rolled " << roll.at(0) << " and " << roll.at(1)
                        << ". That's " << Player::rollSum(roll.at(0), roll.at(1)) << std::endl; // print rolls and sum
            }
            std::cout << "** Points for turn = " << Player::sum(rollset) << std::endl; // prints sum of turn
            std::cout << "*** Total points = " << players[i].score << std::endl; // prints total points of player
            std::cout << std::endl; // newline
            if(win(players)) { winner = &players[i]; break; } // tests if player won - if so, breaks loop and stores
        }
        if(winner->name != "Error") // checks if winner has been updated (this is so ugly)
            break; // breaks forever loop
    }
    printWin(winner); // prints winner based on reference to winner
}

void printWin(Player *player) {
    std::cout << player->name << " won the game with " << player->score << " points" << std::endl;
    exit(1);
}

bool win(std::array<Player, 3> players) {
    for(int i = 0; i < players.size(); ++i) // loops through players
        if(players[i].score >= 100) return true; // returns true if someone won
    return false;
}

