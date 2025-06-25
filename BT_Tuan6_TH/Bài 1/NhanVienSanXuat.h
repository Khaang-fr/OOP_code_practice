#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVienSanXuat : public NhanVien {
    double luongCB;
    int soSP;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap luong co ban: ";
        cin >> luongCB;
        cout << "Nhap so san pham: ";
        cin >> soSP;
        cin.ignore();
    }
    void xuat() const override {
        NhanVien::xuat();
        cout << ", Loai: SX, Luong: " << tinhLuong() << endl;
    }
    double tinhLuong() const override {
        return luongCB + soSP * 5000;
    }
    int layTuoi() const override {
        return 2025 - stoi(ngaySinh.substr(6));
    }
};
