using namespace std;
#include <iostream>
#include "cDaThuc.h"

int main() {
    cDaThuc p1{1, 2, 3}; 
    cDaThuc p2{0, -2, 4};

    cout << "P1(x): " << p1 << endl;
    cout << "P2(x): " << p2 << endl;

    cout << "Tong: " << (p1 + p2) << endl;
    cout << "Hieu: " << (p1 - p2) << endl;
    cout << "Tich: " << (p1 * p2) << endl;

    double x = 2;
    cout << "Gia tri P1(" << x << ") = " << p1.tinhGiaTri(x) << endl;

    return 0;
}
