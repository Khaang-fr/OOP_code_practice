#include <iostream>
#include <string.h>
#include <string>
#include "InternalVehicle.h"
using namespace std;

void InternalVehicle::Nhap() { 
    Vehicle::Nhap();
    cout << "Nhap so tuyen:"; getline(cin, this->soTuyen);
    cout << "Nhap so km:"; cin >> this->soKM;
    cin.ignore();
}

void InternalVehicle::Xuat() {
    Vehicle::Xuat();
    cout << "So tuyen: " << this->soTuyen << endl;
    cout << "So km: " << this->soKM << endl;
}
