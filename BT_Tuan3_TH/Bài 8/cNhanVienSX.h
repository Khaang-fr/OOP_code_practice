#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

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

class cNhanVienSX {
private:
    string maNhanVien;
    string hoTen;
    NgayThang ngaySinh;
    int soSP;
    double donGia;

    double luong;

public:
    cNhanVienSX() {
        maNhanVien = "";
        hoTen = "";
        ngaySinh = NgayThang();
        soSP = 0;
        donGia = 0.0;
        luong = 0.0;
    }
    cNhanVienSX(string maNV, string ht, NgayThang ns, int so, double gia) {
        maNhanVien = maNV;
        hoTen = ht;
        ngaySinh = ns;
        soSP = so;
        donGia = gia;
        luong = double(so* gia);
    }
    cNhanVienSX(string maNV, string ht, int ngay, int thang, int nam, int so, double gia) {
        maNhanVien = maNV;
        hoTen = ht;
        ngaySinh = NgayThang(ngay, thang, nam);
        soSP = so;
        donGia = gia;
        luong = double(so* gia);
    }
    string getMaNhanVien() const {
        return maNhanVien;
    }
    string getHoTen() const {
        return hoTen;
    }
    NgayThang getNgaySinh() const {
        return ngaySinh;
    }
    int getNgay() const {
        return ngaySinh.ngay;
    }
    int getThang() const {
        return ngaySinh.thang;
    }
    int getNam() const {
        return ngaySinh.nam;
    }
    int getSoSP() const {
        return soSP;
    }
    double getDonGia() const {
        return donGia;
    }
    double getLuong() const {
        return luong;
    }
    void setMaNhanVien(string maNV) {
        maNhanVien = maNV;
    }
    void setHoTen(string ht) {
        hoTen = ht;
    }
    void setNgaySinh(NgayThang ns) {
        ngaySinh = ns;
    }
    void setNgaySinh(int ngay, int thang, int nam) {
        ngaySinh.ngay = ngay;
        ngaySinh.thang = thang;
        ngaySinh.nam = nam;
    }
    void setSoSP (int SP) {
        soSP = SP;
    }
    void setDonGia (double gia) {
        donGia = gia;
    }
    void setLuong(double l) {
        luong = l;
    }
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNhanVien);
        
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        
        cout << "Nhap ngay sinh:" << endl;
        cout << "  Ngay: ";
        cin >> ngaySinh.ngay;
        cout << "  Thang: ";
        cin >> ngaySinh.thang;
        cout << "  Nam: ";
        cin >> ngaySinh.nam;
        
        cout << "Nhap so san pham da gia cong: ";
        cin >> soSP;
        cout << "Nhap don gia tung san pham: ";
        cin >> donGia;
        luong = soSP * donGia;
        cin.ignore();
    }
    void xuat() const {
        cout << "Ma nhan vien: " << maNhanVien << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: ";
        ngaySinh.hienThi();
        cout << endl;
        cout << "So san pham: " << soSP << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Luong: " << luong << endl;
    }
    int tinhTuoi(int namHienTai) const {
        return namHienTai - ngaySinh.nam;
    }
    void tuoiCaoNhat (cNhanVienSX nv[], int n) {
        int Max=0;
        for (int i=0; i<n; i++) {
            int temp = nv[i].tinhTuoi(2025);
            Max = max(temp, Max);
        }
        cout << "Nhan vien cao tuoi nhat la:" << endl;
        for (int i=0; i<n; i++) {
            if (nv[i].tinhTuoi(2025) == Max) {
                nv[i].xuat();
                cout << endl;
            }
        }
    }
};
