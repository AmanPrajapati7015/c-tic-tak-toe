#include "player.hpp"
#include <iostream>
#include "minMax.hpp"

HumanPlayer::HumanPlayer(const char* name, char marker)
    : Player(name, marker) {}

void HumanPlayer::PlayTurn(Board& board) {
    int i, j;
    while (1) {
        std::cout << "Please give i, j, for Player (" << m_Name << ") ["
                  << m_Marker << "] :: ";
        std::cin >> i >> j;

        if (board.m_mark(m_Marker, i, j))
            break;
        else
            std::cout << "Please try again" << std::endl;
    }
}

AIPlayer::AIPlayer(const char* name, char marker) : Player(name, marker) {}

void AIPlayer::PlayTurn(Board& board) {
    int maxi_score = INT_MIN;
    int maxi_ind = -1;

    for (int i = 0; i < 9; i++) {
        if (board.m_IsValidIndex(i)) {
            int score = MinMax(board, this, i);
            if (score > maxi_score) {
                maxi_ind = i;
                maxi_score = score;
            }
        }
    }

    board.m_mark(m_Marker, maxi_ind / 3, maxi_ind % 3);
}
