#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
#include "cDSPhanSo.h"
using namespace std;

cDSPhanSo::cDSPhanSo() {
    n = 0;
    tu = nullptr;
    mau = nullptr;
}
cDSPhanSo::cDSPhanSo(int n) {
    this->n = n;
    tu = new int[n];
    mau = new int [n];
}
cDSPhanSo::~cDSPhanSo() {
    if (tu != nullptr) {
        delete[] tu;
        tu = nullptr;
    }
    if (mau != nullptr) {
        delete[] mau;
        mau = nullptr;
    }
}
void cDSPhanSo::Nhap() {
    cout << "Nhap so luong phan so: ";
    cin >> n;
    tu = new int[n];
    mau = new int [n];
    for (int i=0; i<n; i++) {
        cout << "Nhap phan so thu " << i+1 << ": ";
        cin >> tu[i]; cin >> mau[i];
    }
}
void cDSPhanSo::Xuat() {
    cout << "Danh sach phan so: " << endl;
    for (int i =0; i<n; i++) {
        RutGon(tu[i], mau[i]);
        cout << "Phan so thu " << i+1 << ": ";
        if (mau[i] == 1) {
            cout << tu[i] << endl;
        } else {
            cout << tu[i] << "/" << mau[i] << endl;
        }
    }
}
void cDSPhanSo::Xuat(int t, int m) {
    RutGon(t, m);
    if (m == 1) {
        cout << t << endl;
    } else {
        cout << t << "/" << m << endl;
    }
}
void cDSPhanSo::RutGon(int &a, int &b) {
    int t = abs(a), m = abs(b);
    while (m != 0) {
        int r = t % m;
        t = m;
        m = r;
    }
    int gcd = t;
    a /= gcd;
    b /= gcd;
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
}
void cDSPhanSo::Tong() {
    int t = 0, m = 0;
    for (int  i = 0; i< n; i++) {
        if (m == 0) {
            t = tu[i];
            m = mau[i];
        } else {
            t = t * mau[i] + tu[i] * m;
            m = m * mau[i];
        }
    }
    cout << "Tong phan so: ";
    RutGon(t, m);
    Xuat(t, m);
}
void cDSPhanSo::Max() {
    int record = 0;
    for (int i = 0; i< n; i++){
        if (tu[i] * mau[record] > tu[record] * mau[i]) {
            record = i;
        }
    }
    cout << "Phan so lon nhat: ";
    RutGon(tu[record], mau[record]);
    Xuat(tu[record], mau[record]);
}
void cDSPhanSo::Min() {
    int record = 0;
    for (int i = 0; i< n; i++){
        if (tu[i] * mau[record] < tu[record] * mau[i]) {
            record = i;
        }
    }
    cout << "Phan so nho nhat: ";
    RutGon(tu[record], mau[record]);
    Xuat(tu[record], mau[record]);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void cDSPhanSo::TuLaSoNguyenToLonNhat() {
    int record = -1;
    for (int i = 0; i< n; i++){
        if (isPrime(tu[i]) && (record == -1 || tu[i] > tu[record])) {
            record = i;
        }
    }
    if (record != -1) {
        cout << "Phan so co tu la so nguyen to lon nhat: ";
        RutGon(tu[record], mau[record]);
        Xuat(tu[record], mau[record]);
    } else {
        cout << "Khong co phan so nao co tu la so nguyen to." << endl;
    }
}

void merge_decending(int *tu, int *mau, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L_tu = new int[n1], *L_mau = new int[n1];
    int *R_tu = new int[n2], *R_mau = new int[n2];

    for (int i = 0; i < n1; i++) {
        L_tu[i] = tu[left + i];
        L_mau[i] = mau[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R_tu[j] = tu[mid + 1 + j];
        R_mau[j] = mau[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L_tu[i] * R_mau[j] >= R_tu[j] * L_mau[i]) {
            tu[k] = L_tu[i];
            mau[k] = L_mau[i];
            i++;
        } else {
            tu[k] = R_tu[j];
            mau[k] = R_mau[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tu[k] = L_tu[i];
        mau[k] = L_mau[i];
        i++;
        k++;
    }

    while (j < n2) {
        tu[k] = R_tu[j];
        mau[k] = R_mau[j];
        j++;
        k++;
    }

    delete[] L_tu;
    delete[] L_mau;
    delete[] R_tu;
    delete[] R_mau;
}

void merge_ascending(int *tu, int *mau, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L_tu = new int[n1], *L_mau = new int[n1];
    int *R_tu = new int[n2], *R_mau = new int[n2];

    for (int i = 0; i < n1; i++) {
        L_tu[i] = tu[left + i];
        L_mau[i] = mau[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R_tu[j] = tu[mid + 1 + j];
        R_mau[j] = mau[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L_tu[i] * R_mau[j] <= R_tu[j] * L_mau[i]) {
            tu[k] = L_tu[i];
            mau[k] = L_mau[i];
            i++;
        } else {
            tu[k] = R_tu[j];
            mau[k] = R_mau[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tu[k] = L_tu[i];
        mau[k] = L_mau[i];
        i++;
        k++;
    }

    while (j < n2) {
        tu[k] = R_tu[j];
        mau[k] = R_mau[j];
        j++;
        k++;
    }

    delete[] L_tu;
    delete[] L_mau;
    delete[] R_tu;
    delete[] R_mau;
}

void mergeSort(int *tu, int *mau, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(tu, mau, left, mid);
        mergeSort(tu, mau, mid + 1, right);
        merge_ascending(tu, mau, left, mid, right);
    }
}

void cDSPhanSo::SapXepTangDan() {
    mergeSort(tu, mau, 0, n - 1);
    cout << "Danh sach phan so sau khi sap xep tang dan: " << endl;
    Xuat();
}

void cDSPhanSo::SapXepGiamDan() {
    mergeSort(tu, mau, 0, n - 1);
    cout << "Danh sach phan so sau khi sap xep giam dan: " << endl;
    Xuat();
}
