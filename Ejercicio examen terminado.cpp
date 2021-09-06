#include "pch.h"
#include <conio.h>
#include "1Pitcher.hpp"
#include "2Pitcher.hpp"
#include <time.h>

using namespace System;

int main() {
    srand(time(NULL));
    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;

    _1Pitcher* ObjPitcher = new _1Pitcher();
    Sphere* ObjSphere;
    _2Pitcher* ObjPitcher2 = new _2Pitcher();
    Ball* ObjBall;

    Console::SetCursorPosition(0, 0);
    Console::ForegroundColor = ConsoleColor::Blue;
    cout << "O-"; //Lanzador 1 de color azul
    Console::SetCursorPosition(40, 36);
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "|";
    Console::SetCursorPosition(40, 37);
    cout << "O";

    Console::ForegroundColor = ConsoleColor::White;
    while (true) {
        //add more Spheres
        if (ObjPitcher->getN() > 0) {
            for (int i = 0; i < ObjPitcher->getN(); i++) {
                ObjSphere = ObjPitcher->obtainSphere(i);
                ObjSphere->erase();
                ObjSphere->move();
                Console::ForegroundColor = ConsoleColor::Blue;
                ObjSphere->draw();
                //ObjSphere->eerase();
            }
        }

        if (ObjPitcher2->getN() > 0) {
            for (int i = 0; i < ObjPitcher2->getN(); i++) {
                ObjBall = ObjPitcher2->obtainBall(i);
                ObjBall->erase();
                ObjBall->move();
                Console::ForegroundColor = ConsoleColor::Red;
                ObjBall->draw();
            }
        }

        if (kbhit()) {
            char key = getch();
            if (toupper(key) == 'A') {
                ObjSphere = new Sphere(2, 0);
                ObjPitcher->addSphere(ObjSphere);

            }
            else if (toupper(key) == 'R') {
                ObjBall = new Ball(40, 35);
                ObjPitcher2->addBall(ObjBall);

            }
        }
        _sleep(20);
    }

    return 0;
}