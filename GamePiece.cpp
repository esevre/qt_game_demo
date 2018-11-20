//
// Created by Erik Sevre on 11/20/18.
//

#include "GamePiece.hpp"

#include <QPalette>
#include <QPainter>
#include <QPen>
#include <QRectF>

//
//  Create an empty game space
//
GamePiece::GamePiece(QWidget* parent)
    : QWidget(parent)
    , playerColor(QColor(255, 255, 255))
    , backgroundColor(QColor(255, 255, 255))
{
    this->resize(100,100);
}

GamePiece::GamePiece(
        QColor playerColor,
        QColor backgroundColor,
        QWidget* parent)
    : QWidget(parent)
    , playerColor(playerColor)
    , backgroundColor(backgroundColor)
{
    this->resize(100,100);
}

GamePiece::GamePiece(
        size_t row,
        size_t col,
        QWidget* parent)
    : QWidget(parent)
    , playerColor(QColor(255, 255, 255))
    , backgroundColor(QColor(255, 255, 255))
    , row(row)
    , col(col)
{
    this->resize(100,100);
}

GamePiece::GamePiece(
        size_t row,
        size_t col,
        QColor playerColor,
        QColor backgroundColor,
        QWidget* parent)
    : QWidget(parent)
    , playerColor(QColor(255, 255, 255))
    , backgroundColor(QColor(255, 255, 255))
    , row(row)
    , col(col)
{
    this->resize(100,100);
}

void GamePiece::setupBackgroundPalette()
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, backgroundColor);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void GamePiece::setupPainter(QPainter &Painter)
{
    Painter.setRenderHint(QPainter::Antialiasing, true);
    Painter.translate(width()/2, height()/2);
    qreal drawWidth = 5;
    Painter.setPen(QPen(playerColor, drawWidth));
}

void GamePiece::drawPlayer(QPainter &painter)
{
    qreal diameter = width() < height() ? width() : height();
    qreal pad = 10;
    if (diameter > pad) { diameter -= pad; }
    painter.drawEllipse(QRectF(-diameter/2.0, -diameter/2.0, diameter, diameter));
}

void GamePiece::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    setupPainter(painter);
    setupBackgroundPalette();
    drawPlayer(painter);
}
