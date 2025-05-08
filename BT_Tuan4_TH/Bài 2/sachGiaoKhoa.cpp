#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#inclue "sachGiaoKhoa.h"
void sachGiaoKhoa::nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang cua sach: "; getline(cin, this->tinhTrang); cout << endl;
    thanhTien = this->sachGiaoKhoa::tinhThanhTien();
}

void sachGiaoKhoa::xuat() {
    Sach::Xuat();
    cout << "Tinh trang cua sach: " << this->tinhTrang << endl;
    cout << "Thanh tien tong sach la: " << this->thanhTien << endl;
}
