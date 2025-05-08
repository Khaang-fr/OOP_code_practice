#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class sachGiaoKhoa : public Sach
{
private: 
    string tinhTrang;
    double thanhTien;
public:
    void nhap();
    void xuat();
    double tinhThanhTien() {
        double tien;
        if (tinhTrang == "moi") {
            tien = this->getSoLuong() * this->getDonGia();
        } else {
            tien = this->getSoLuong() * this->getDonGia() / 2;
        }
        return tien;
    }
    double getThanhTien() {
        return thanhTien;
    }
};
