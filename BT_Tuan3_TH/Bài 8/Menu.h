#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "cNhanVienSX.h"

struct NgayThang {
    int ngay;
    int thang;
    int nam;
    NgayThang() {
        ngay = 1;
        thang = 1;
        nam = 2025;
    }
    NgayThang(int ng, int th, int n) {
        ngay = ng;
        thang = th;
        nam = n;
    }
    void hienThi() const {
        cout << setfill('0') << setw(2) << ngay << "/" 
             << setfill('0') << setw(2) << thang << "/" 
             << nam;
    }
    string toString() const {
        char buffer[11];
        sprintf(buffer, "%02d/%02d/%04d", ngay, thang, nam);
        return string(buffer);
    }
};

class Menu {
private:
    cNhanVienSX* nv;
    int n;

public:
    Menu() : nv(nullptr), n(0) {}
    ~Menu() {
        delete[] nv;
    }

    void nhapDanhSach() {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        cin.ignore();
        nv = new cNhanVienSX[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;
            nv[i].nhap();
        }
    }

    void hienThiDanhSach() const {
        cout << "Danh sach nhan vien:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Thong tin nhan vien " << i + 1 << ":" << endl;
            nv[i].xuat();
        }
    }

    void hienThiLuongThapNhat() const {
        if (n <= 0) {
            cout << "Khong co nhan vien nao!" << endl;
            return;
        }

        double minLuong = nv[0].getLuong();
        for (int i = 1; i < n; i++) {
            if (nv[i].getLuong() < minLuong) {
                minLuong = nv[i].getLuong();
            }
        }

        cout << "Nhan vien co luong thap nhat (" << fixed << setprecision(0) << minLuong << "):" << endl;
        for (int i = 0; i < n; i++) {
            if (nv[i].getLuong() == minLuong) {
                nv[i].xuat();
                cout << endl;
            }
        }
    }

    void hienThiTongLuong() const {
        double tongLuong = 0;
        for (int i = 0; i < n; i++) {
            tongLuong += nv[i].getLuong();
        }
        cout << "Tong luong cong ty phai tra: " << fixed << setprecision(0) << tongLuong << endl;
    }

    void hienThiTuoiCaoNhat() const {
        nv->tuoiCaoNhat(nv, n);
    }

    void sapXepTheoLuong() {
        sort(nv, nv + n, [](const cNhanVienSX &a, const cNhanVienSX &b) {
            return a.getLuong() < b.getLuong();
        });
        cout << "Danh sach nhan vien sap xep theo luong tang dan:" << endl;
        hienThiDanhSach();
    }

    void menu() {
        int choice;
        do {
            cout << "\n=== MENU ===\n";
            cout << "1. Nhap danh sach nhan vien\n";
            cout << "2. Xuat danh sach nhan vien\n";
            cout << "3. Hien thi nhan vien co luong thap nhat\n";
            cout << "4. Tinh tong luong cong ty phai tra\n";
            cout << "5. Hien thi nhan vien co tuoi cao nhat\n";
            cout << "6. Sap xep danh sach theo luong tang dan\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    nhapDanhSach();
                    break;
                case 2:
                    hienThiDanhSach();
                    break;
                case 3:
                    hienThiLuongThapNhat();
                    break;
                case 4:
                    hienThiTongLuong();
                    break;
                case 5:
                    hienThiTuoiCaoNhat();
                    break;
                case 6:
                    sapXepTheoLuong();
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
