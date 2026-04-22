#pragma once
#include <algorithm>
#include <type_traits>
#include "board.hpp"
#include "player.hpp"

static const double DECAY_RATE = 0.95;

// T is cur player who has to play,
//  T1 will play next

// isMaxi = 1 (adversary is T)
template <bool isMaxi, typename T, typename T1>
double MinMax(Board& board, Player<T>* p, int i, Player<T1>* other) {
    board.m_mark(p->getMarker(), i);  // played by T

    // base case: evaluated for the player who JUST moved (p)
    if (board.m_HasWon()) {
        board.m_RemoveMark(i);
        // if constexpr (std::is_same_v<HumanPlayer, T>)
        if constexpr (!isMaxi)
            return -5;
        else
            return 5;
    }

    if (board.m_IsEnded()) {
        board.m_RemoveMark(i);
        return 0;
    }

    double bestScore;
    if constexpr (!isMaxi)  // next player is AI
        bestScore = INT_MIN;
    else
        bestScore = INT_MAX;

    for (int j = 0; j < 9; j++) {
        if (board.m_IsValidIndex(j)) {
            double score = MinMax<!isMaxi>(board, other, j, p);
            if constexpr (!isMaxi)  // next player is AI
                bestScore = std::max(bestScore, score);
            else
                bestScore = std::min(bestScore, score);
        }
    }

    board.m_RemoveMark(i);

    return (DECAY_RATE)*bestScore;
}