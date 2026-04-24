#pragma once
#include <iostream>
// #include <sstream>
#include "board.hpp"

template <typename T>
class Player {
   private:
    Player() = default;

   protected:
    const char* m_Name;
    char m_Marker;
    T* getDerived() { return static_cast<T*>(this); }
    friend T;

   public:
    Player(const char* name, char marker) : m_Name(name), m_Marker(marker) {}
    char getMarker() const { return m_Marker; }
    const char* getName() const { return m_Name; };
    template <typename T1>
    void PlayTurn(Board& board, Player<T1>* other) {
        getDerived()->PlayTurn(board, other);
    };
};

// extern std::istringstream stringcin;

class HumanPlayer : public Player<HumanPlayer> {
    HumanPlayer() = default;

   public:
    HumanPlayer(const char* name, char marker) : Player(name, marker) {}

    template <typename T1>
    void PlayTurn(Board& board, Player<T1>* other) {
        int i, j;
        while (true) {
            std::cout << "Please give i, j, for Player (" << m_Name << ") ["
                      << m_Marker << "] :: ";
            std::cin >> i >> j;
            // stringcin >> i >> j;

            if (i < 0 || j < 0 || i >= 3 || j >= 3) {
                std::cout << "Out of bounds! Please try again.\n";
            } else if (board.m_mark(m_Marker, i * 3 + j)) {
                break;
            }
        }
    }
};
