#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVienVanPhong : public NhanVien {
    int soNgayLV;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLV;
        cin.ignore();
    }
    void xuat() const override {
        NhanVien::xuat();
        cout << ", Loai: VP, Luong: " << tinhLuong() << endl;
    }
    double tinhLuong() const override {
        return soNgayLV * 100000;
    }
    int layTuoi() const override {
        return 2025 - stoi(ngaySinh.substr(6));
    }
};
