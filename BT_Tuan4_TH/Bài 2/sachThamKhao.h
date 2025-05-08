#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class sachThamKhao : public Sach 
{
private:
    double thue;
    double thanhTien;
public:
    void nhap();
    void xuat();
    double tinhThanhTien() {
        double tien = this->getDonGia() * this->getSoLuong() + this->thue;
        return tien;
    }
    double getThanhTien() {
        return thanhTien;
    }
};
