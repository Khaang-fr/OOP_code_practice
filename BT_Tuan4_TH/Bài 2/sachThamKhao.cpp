#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "sachThamKhao.h"
void sachThamKhao::nhap() {
    Sach::Nhap();
    cout << "Nhap so thue: "; cin >> this->thue;
    cin.ignore();
    this->thanhTien = sachThamKhao::tinhThanhTien();
}

void sachThamKhao::xuat() {
    Sach::Xuat();
    cout << "Thue: " << this->thue << endl;
    cout << "Thanh tien tong sach la: " << this->thanhTien << endl;
}
