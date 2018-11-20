//
// Created by Erik Sevre on 11/20/18.
//

#pragma once

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPen>


class GamePiece : public QWidget
{
    Q_OBJECT
public:
    explicit GamePiece(QWidget *parent = nullptr);
    explicit GamePiece(size_t row, size_t col, QWidget *parent = nullptr);
    explicit GamePiece(QColor playerColor, QColor backgroundColor, QWidget *parent = nullptr);
    explicit GamePiece(size_t row, size_t col, QColor playerColor, QColor backgroundColor, QWidget *parent = nullptr);

    void setRow(size_t new_row) { row = new_row; }
    void setCol(size_t new_col) { col = new_col; }

protected:
    void setupBackgroundPalette();
    void drawPlayer(QPainter &painter);
    void setupPainter(QPainter &painter);

    void paintEvent(QPaintEvent* event) override;

private:
    QColor playerColor;
    QColor backgroundColor;

public:
    size_t row = 0;
    size_t col = 0;
};


