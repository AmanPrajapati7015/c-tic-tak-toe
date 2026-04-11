#include <iostream>
#include "aiPlayer.hpp"
#include "board.hpp"
#include "gameRunner.hpp"
#include "player.hpp"

int main(int argc, char const* argv[]) {
    HumanPlayer player1("Aman", 'X');
    AIPlayer player2("Divesh", 'O');
    Board board{};

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
