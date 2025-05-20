#include "cTime.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
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
