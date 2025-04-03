#include "Diem.h"
#include "TamGiac.h"
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	TamGiac tg;
	tg.Nhap();
	cout << "Loai tam giac: " << tg.KiemTraLoai() << endl;
	cout << "Tam giac co chu vi: " << tg.TinhChuVi() << endl;
	cout << "Tam giac co dien tich: " << tg.TinhDienTich() << endl;
	cout << "Tinh tien cho tam giac: " << endl;
	tg.TinhTien();
	cout << "Tam giac sau khi tinh tien: " << endl;
	tg.Xuat();
	int n;
	cout << "Quay tam giac "; cin >> n; cout << "do." << endl;
	tg.Quay(n);
	cout << "Tam giac sau khi quay: " << endl;
	tg.Xuat();
	cout << "Phong to tam giac: " << endl;
	double heso;
	cout << "He so phong to: "; cin >> heso;
	tg.PhongTo(heso);
	cout << "Tam giac sau khi phong to: "; tg.Xuat();
	cout << "Thu nho tam giac: " << endl;
	cout << "He so thu nho: "; cin >> heso;
	tg.ThuNho(heso);
	cout << "Tam giac sau khi thu nho: "; tg.Xuat();
	return 0;
}
