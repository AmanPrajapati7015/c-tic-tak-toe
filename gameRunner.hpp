#include <iostream>
#include "board.hpp"
#include "player.hpp"

template <typename T>
int GameRunner(Board& board, Player<T>* activePlayer) {
    // Board board;
    board.m_Display();
    activePlayer->PlayTurn(board);

    if (board.m_HasWon()) {
        std::cout << activePlayer->getName() << " has Won the Game"
                  << std::endl;
        return 1;
    }
    return 0;
}