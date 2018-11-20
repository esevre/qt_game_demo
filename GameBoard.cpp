//
// Created by Erik Sevre on 11/20/18.
//

#include "GameBoard.hpp"

#include <iostream>

#include <algorithm>
#include <QKeyEvent>


GameBoard::GameBoard(QWidget* parent)
    : QWidget(parent)
{
    this->resize(640, 480);

    gamePieces.resize(numRows * numCols);

    player = new GamePiece(QColor(255, 200, 200), QColor(0, 50, 100), this);
    badGuy = new GamePiece(QColor(255, 128, 128), QColor(255, 0, 0), this);

    gamePieces[0] = player;
    gamePieces[1] = badGuy;
    for (int i = 2; i<numRows*numCols; ++i) {
        gamePieces[i] = new GamePiece(this);
    }
    for (size_t row = 0; row<numRows; ++row) {
        for (size_t col = 0; col<numCols; ++col) {
            gamePieces[index(row, col)]->row = row;
            gamePieces[index(row, col)]->col = col;
        }
    }

    gridLayout = new QGridLayout(this);
    this->setLayout(gridLayout);

    updateGrid();

}

void GameBoard::updateGrid() {

    for (int row = 0; row<numRows; ++row) {
        for (int col = 0; col<numCols; ++col) {
            gridLayout->addWidget(
                    gamePieces[index(row, col)], row, col
            );
        }
    }
}

void GameBoard::movePiece(
        GamePiece* piece,
        GameBoard::Direction direction)
{
    if (direction == Direction::UP) {
        if (piece->row > 0) {
            size_t new_row = piece->row - 1;
            size_t new_col = piece->col;
            size_t old_row = piece->row;
            size_t old_col = piece->col;

            swapPieces(old_row, old_col, new_row, new_col);
        }
    }
    else if (direction == Direction::DOWN){
        if (piece->row < numRows - 1) {
            size_t new_row = piece->row + 1;
            size_t new_col = piece->col;
            size_t old_row = piece->row;
            size_t old_col = piece->col;

            swapPieces(old_row, old_col, new_row, new_col);
        }

    }
    else if (direction == Direction::LEFT){
        if (piece->col > 0) {
            size_t new_row = piece->row;
            size_t new_col = piece->col - 1;
            size_t old_row = piece->row;
            size_t old_col = piece->col;

            swapPieces(old_row, old_col, new_row, new_col);
        }

    }
    else if (direction == Direction::RIGHT){
        if (piece->col < numCols - 1) {
            size_t new_row = piece->row;
            size_t new_col = piece->col + 1;
            size_t old_row = piece->row;
            size_t old_col = piece->col;

            swapPieces(old_row, old_col, new_row, new_col);
        }

    }
}

void GameBoard::swapPieces(size_t row_1, size_t col_1, size_t row_2, size_t col_2)
{
    // only do the swap if a row or column will switch
    if (row_1 != row_2 or col_1 != col_2) {

        gamePieces[index(row_1, col_1)]->setRow(row_2);
        gamePieces[index(row_1, col_1)]->setCol(col_2);
        auto basePiece = gamePieces[index(row_1, col_1)];

        gamePieces[index(row_2, col_2)]->setRow(row_1);
        gamePieces[index(row_2, col_2)]->setCol(col_1);
        auto targetPiece = gamePieces[index(row_2, col_2)];

        gamePieces[index(row_1, col_1)] = targetPiece;
        gamePieces[index(row_2, col_2)] = basePiece;
    }
}

void GameBoard::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key_Down) {
        movePiece(player, Direction::DOWN);
    }
    else if (event->key() == Qt::Key_Up) {
        movePiece(player, Direction::UP);
    }
    else if (event->key() == Qt::Key_Left) {
        movePiece(player, Direction::LEFT);
    }
    else if (event->key() == Qt::Key_Right) {
        movePiece(player, Direction::RIGHT);
    }

    if (event->key() == Qt::Key_S) {
        movePiece(badGuy, Direction::DOWN);
    }
    else if (event->key() == Qt::Key_W) {
        movePiece(badGuy, Direction::UP);
    }
    else if (event->key() == Qt::Key_A) {
        movePiece(badGuy, Direction::LEFT);
    }
    else if (event->key() == Qt::Key_D) {
        movePiece(badGuy, Direction::RIGHT);
    }

    updateGrid();
    update();

}







