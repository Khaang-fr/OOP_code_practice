#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cin.ignore();
    }

    void xuat() const override {
        NhanVien::xuat();
        cout << setw(15) << "Van phong" 
             << setw(10) << tinhLuong() << endl;
    }

    long tinhLuong() const override {
        return soNgayLamViec * 100000;
    }
};
