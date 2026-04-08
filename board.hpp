#pragma once

class Board {
    char board[3][3];
    int emplyCells;

   public:
    Board();
    // Board(const Board& prev);
    void m_mark(char marker, int i, int j);
    void m_Display() const noexcept;
    bool m_IsEnded() const;
    bool m_HasWon() const;
    bool m_IsValidIndex(int i) const;

    void m_RemoveMark(int i, int j);
};