#include <algorithm>
#include "Player.hpp"
#include "board.hpp"

HumanPlayer player1("Aman", 'X');
AIPlayer player2("AI", 'O');

Board board;

Player* switchPlayer(Player* prev) {
    if (prev == &player1)
        return &player2;
    return &player1;
}

int MinMax(Board& board, Player* p, int i) {
    board.m_mark(p->getMarker(), i / 3, i % 3);

    // base case: evaluated for the player who JUST moved (p)
    if (board.m_HasWon()) {
        board.m_RemoveMark(i / 3, i % 3);
        if (p->WhoAmI() == Entity::AI)
            return 5;
        return -5;
    }

    if (board.m_IsEnded()) {
        board.m_RemoveMark(i / 3, i % 3);
        return 0;
    }

    // Identify the player taking the NEXT turn
    Player* nextPlayer = switchPlayer(p);

    // Initialize bestScore based on the NEXT player's goals
    int bestScore = (nextPlayer->WhoAmI() == Entity::AI) ? INT_MIN : INT_MAX;

    for (int j = 0; j < 9; j++) {
        if (board.m_IsValidIndex(j)) {
            // Pass nextPlayer to the recursive call
            int score = MinMax(board, nextPlayer, j);

            // Maximize if the next player is AI, Minimize if Human
            if (nextPlayer->WhoAmI() == Entity::AI)
                bestScore = std::max(bestScore, score);
            else
                bestScore = std::min(bestScore, score);
        }
    }

    board.m_RemoveMark(i / 3, i % 3);

    return bestScore;
}