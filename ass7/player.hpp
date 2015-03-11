#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <array>

class Player {
    public:
        struct turn {
            public:
                std::array<int, 2> roll;
                int result;
                turn(std::array<int, 2> roll, int result) : roll(roll)
                                                         , result{result} { }
        };
        std::string name;
        int score = 0;
        int wins = 0;
        std::vector<std::array<int, 2> > doTurn();
        Player(std::string, int);
        void clear();
        static int rollSum(int, int);
        static int sum(std::vector<std::array<int, 2> >);
    private:
        int turnlength;
        turn roll();
        int rollDice();
};

#endif
