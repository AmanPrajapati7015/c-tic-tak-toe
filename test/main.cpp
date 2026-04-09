#include <chrono>
#include <iostream>
#include <sstream>
#include "aiPlayer.hpp"
#include "board.hpp"
#include "gameRunner.hpp"
#include "player.hpp"

std::istringstream stringcin;

int main(int argc, char const* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        HumanPlayer player1("Aman", 'X');
        AIPlayer player2("AI", 'O');
        Board board{};
        stringcin.str("0 0 2 2 2 1 0 2 1 0 ");
        bool isDraw = true;

        while (!board.m_IsEnded()) {
            if (GameRunner(board, &player1, &player2)) {
                isDraw = 0;
                break;
            }
            if (!board.m_IsEnded() && GameRunner(board, &player2, &player1)) {
                isDraw = 0;
                break;
            }
        }

        if (isDraw) {
            std::cout << "Match Draw" << std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << " milliseconds" << std::endl;
}
