#include "cDaThuc.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Nhap vao cDaThuc thu 1:" << endl;
    cDaThuc p1;
    p1.nhap();
    cout << endl;
    cout << "cDaThuc da nhap vao: " << endl;
    p1.xuat();
    double x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Gia tri cDaThuc tai x = " << x << ": " << p1.tinhGiaTri(x) << endl;

    cout << "Nhap vao cDaThuc thu 2:" << endl;
    cDaThuc p2;
    p2.nhap();
    cout << endl;
    cout << "cDaThuc da nhap vao: " << endl;
    p2.xuat();
    double y;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Gia tri cDaThuc tai y = " << y << ": " << p2.tinhGiaTri(y) << endl;

    cDaThuc tong = p2.tong(p1);
    cout << "Tong: " << tong << endl;
    cDaThuc hieu = p2.hieu(p1);
    cout << "Hieu: " << hieu << endl;
    return 0;
}
