#include <iostream>
#include "PhanSo.h"
using namespace std;

int main() {
    PhanSo ps;
    ps.Nhap();
    cout << "Phan so vua nhap: ";
    ps.Xuat();
    cout << "Rut gon phan so: ";
    ps.RutGon();
    ps.Xuat();
    cout << "Tinh tong voi phan so khac:" << endl;
    ps.Tong();
    ps.Xuat();
    cout << "Tinh hieu voi phan so khac:" << endl;
    ps.Hieu();
    ps.Xuat();
    cout << "Tinh tich voi phan so khac:" << endl;
    ps.Tich();
    ps.Xuat();
    cout << "Tinh thuong voi phan so khac:" << endl;
    ps.Thuong();
    ps.Xuat();
    cout << "So sanh voi phan so khac:" << endl;
    ps.SoSanh();
    return 0;
}
