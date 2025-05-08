#pragma once
class InternalVehicle:public Vehicle {
private:
    string soTuyen;
    int soKM;
public:
    void Nhap();
    void Xuat();
};
