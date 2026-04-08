#include <exception>
#include <iostream>
#include "Player.hpp"
#include "board.hpp"

extern HumanPlayer player1;
extern AIPlayer player2;

void GameRunner() {
    Board board{};

    Player* activePlayer = &player1;

    while (!board.m_IsEnded()) {
        board.m_Display();
        activePlayer->PlayTurn(board);

        if (board.m_HasWon()) {
            std::cout << activePlayer->getName() << " has Won the Game"
                      << std::endl;
            return;
        }

        if (activePlayer == &player1)
            activePlayer = &player2;
        else
            activePlayer = &player1;
    }

    std::cout << "Match Draw" << std::endl;
}