#pragma once
#include <iostream>
#include "board.hpp"
#include "player.hpp"

template <typename T, typename T1>
int GameRunner(Board& board, Player<T>* activePlayer, Player<T1>* other) {
    board.m_Display();
    activePlayer->PlayTurn(board, other);

    if (board.m_HasWon()) {
        std::cout << activePlayer->getName() << " has Won the Game"
                  << std::endl;
        return 1;
    }
    return 0;
}