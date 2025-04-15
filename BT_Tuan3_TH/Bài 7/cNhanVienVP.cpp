#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "cNhanVienVP.h"

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

NhanVienVP::NhanVienVP() {
    maNhanVien = "";
    hoTen = "";
    ngaySinh = NgayThang();
    luong = 0.0;
}

NhanVienVP::NhanVienVP(string maNV, string ht, NgayThang ns, double l) {
    maNhanVien = maNV;
    hoTen = ht;
    ngaySinh = ns;
    luong = l;
}

NhanVienVP::NhanVienVP(string maNV, string ht, int ngay, int thang, int nam, double l) {
    maNhanVien = maNV;
    hoTen = ht;
    ngaySinh = NgayThang(ngay, thang, nam);
    luong = l;
}

string NhanVienVP::getMaNhanVien() const { return maNhanVien; }
string NhanVienVP::getHoTen() const { return hoTen; }
NgayThang NhanVienVP::getNgaySinh() const { return ngaySinh; }
int NhanVienVP::getNgay() const { return ngaySinh.ngay; }
int NhanVienVP::getThang() const { return ngaySinh.thang; }
int NhanVienVP::getNam() const { return ngaySinh.nam; }
double NhanVienVP::getLuong() const { return luong; }

void NhanVienVP::setMaNhanVien(string maNV) { maNhanVien = maNV; }
void NhanVienVP::setHoTen(string ht) { hoTen = ht; }
void NhanVienVP::setNgaySinh(NgayThang ns) { ngaySinh = ns; }
void NhanVienVP::setNgaySinh(int ngay, int thang, int nam) { ngaySinh = NgayThang(ngay, thang, nam); }
void NhanVienVP::setLuong(double l) { luong = l; }

void NhanVienVP::nhap() {
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
    cout << "Nhap luong: ";
    cin >> luong;
    cin.ignore();
}

void NhanVienVP::xuat() const {
    cout << "Ma nhan vien: " << maNhanVien << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: ";
    ngaySinh.hienThi();
    cout << endl;
    cout << "Luong: " << luong << endl;
}

int NhanVienVP::tinhTuoi(int namHienTai) const {
    return namHienTai - ngaySinh.nam;
}

void NhanVienVP::tuoiCaoNhat(NhanVienVP nv[], int n) {
    if (n <= 0) {
        cout << "Khong co nhan vien nao!" << endl;
        return;
    }

    int maxTuoi = nv[0].tinhTuoi(2025);
    for (int i = 1; i < n; i++) {
        maxTuoi = max(maxTuoi, nv[i].tinhTuoi(2025));
    }

    cout << "Nhan vien cao tuoi nhat la:" << endl;
    for (int i = 0; i < n; i++) {
        if (nv[i].tinhTuoi(2025) == maxTuoi) {
            nv[i].xuat();
            cout << endl;
        }
    }
}

void NhanVienVP::luongCaoNhat(NhanVienVP nv[], int n) {
    if (n <= 0) {
        cout << "Khong co nhan vien nao!" << endl;
        return;
    }

    double maxLuong = nv[0].luong;
    for (int i = 1; i < n; i++) {
        if (nv[i].luong > maxLuong) {
            maxLuong = nv[i].luong;
        }
    }

    cout << "Nhan vien co luong cao nhat (" << fixed << setprecision(0) << maxLuong << "):" << endl;
    for (int i = 0; i < n; i++) {
        if (nv[i].luong == maxLuong) {
            nv[i].xuat();
            cout << endl;
        }
    }
}

double NhanVienVP::tinhTongLuong(NhanVienVP nv[], int n) {
    double tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += nv[i].luong;
    }
    return tongLuong;
}

void NhanVienVP::sapXepTheoLuongTangDan(NhanVienVP nv[], int n) {
    sort(nv, nv + n, [](const NhanVienVP &a, const NhanVienVP &b) {
        return a.luong < b.luong;
    });
}
