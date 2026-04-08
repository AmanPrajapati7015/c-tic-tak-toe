#pragma once

class Board {
    char board[3][3];
    int emptyCells;

   public:
    Board();
    // Board(const Board& prev);
    bool m_mark(char marker, int i);
    void m_Display() const;
    bool m_IsEnded() const;
    bool m_HasWon() const;
    bool m_IsValidIndex(int i) const;

    void m_RemoveMark(int i);
};