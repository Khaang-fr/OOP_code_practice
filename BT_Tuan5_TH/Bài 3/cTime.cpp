#include "cTime.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
cTime cTime::operator+(int s) {
    cTime tmp(gio, phut, giay + s);
    tmp.normalize();
    return tmp;
}
cTime cTime::operator-(int s) {
    cTime tmp(gio, phut, giay - s);
    tmp.normalize();
    return tmp;
}
cTime cTime::operator++() {
    giay++;
    normalize();
    return *this;
}
cTime cTime::operator--() {
    giay--;
    normalize();
    return *this;
}
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
