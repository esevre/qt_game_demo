//
// Created by Erik Sevre on 11/20/18.
//

#pragma once

#include <vector>
#include <Qwidget>
#include <QGridLayout>

#include "GamePiece.hpp"

class GameBoard : public QWidget
{
    Q_OBJECT

    enum class Direction {UP, DOWN, LEFT, RIGHT};

public:
    explicit GameBoard(QWidget *parent = nullptr);


protected:
    void keyPressEvent(QKeyEvent* event) override;

    constexpr size_t index(size_t row, size_t col) noexcept { return col + numCols * row; }

    GamePiece *getPiece(size_t row, size_t col) { return gamePieces[index(row, col)]; }
    void movePiece(GamePiece *piece, Direction direction);
    void swapPieces(size_t row_1, size_t col_1, size_t row_2, size_t col_2);
    void updateGrid();

private:
    std::vector<GamePiece *> gamePieces;
    QGridLayout *gridLayout;

    GamePiece *player;
    GamePiece *badGuy;

    size_t numRows = 8;
    size_t numCols = 8;

};


