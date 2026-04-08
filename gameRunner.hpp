#include <iostream>
#include "board.hpp"
#include "player.hpp"

extern Board board;

template <typename T>
int GameRunner(Player<T>* activePlayer) {
    board.m_Display();
    activePlayer->PlayTurn(board);

    if (board.m_HasWon()) {
        std::cout << activePlayer->getName() << " has Won the Game"
                  << std::endl;
        return 1;
    }
    return 0;
}