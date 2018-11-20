#include <iostream>
#include <QApplication>

#include "GameBoard.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameBoard board;
    board.show();

    app.exec();
}