#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
#include "cDSPhanSo.h"
#include "cPhanSO.h"
using namespace std;

cDSPhanSo::cDSPhanSo() {
    this->n = 0;
    arr = nullptr;
}

cDSPhanSo::cDSPhanSo(int n) : n(n) {
    arr = new cPhanSo[n];
}

cDSPhanSo::~cDSPhanSo() {
    delete[] arr;
}

void cDSPhanSo::Nhap() {
    cout << "Nhap so luong phan so: ";
    cin >> n;
    arr = new cPhanSo[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        arr[i].Nhap();
    }
}

void cDSPhanSo::Xuat() {
    cout << "Danh sach phan so: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ": ";
        arr[i].Xuat();
        cout << endl;
    }
}

void cDSPhanSo::Tong() {
    cPhanSo sum;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    cout << "Tong phan so: ";
    sum.Xuat();
    cout << endl;
}

void cDSPhanSo::Max() {
    int record = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[record]) {
            record = i;
        }
    }
    cout << "Phan so lon nhat: ";
    arr[record].Xuat();
    cout << endl;
}

void cDSPhanSo::Min() {
    int record = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[record]) {
            record = i;
        }
    }
    cout << "Phan so nho nhat: ";
    arr[record].Xuat();
    cout << endl;
}

void cDSPhanSo::TuLaSoNguyenToLonNhat() {
    int record = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].TuLaSoNguyenTo() && (record == -1 || arr[i].GetTu() > arr[record].GetTu())) {
            record = i;
        }
    }
    if (record != -1) {
        cout << "Phan so co tu la so nguyen to lon nhat: ";
        arr[record].Xuat();
        cout << endl;
    } else {
        cout << "Khong co phan so nao co tu la so nguyen to." << endl;
    }
}

void cDSPhanSo::SapXepTangDan() {
    sort(arr, arr + n, [](const cPhanSo &a, const cPhanSo &b) { return a < b; });
    cout << "Danh sach phan so sau khi sap xep tang dan: " << endl;
    Xuat();
}

void cDSPhanSo::SapXepGiamDan() {
    sort(arr, arr + n, [](const cPhanSo &a, const cPhanSo &b) { return a > b; });
    cout << "Danh sach phan so sau khi sap xep giam dan: " << endl;
    Xuat();
}

void cDSPhanSo::SapXepGiamDan() {
    mergeSort(tu, mau, 0, n - 1);
    cout << "Danh sach phan so sau khi sap xep giam dan: " << endl;
    Xuat();
}
