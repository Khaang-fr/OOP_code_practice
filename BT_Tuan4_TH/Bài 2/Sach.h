#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct NgayThang {
    int ngay, thang, nam;
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
class Sach {
private:
    string maSach;
    NgayThang ngayNhap;
    double DonGia;
    int soLuong;
    string NXB;
public:
    Sach() {
        maSach = "";
        ngayNhap = NgayThang();
        DonGia = 0.0;
        soLuong = 0;
        NXB = "";
    }
    Sach(string ma, NgayThang Ngay, double gia, int luong, string nxb) {
        maSach = ma;
        ngayNhap = NgayThang(Ngay.ngay, Ngay.thang, Ngay.nam);
        DonGia = gia;
        soLuong = luong;
        NXB = nxb;
    }
    Sach(string ma, int ngay, int thang, int nam, double gia, int luong, string nxb) {
        maSach = ma;
        ngayNhap = NgayThang(ngay, thang, nam);
        DonGia = gia;
        soLuong = luong;
        NXB = nxb;
    }
    void Nhap();
    void Xuat();
    double getDonGia() const {
        return DonGia;
    }
    int getSoLuong() const {
        return soLuong;
    }
    string getNXB() const {
        return NXB;
    }
    virtual ~Sach() {
        cout << "bye!" << endl;
    }
};
