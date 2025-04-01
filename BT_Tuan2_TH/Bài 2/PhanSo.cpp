#include "PhanSo.h"
#include <iostream>
using namespace std;

int __gcd(int tu, int mau) {
    while (mau != 0) {
        int temp = mau;
        mau = tu % mau;
        tu = temp;
    }
    return tu;
}

void NhapPhanSo(int& tu, int& mau) {
    cout << "Nhap tu so cua phan so thu 2: ";
    cin >> tu;
    cout << "Nhap mau so cua phan so thu 2: ";
    cin >> mau;
    if (mau == 0) {
        cout << "Mau phai khac 0";
        exit(1);
    }
}

void TinhToan(int& tu1, int& mau1, int tu2, int mau2, char phepToan) {
    switch (phepToan) {
    case '+':
        tu1 = tu1 * mau2 + tu2 * mau1;
        mau1 = mau1 * mau2;
        break;
    case '-':
        tu1 = tu1 * mau2 - tu2 * mau1;
        mau1 = mau1 * mau2;
        break;
    case '*':
        tu1 = tu1 * tu2;
        mau1 = mau1 * mau2;
        break;
    case '/':
        tu1 = tu1 * mau2;
        mau1 = mau1 * tu2;
        break;
    }
}

void PhanSo::Nhap() {
    cout << "Nhap tu so: ";
    cin >> iTu;
    cout << "Nhap mau so: ";
    cin >> iMau;
    if (iMau == 0) {
        cout << "Mau phai khac 0";
        exit(1);
    }
}

void PhanSo::Xuat() const {
    if (iMau != 1) {
        cout << iTu << "/" << iMau << endl;
    }
    else {
        cout << iTu << endl;
    }
}

void PhanSo::RutGon() {
    int gcd = __gcd(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

void PhanSo::Tong() {
    int tu2, mau2;
    NhapPhanSo(tu2, mau2);
    int tuResult = iTu * mau2 + tu2 * iMau;
    int mauResult = iMau * mau2;
    PhanSo result;
    result.iTu = tuResult;
    result.iMau = mauResult;
    result.RutGon();
    cout << "Ket qua tong: ";
    result.Xuat();
}

void PhanSo::Hieu() {
    int tu2, mau2;
    NhapPhanSo(tu2, mau2);
    int tuResult = iTu * mau2 - tu2 * iMau;
    int mauResult = iMau * mau2;
    PhanSo result;
    result.iTu = tuResult;
    result.iMau = mauResult;
    result.RutGon();
    cout << "Ket qua hieu: ";
    result.Xuat();
}

void PhanSo::Tich() {
    int tu2, mau2;
    NhapPhanSo(tu2, mau2);
    int tuResult = iTu * tu2;
    int mauResult = iMau * mau2;
    PhanSo result;
    result.iTu = tuResult;
    result.iMau = mauResult;
    result.RutGon();
    cout << "Ket qua tich: ";
    result.Xuat();
}

void PhanSo::Thuong() {
    int tu2, mau2;
    NhapPhanSo(tu2, mau2);
    int tuResult = iTu * mau2;
    int mauResult = iMau * tu2;
    PhanSo result;
    result.iTu = tuResult;
    result.iMau = mauResult;
    result.RutGon();
    cout << "Ket qua thuong: ";
    result.Xuat();
}

void PhanSo::SoSanh() {
    int tu2, mau2;
    NhapPhanSo(tu2, mau2);
    int tuResult = iTu * mau2 - tu2 * iMau;
    if (tuResult < 0) {
        cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
    }
    else if (tuResult > 0) {
        cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
    }
    else {
        cout << "Hai phan so bang nhau." << endl;
    }
}
