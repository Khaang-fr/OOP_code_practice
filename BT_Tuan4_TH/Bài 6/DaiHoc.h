#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class DaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void nhap() {
        SinhVien::nhap();
        cout << "Nhap ten luan van: ";
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
        cin.ignore();
    }

    void xuat() const {
        SinhVien::xuat();
        cout << "Ten luan van: " << tenLuanVan << "\n"
             << "Diem luan van: " << diemLuanVan << "\n"
             << "He: Dai hoc";
        if (totNghiep()) cout << " (Dat tot nghiep)";
        else cout << " (Khong dat)";
        cout << "\n";
    }

    bool totNghiep() const {
        return (tongSoTC >= 145 && diemTB >= 5 && diemLuanVan >= 5);
    }

    bool laDaiHoc() const {
        return true;
    }
};
