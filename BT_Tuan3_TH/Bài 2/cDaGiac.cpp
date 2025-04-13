#include "cDaGiac.h"
#include "Diem.h"
#include <string>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846

cDaGiac::cDaGiac() {
    n = 0;
    d = nullptr;
}

cDaGiac::cDaGiac(int a) {
    this->n = a;
    d = new Diem[n];
}

cDaGiac::~cDaGiac() {
    if (d != nullptr) {
        delete[] d;
        d = nullptr;
    }
}

void cDaGiac::Nhap() {
    cout << "Nhap so dinh: "; cin >> n;
    if (n < 3) {
        cout << "Khong phai da giac" << endl;
        exit(0);
    }
    d = new Diem[n];
    for (int i = 0; i < n; i++) {
        cout <<  "Nhap dinh " << i + 1 << ": " << endl;
        d[i].Diem::Nhap();
    }
    cout << endl;
}

void cDaGiac::Xuat() const {
    cout << "Da giac co " << n << " dinh: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        d[i].Diem::Xuat();
    }
}

string cDaGiac::KiemTraLoai() const {
    if (n < 3) {
        return "Khong phai da giac";
    }
    else if (n == 3) {
        return "Tam giac";
    }
    else if (n == 4) {
        return "Tu giac";
    }
    else if (n == 5) {
        return "Ngu giac";
    }
    else if (n == 6) {
        return "Luc giac";
    }
    else {
        return "Da giac";
    }
}

double cDaGiac::TinhChuVi() const {
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        chuVi += d[i].TinhKhoangCach(d[(i+1) % n]);
    }
    return chuVi;
}
double cDaGiac::TinhDienTich() const {
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        dienTich += d[i].getDx() * d[(i + 1) % n].getDy() - d[(i + 1) % n].getDx() * d[i].getDy();
    }
    return abs(dienTich) / 2;
}
void cDaGiac::TinhTien() {
    double x, y;
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    for (int i = 0; i < n; i++) {
        d[i].TinhTien(x, y);
    }
    cout << "\nDa giac sau khi tinh tien: " << endl;
    Xuat();
}
void cDaGiac::Quay(int goc) {
    for (int i = 0; i < n; i++) {
        d[i].Quay(goc);
    }
    cout << "\nDa giac sau khi quay: " << endl;
    Xuat();
}
void cDaGiac::PhongTo(double heSo) {
    for (int i = 0; i < n; i++) {
        d[i].PhongTo(heSo);
    }
    cout << "Da giac sau khi phong to: " << endl;
    Xuat();
}
void cDaGiac::ThuNho(double heSo) {
    for (int i = 0; i < n; i++) {
        d[i].ThuNho(heSo);
    }
    cout << "Da giac sau khi thu nho: " << endl;
    Xuat();
}
