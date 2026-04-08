#include "Player.hpp"
#include <algorithm>
int MinMax(Board& board, Player* p, int i);

Player::Player(const char* name, char marker)
    : m_Name(name), m_Marker(marker) {}

char Player::getMarker() {
    return m_Marker;
}
const char* Player::getName() {
    return m_Name;
}

HumanPlayer::HumanPlayer(const char* name, char marker)
    : Player(name, marker) {}

Entity HumanPlayer::WhoAmI() {
    return Entity::HUMAN;
}

void HumanPlayer::PlayTurn(Board& board) {
    int i, j;

    while (1) {
        std::cout << "Please give i, j, for Player (" << m_Name << ") ["
                  << m_Marker << "] :: ";
        std::cin >> i >> j;
        try {
            board.m_mark(m_Marker, i, j);
            break;
        } catch (std::exception& ex) {
            std::cout << ex.what() << "Please try again" << std::endl;
        }
    }
}

AIPlayer::AIPlayer(const char* name, char marker) : Player(name, marker) {}

Entity AIPlayer::WhoAmI() {
    return Entity::AI;
}

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
