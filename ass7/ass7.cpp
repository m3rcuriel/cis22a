#include <iostream>
#include "player.hpp"
#include <string>
#include <iomanip>
#include <fstream>

bool win(std::array<Player, 3>); // defines function to find a win
std::string printWin(Player*);

int main() {
    std::array<Player, 3> players = {Player("Harry", 1), Player("Mary", 3),
    Player("Larry", -1)};

    std::ofstream write("sample.txt");

    for(int i = 0; i < 1000000; i++) {
        for(Player& player : players)
            player.clear();

        std::vector<std::array<int, 2> > rollset;
        Player * winner = 0;
        
        while(1) {
            for (Player& player : players) {
                if ( i == 1) {
                    write << player.name << ", it is your turn\n";
                    rollset = player.doTurn();
                    for(std::array<int, 2> roll : rollset) {
                        int sum = Player::rollSum(roll.at(0), roll.at(1)); 
                        write << "* You rolled " << roll.at(0) << " and " <<
                            roll.at(1) << ". That's "
                            << (sum == -1 ? "SKUNK" : std::to_string(sum)) << std::endl;
                    }
                    write << "** Points for turn = " << Player::sum(rollset) <<
                        std::endl;
                    if(win(players)) {winner = &player; break;};
                    write << "*** Total points = " << player.score << std::endl;
                    write << std::endl;
                } else
                    player.doTurn();
                if(win(players)) {winner = &player; break;};
            }
            if(winner != nullptr)
                break;
        }
        if ( i == 1)
            write << printWin(winner);
        winner->wins++;
    }
    for(unsigned int i = 1; i < 4; i++)
       std::cout << "Player " << i << " won " << std::fixed << std::setprecision(1) << std::setfill('0') << std::setw(4) << players[i - 1].wins / 10000. << "% of the games." << std::endl;
}

std::string printWin(Player *player) {
    return player->name + " won the game with " + std::to_string(player->score) + 
        " points";
}

bool win(std::array<Player, 3> players) {
    for(Player player : players)
        if(player.score >= 100) return true;
    return false;
}
