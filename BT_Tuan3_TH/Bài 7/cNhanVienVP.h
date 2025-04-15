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

class NhanVienVP {
private:
    string maNhanVien;
    string hoTen;
    NgayThang ngaySinh;
    double luong;

public:
    NhanVienVP();
    NhanVienVP(string maNV, string ht, NgayThang ns, double l);
    NhanVienVP(string maNV, string ht, int ngay, int thang, int nam, double l);
    string getMaNhanVien() const;
    string getHoTen() const;
    NgayThang getNgaySinh() const;
    int getNgay() const;
    int getThang() const;
    int getNam() const;
    double getLuong() const;
    void setMaNhanVien(string maNV);
    void setHoTen(string ht);
    void setNgaySinh(NgayThang ns);
    void setNgaySinh(int ngay, int thang, int nam);
    void setLuong(double l);
    void nhap();
    void xuat() const;
    int tinhTuoi(int namHienTai) const;
    static void tuoiCaoNhat(NhanVienVP nv[], int n);
    static void luongCaoNhat(NhanVienVP nv[], int n);
    static double tinhTongLuong(NhanVienVP nv[], int n);
    static void sapXepTheoLuongTangDan(NhanVienVP nv[], int n);
};
