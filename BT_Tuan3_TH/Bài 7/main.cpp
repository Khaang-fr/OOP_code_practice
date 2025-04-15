#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "cNhanVienVP.h"

int main() {
    int n;
    cin >> n;
    cin.ignore();
    NhanVienVP *nv = new NhanVienVP[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;
        nv[i].nhap();
    }

    cout << "Danh sach nhan vien sap xep theo luong tang dan:" << endl;
    NhanVienVP::sapXepTheoLuongTangDan(nv, n);
    for (int i = 0; i < n; i++) {
        cout << "Thong tin nhan vien " << i + 1 << " (Luong: " << fixed << setprecision(0) << nv[i].getLuong() << "):" << endl;
        nv[i].xuat();
    }

    cout << "Nhan vien co tuoi cao nhat:" << endl;
    NhanVienVP::tuoiCaoNhat(nv, n);

    cout << "Nhan vien co luong cao nhat:" << endl;
    NhanVienVP::luongCaoNhat(nv, n);

    cout << "Tong luong cong ty phai tra: " << endl;
    double tongLuong = NhanVienVP::tinhTongLuong(nv, n);
    cout << "Tong luong: " << fixed << setprecision(0) << tongLuong << endl;

    delete[] nv;
    return 0;
}
