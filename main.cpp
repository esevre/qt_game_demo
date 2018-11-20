#include <iostream>
#include <QApplication>

#include "GamePiece.hpp"
#include "GameBoard.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    GamePiece player(QColor(0,0,0), QColor(255,0,0));
//    player.show();
    GameBoard board;
    board.show();

    app.exec();
}