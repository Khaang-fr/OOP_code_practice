#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Sach.h"

void Sach::Nhap() {
    cout << "Nhap ma sach: "; getline(cin, this->maSach);
    cout << "Nhap ngay nhap: "; cin >> this->ngayNhap.ngay >> this->ngayNhap.thang >> this->ngayNhap.nam;
    cout << "Nhap don gia cuon sach: "; cin >> this->DonGia;
    cout << "Nhap so luong cuon sach: "; cin >> this->soLuong;
    cin.ignore();
    cout << "Nhap nha xuat ban cuon sach: "; getline(cin, this->NXB);
}

void Sach::Xuat() {
    cout << "Ma sach: " << this->maSach << endl;
    cout << "Ngay nhap sach: "; this->ngayNhap.hienThi(); cout << endl;
    cout << "Don gia cua cuon sach: " << this->DonGia << " - "
         << "So luong cuon sach: " << this->soLuong << endl;
    cout << "Nha xuat ban cuon sach: " << this->NXB << endl;
}
