#pragma once
#include <algorithm>
#include <type_traits>
#include "board.hpp"
#include "player.hpp"

static const double DECAY_RATE = 0.95;

template <typename T, typename T1>
double MinMax(Board& board, Player<T>* p, int i, Player<T1>* other) {
    board.m_mark(p->getMarker(), i);

    // base case: evaluated for the player who JUST moved (p)
    if (board.m_HasWon()) {
        board.m_RemoveMark(i);
        if constexpr (std::is_same_v<HumanPlayer, T>)
            return -5;
        else
            return 5;
    }

    if (board.m_IsEnded()) {
        board.m_RemoveMark(i);
        return 0;
    }

    double g_bestScore = 0;

    if constexpr (std::is_same_v<HumanPlayer, T>) {  // next player is AI
        double bestScore = INT_MIN;

        for (int j = 0; j < 9; j++) {
            if (board.m_IsValidIndex(j)) {
                double score = MinMax(board, other, j, p);
                bestScore = std::max(bestScore, score);
            }
        }
        g_bestScore = bestScore;
    }

    else {  // next player is HUMAN
        double bestScore = INT_MAX;

        for (int j = 0; j < 9; j++) {
            if (board.m_IsValidIndex(j)) {
                double score = MinMax(board, other, j, p);
                bestScore = std::min(bestScore, score);
            }
        }
        g_bestScore = bestScore;
    }

    board.m_RemoveMark(i);

    return (DECAY_RATE)*g_bestScore;
}