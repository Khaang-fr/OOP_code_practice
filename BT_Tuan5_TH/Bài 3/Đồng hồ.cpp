#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

//cTime.h
//#pragma once
//#include <iostream>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
class cTime {
    private:
        int gio, phut, giay;
        void normalize() {
            if (giay >= 60) {
                phut += giay / 60;
                giay %= 60;
            }
            if (giay < 0) {
                int m = (abs(giay) + 59) / 60;
                phut -= m;
                giay += m * 60;
            }
            if (phut >= 60) {
                gio += phut / 60;
                phut %= 60;
            }
            if (phut < 0) {
                int h = (abs(phut) + 59) / 60;
                gio -= h;
                phut += h * 60;
            }
            if (gio >= 24)
                gio %= 24;
            if (gio < 0)
                gio = (gio % 24 + 24) % 24;
        }
    public:
        cTime(int g = 0, int p = 0, int s = 0) : gio(g), phut(p), giay(s) {normalize();}
        cTime operator+(int s);
        cTime operator-(int s);
        cTime operator++();
        cTime operator--();
        friend ostream& operator<<(ostream& os, const cTime& t) {
            os << t.gio << ":" << t.phut << ":" << t.giay;
            return os;
        }
        friend istream& operator>>(istream& is, cTime& t) {
            char c;
            do {
                cout << "Nhap thoi gian: ";
                is >> t.gio >> c >> t.phut >> c >> t.giay;
                if (t.gio < 0 || t.gio > 23 || t.phut < 0 || t.phut > 59 || t.giay < 0 || t.giay >59) {
                    cout << "Thoi gian khong hop le, vui long nhap lai." << endl;
                }
            } while (t.gio < 0 || t.gio > 23 || t.phut < 0 || t.phut > 59 || t.giay < 0 || t.giay >59);
            return is;
        }
        void setCurrentTime() {
            SYSTEMTIME st;
            GetLocalTime(&st);
            gio = st.wHour;
            phut = st.wMinute;
            giay = st.wSecond;
        }
};
void gotoxy(int x, int y);

//cTime.cpp
//#include "cTime.h"
//#include <iostream>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
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

//main.cpp
//#include "cTime.h"
//#include <iostream>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
int main() {
    cTime t;
    while (true) {
        t.setCurrentTime();
        gotoxy(70, 0);
        cout << t << flush;
        Sleep(1000);
    }
    return 0;
}
