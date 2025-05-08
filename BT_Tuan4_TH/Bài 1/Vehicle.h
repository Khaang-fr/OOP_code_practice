#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Vehicle {
private:
    string mSC;
    string hoTen;
    string soXe;
    double doanhThu;
    
public:
    Vehicle() {
        this->mSC="";
        this->hoTen="";
        this->soXe="";
        this->doanhThu=0.0;
    }
    void Nhap();
    void Xuat();
    double GetDoanhThu();
    void SetDoanhThu(double dt);
    ~Vehicle() {
        cout << "bye!" << endl;
    }
};
