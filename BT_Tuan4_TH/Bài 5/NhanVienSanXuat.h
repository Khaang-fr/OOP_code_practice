#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class NhanVienSanXuat : public NhanVien {
private:
    long luongCoBan;
    int soSanPham;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        cin.ignore();
    }

    void xuat() const override {
        NhanVien::xuat();
        cout << setw(15) << "San xuat" 
             << setw(10) << tinhLuong() << endl;
    }

    long tinhLuong() const override {
        return luongCoBan + soSanPham * 5000;
    }
};
