#pragma once
#include <iostream>
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

    void PlayTurn(Board& board) { getDerived()->PlayTurn(board); };
};

class HumanPlayer : public Player<HumanPlayer> {
    HumanPlayer() = default;

   public:
    HumanPlayer(const char* name, char marker);
    void PlayTurn(Board& board);
};

class AIPlayer : public Player<AIPlayer> {
    AIPlayer() = default;

   public:
    AIPlayer(const char* name, char marker);
    void PlayTurn(Board& board);
};
