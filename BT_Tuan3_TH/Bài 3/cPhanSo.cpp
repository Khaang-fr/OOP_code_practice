#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "cPhanSo.h"
using namespace std;

cPhanSo::cPhanSo(int tu, int mau) : tu(tu), mau(mau) {
    if (mau == 0) {
        throw invalid_argument("Mau so khong the bang 0");
    }
    RutGon();
}

void cPhanSo::Nhap() {
    cout << "Nhap tu va mau: ";
    cin >> tu >> mau;
    if (mau == 0) {
        throw invalid_argument("Mau so khong the bang 0");
    }
    RutGon();
}

void cPhanSo::Xuat() {
    if (mau == 1) {
        cout << tu;
    } else {
        cout << tu << "/" << mau;
    }
}

void cPhanSo::RutGon() {
    int t = abs(tu), m = abs(mau);
    while (m != 0) {
        int r = t % m;
        t = m;
        m = r;
    }
    int gcd = t;
    tu /= gcd;
    mau /= gcd;
    if (mau < 0) {
        tu *= -1;
        mau *= -1;
    }
}

double cPhanSo::GiaTri() const {
    return static_cast<double>(tu) / mau;
}

bool cPhanSo::operator>(const cPhanSo &other) const {
    return tu * other.mau > other.tu * mau;
}

bool cPhanSo::operator<(const cPhanSo &other) const {
    return tu * other.mau < other.tu * mau;
}

bool cPhanSo::operator==(const cPhanSo &other) const {
    return tu * other.mau == other.tu * mau;
}

cPhanSo cPhanSo::operator+(const cPhanSo &other) const {
    int newTu = tu * other.mau + other.tu * mau;
    int newMau = mau * other.mau;
    return cPhanSo(newTu, newMau);
}

int cPhanSo::GetTu() const {
    return tu;
}

int cPhanSo::GetMau() const {
    return mau;
}

bool cPhanSo::TuLaSoNguyenTo() const {
    if (tu < 2) return false;
    for (int i = 2; i <= sqrt(tu); i++) {
        if (tu % i == 0) return false;
    }
    return true;
}
