#pragma once
#include <string>
class ExternalVehicle: public Vehicle {
private:
    string noiDen;
    int soNgayDi;
public:
    void Nhap();
    void Xuat();

};
