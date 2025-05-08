#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
#include "DaiHoc.h"
#include "CaoDang.h"
int main() {
    vector<SinhVien*> ds;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        int loai;
        cout << "1. Cao dang | 2. Dai hoc: ";
        cin >> loai;
        cin.ignore();

        SinhVien* sv;
        if (loai == 1) sv = new CaoDang();
        else sv = new DaiHoc();

        sv->nhap();
        ds.push_back(sv);
    }

    cout << "DANH SACH SINH VIEN\n";
    for (SinhVien* sv : ds) {
        sv->xuat();
    }

    cout << "SINH VIEN DAT TOT NGHIEP\n";
    for (SinhVien* sv : ds) {
        if (sv->totNghiep()) {
            sv->xuat();
        }
    }

    cout << "SINH VIEN KHONG DAT TOT NGHIEP\n";
    for (SinhVien* sv : ds) {
        if (!sv->totNghiep()) {
            sv->xuat();
        }
    }

    cout << "SINH VIEN DAI HOC CO DIEM TB CAO NHAT" << endl;
    double maxDiem = -1;
    SinhVien* bestSV = nullptr;
    for (SinhVien* sv : ds) {
        if (sv->laDaiHoc() && sv->getDiemTB() > maxDiem) {
            maxDiem = sv->getDiemTB();
            bestSV = sv;
        }
    }
    if (bestSV) bestSV->xuat();
    else cout << "Khong co sinh vien dai hoc nao.\n";

    for (SinhVien* sv : ds)
        delete sv;

    return 0;
}
