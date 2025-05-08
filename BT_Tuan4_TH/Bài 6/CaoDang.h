#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class CaoDang : public SinhVien {
private:
    double diemTotNghiep;
public:
    void nhap() {
        SinhVien::nhap();
        cout << "Nhap diem tot nghiep: ";
        cin >> diemTotNghiep;
        cin.ignore();
    }

    void xuat() const {
        SinhVien::xuat();
        cout << "Diem tot nghiep: " << diemTotNghiep << "\n"
             << "He: Cao dang";
        if (totNghiep()) cout << " (Dat tot nghiep)";
        else cout << " (Khong dat)";
        cout << "\n";
    }

    bool totNghiep() const {
        return (tongSoTC >= 110 && diemTB >= 5 && diemTotNghiep >= 5);
    }
};
