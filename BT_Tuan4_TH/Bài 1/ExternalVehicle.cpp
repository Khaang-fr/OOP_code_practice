#include <iostream>
#include <string.h>
#include <string>
#include "ExternalVehicle.h"
using namespace std;

void ExternalVehicle::Nhap() {
    Vehicle::Nhap();
    cout << "Nhap noi den: "; getline(cin, this->noiDen);
    cout << "Nhap so ngay: "; cin >> this->soNgayDi;
    cin.ignore();
}
void ExternalVehicle::Xuat() {
    Vehicle::Xuat();
    cout << "Noi den: " << this->noiDen << endl;
    cout << "So ngay di: " << this->soNgayDi << endl;
}
