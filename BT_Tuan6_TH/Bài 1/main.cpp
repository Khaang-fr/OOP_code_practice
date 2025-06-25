#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<NhanVien*> danhSach;
    int nSX, nVP;
    cout << "Nhap so nhan vien san xuat: "; cin >> nSX; cin.ignore();
    for (int i = 0; i < nSX; i++) {
        NhanVien* nv = new NhanVienSanXuat();
        nv->nhap();
        danhSach.push_back(nv);
    }

    cout << "Nhap so nhan vien van phong: "; cin >> nVP; cin.ignore();
    for (int i = 0; i < nVP; i++) {
        NhanVien* nv = new NhanVienVanPhong();
        nv->nhap();
        danhSach.push_back(nv);
    }

    cout << "\nDanh sach nhan vien:\n";
    for (auto nv : danhSach)
        nv->xuat();

    double tongLuong = 0;
    for (auto nv : danhSach)
        tongLuong += nv->tinhLuong();
    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;

    double minLuongSX = 1e18;
    NhanVien* nvLuongThap = nullptr;
    int maxTuoiVP = 0;
    NhanVien* nvGiaNhat = nullptr;

    for (auto nv : danhSach) {
        if (auto sx = dynamic_cast<NhanVienSanXuat*>(nv)) {
            if (sx->tinhLuong() < minLuongSX) {
                minLuongSX = sx->tinhLuong();
                nvLuongThap = sx;
            }
        } else if (auto vp = dynamic_cast<NhanVienVanPhong*>(nv)) {
            if (vp->layTuoi() > maxTuoiVP) {
                maxTuoiVP = vp->layTuoi();
                nvGiaNhat = vp;
            }
        }
    }

    cout << "\nNhan vien san xuat co luong thap nhat:\n";
    if (nvLuongThap) nvLuongThap->xuat();

    cout << "\nNhan vien van phong co tuoi cao nhat:\n";
    if (nvGiaNhat) nvGiaNhat->xuat();

    for (auto nv : danhSach)
        delete nv;

    return 0;
}
