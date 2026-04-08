#include <algorithm>
#include <type_traits>
#include "board.hpp"
#include "player.hpp"

extern HumanPlayer player1;
extern AIPlayer player2;

template <typename T>
int MinMax(Board& board, Player<T>* p, int i) {
    board.m_mark(p->getMarker(), i);

    // base case: evaluated for the player who JUST moved (p)
    if (board.m_HasWon()) {
        board.m_RemoveMark(i);
        if constexpr (std::is_same_v<AIPlayer, T>)
            return 5;
        return -5;
    }

    if (board.m_IsEnded()) {
        board.m_RemoveMark(i);
        return 0;
    }

    int g_bestScore = 0;

    if constexpr (std::is_same_v<HumanPlayer, T>) {  // next player is AI
        int bestScore = INT_MIN;

        for (int j = 0; j < 9; j++) {
            if (board.m_IsValidIndex(j)) {
                int score = MinMax(board, &player2, j);
                bestScore = std::max(bestScore, score);
            }
        }
        g_bestScore = bestScore;
    }

    else {  // next player is HUMAN
        int bestScore = INT_MAX;

        for (int j = 0; j < 9; j++) {
            if (board.m_IsValidIndex(j)) {
                int score = MinMax(board, &player1, j);
                bestScore = std::min(bestScore, score);
            }
        }
        g_bestScore = bestScore;
    }

    board.m_RemoveMark(i);

    return g_bestScore;
}