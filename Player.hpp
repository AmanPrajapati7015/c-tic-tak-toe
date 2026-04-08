#pragma once
#include <iostream>
#include "board.hpp"

enum class Entity { HUMAN, AI };

class Player {
   protected:
    const char* m_Name;
    char m_Marker;

   public:
    Player(const char* name, char marker);
    char getMarker();
    const char* getName();
    virtual void PlayTurn(Board& board) = 0;
    virtual Entity WhoAmI() = 0;
};

class HumanPlayer : public Player {
   public:
    HumanPlayer(const char* name, char marker);
    void PlayTurn(Board& board) override;
    Entity WhoAmI() override;
};

class AIPlayer : public Player {
   public:
    AIPlayer(const char* name, char marker);
    void PlayTurn(Board& board) override;
    Entity WhoAmI() override;
};
