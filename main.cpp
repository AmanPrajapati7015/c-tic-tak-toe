#include <iostream>
#include "board.hpp"
#include "gameRunner.hpp"
#include "player.hpp"

HumanPlayer player1("Aman", 'X');
AIPlayer player2("AI", 'O');

int main(int argc, char const* argv[]) {
    Board board{};
    bool isDraw = true;
    while (!board.m_IsEnded()) {
        if (GameRunner(board, &player1)) {
            isDraw = 0;
            break;
        }
        if (!board.m_IsEnded() && GameRunner(board, &player2)) {
            isDraw = 0;
            break;
        }
    }

    if (isDraw) {
        std::cout << "Match Draw" << std::endl;
    }
}
