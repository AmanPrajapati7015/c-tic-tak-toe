#include "board.hpp"
#include <iostream>

Board::Board() {
    emplyCells = 9;
    for (int i = 0; i < 9; i++) {
        board[i / 3][i % 3] = '_';
    }
}

void Board::m_Display() const {
    std::cout << "_______\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << '|' << board[i][j];
        }
        std::cout << "|\n";
    }
    std::cout.flush();
}

bool Board::m_HasWon() const {
    // Won by rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '_' && board[i][0] == board[i][1] &&
            board[i][0] == board[i][2])
            return 1;
    }
    // Won by cols
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != '_' && board[0][j] == board[1][j] &&
            board[0][j] == board[2][j])
            return 1;
    }

    // Won by diagonal
    if (board[0][0] != '_' && board[0][0] == board[1][1] &&
        board[0][0] == board[2][2])
        return 1;

    if (board[0][2] != '_' && board[0][2] == board[1][1] &&
        board[0][2] == board[2][0])
        return 1;
    return 0;
}

bool Board::m_IsEnded() const {
    return emplyCells == 0;
}

int Board::m_mark(char marker, int i, int j) {
    if (i > 3 || j > 3) {
        std::cout << "out of range index.\n";
        return 0;
    } else if (board[i][j] != '_') {
        std::cout << "Please provide an empty cell.\n";
        return 0;
    }

    board[i][j] = marker;
    emplyCells--;
    return 1;
}

bool Board::m_IsValidIndex(int i) const {
    if (i > 8)
        return false;
    if (board[i / 3][i % 3] != '_')
        return false;
    return true;
}

void Board::m_RemoveMark(int i, int j) {
    board[i][j] = '_';
    emplyCells++;
}