#include <string>
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846

int main() {
    cDaGiac a;
    a.Nhap();
    cout << "Loai da giac: " << a.KiemTraLoai() << endl;
    cout << "Chu vi: " << a.TinhChuVi() << endl;
    cout << "Dien tich: " << a.TinhDienTich() << endl;
    a.TinhTien();
    int n;
    cout << "Nhap goc quay: "; cin >> n;
    a.Quay(n);
    double heSo;
    cout << "Nhap he so phong to: "; cin >> heSo;
    a.PhongTo(heSo);
    cout << "Nhap he so thu nho: "; cin >> heSo;
    a.ThuNho(heSo);
    return 0;
}
