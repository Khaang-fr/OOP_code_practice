#pragma once
#include <string>
#include "Diem.h"
using namespace std;
class TamGiac 
{
private:
	Diem A, B, C;
public:
	TamGiac();
	TamGiac(Diem a, Diem b, Diem c);
	TamGiac(const TamGiac& tg);
	~TamGiac();
	void Nhap();
	void Xuat();
	string KiemTraLoai();
	double TinhChuVi();
	double TinhDienTich();
	void TinhTien();
	void Quay(int goc);
	void PhongTo(double heSo);
	void ThuNho(double heSo);
};

