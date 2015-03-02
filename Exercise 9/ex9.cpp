#include <iostream>
#include <cstdlib>
#include <bitset>
#include <iomanip>

/*
 * Lee Mracek
 * Exercise 9
 * Bundled GCC (CLion)
 */

int main() {
    int head, tail = 0;
    std::bitset<1> flip;

    srand(time(0));

    for (int i = 0; i < 1000000; ++i) {
        flip = std::rand() % 2;
        if (flip[0] & 1) {
            head++;
        } else {
            tail++;
        }
    }
    std::cout << "Number of heads = " << head
            << std::fixed << std::setprecision(2) << ", percent = " << static_cast<float>(head) / 10000 << "%" << std::endl;
    std::cout << "Number of tails = " << tail
            << std::fixed << std::setprecision(2) << ", percent = " << static_cast<float>(tail) / 10000 << "%" << std::endl;
    return 0;
}
