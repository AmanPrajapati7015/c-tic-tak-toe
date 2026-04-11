#pragma once
#include "minMax.hpp"
#include "player.hpp"

class AIPlayer : public Player<AIPlayer> {
    AIPlayer() = default;

   public:
    AIPlayer(const char* name, char marker) : Player(name, marker) {}
    template <typename T1>
    void PlayTurn(Board& board, Player<T1>* other) {
        double maxi_score = INT_MIN;
        int maxi_ind = -1;

        for (int i = 0; i < 9; i++) {
            if (board.m_IsValidIndex(i)) {
                double score = MinMax<true>(board, this, i, other);
                if (score > maxi_score) {
                    maxi_ind = i;
                    maxi_score = score;
                }
            }
        }

        board.m_mark(m_Marker, maxi_ind);
    }
};