#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
public:
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
    }

    virtual void xuat() const {
        cout << left << setw(25) << hoTen 
             << setw(15) << ngaySinh;
    }

    virtual long tinhLuong() const = 0;
    virtual ~NhanVien() {}

    string getHoTen() const {
        return hoTen;
    }

    string getNgaySinh() const {
        return ngaySinh;
    }
};
