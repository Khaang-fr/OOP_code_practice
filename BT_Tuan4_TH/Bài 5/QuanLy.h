#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class QuanLy {
private:
    vector<NhanVien*> danhSach;
public:
    ~QuanLy() {
        for (NhanVien* nv : danhSach)
            delete nv;
    }

    void themNhanVien() {
        int loai;
        cout << "Chon loai nhan vien (1: San xuat, 2: Van phong): ";
        cin >> loai;
        cin.ignore();

        NhanVien* nv;
        if (loai == 1)
            nv = new NhanVienSanXuat();
        else
            nv = new NhanVienVanPhong();

        nv->nhap();
        danhSach.push_back(nv);
    }

    void xuatDanhSach() const {
        for (NhanVien* nv : danhSach) {
            cout << "Ho ten: " << nv->getHoTen() 
                 << " - Ngay sinh: " << nv->getNgaySinh() 
                 << " - Loai: " << (dynamic_cast<NhanVienSanXuat*>(nv) ? "San xuat" : "Van phong") 
                 << " - Luong: " << nv->tinhLuong() << " VND\n";
        }
    }

    void tinhTongLuong() const {
        long tongLuong = 0;
        for (NhanVien* nv : danhSach)
            tongLuong += nv->tinhLuong();

        cout << "\nTong luong cong ty phai tra: " << tongLuong << " VND\n";
    }

    void menu() {
        int choice;
        do {
            cout << "1. Them nhan vien\n";
            cout << "2. Xuat danh sach nhan vien\n";
            cout << "3. Tinh tong luong\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    themNhanVien();
                    break;
                case 2:
                    xuatDanhSach();
                    break;
                case 3:
                    tinhTongLuong();
                    break;
                case 0:
                    cout << "Thoat chuong trinh.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai.\n";
            }
        } while (choice != 0);
    }
};
