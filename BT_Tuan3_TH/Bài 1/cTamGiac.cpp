#include "TamGiac.h"
#include "Diem.h"
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

TamGiac::TamGiac() {
	A = Diem(0, 0);
	B = Diem(0, 0);
	C = Diem(0, 0);
}

TamGiac::TamGiac(Diem a, Diem b, Diem c) {
	A = a;
	B = b;
	C = c;
}

TamGiac::TamGiac(const TamGiac& tg) {
	A = tg.A;
	B = tg.B;
	C = tg.C;
}

TamGiac::~TamGiac() {}

void TamGiac::Nhap() {
	cout << "Nhap 3 diem A, B, C: \n";
	A.Nhap();
	B.Nhap();
	C.Nhap();
}

void TamGiac::Xuat() {
	cout << "Diem A: "; A.Xuat();
	cout << "Diem B: "; B.Xuat();
	cout << "Diem C: "; C.Xuat();
}

string TamGiac::KiemTraLoai() {
	double AB = A.TinhKhoangCach(B);
	double AC = A.TinhKhoangCach(C);
	double BC = B.TinhKhoangCach(C);
	if (AB == AC && AB == BC) {
		return "Tam giac deu";
	}
	else if (AB == AC || AB == BC || AC == BC) {
		return "Tam giac can";
	}
	else if (pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || pow(AC, 2) + pow(BC, 2) == pow(AB, 2)) {
		return "Tam giac vuong";
	}
	else {
		return "Tam giac thuong";
	}
}

double TamGiac::TinhChuVi() {
	double AB = A.TinhKhoangCach(B);
	double AC = A.TinhKhoangCach(C);
	double BC = B.TinhKhoangCach(C);
	return AB + AC + BC;
}

double TamGiac::TinhDienTich() {
	double AB = A.TinhKhoangCach(B);
	double AC = A.TinhKhoangCach(C);
	double BC = B.TinhKhoangCach(C);
	double p = (AB + AC + BC) / 2;
	return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

void TamGiac::TinhTien() {
	double dx1, dy1;
	cout << "Nhap khoang cach dx, dy: ";
	cin >> dx1 >> dy1;
	A.TinhTien(dx1, dy1);
	B.TinhTien(dx1, dy1);
	C.TinhTien(dx1, dy1);
}

void TamGiac::Quay(int goc) {
	A.Quay(goc);
	B.Quay(goc);
	C.Quay(goc);
}

void TamGiac::PhongTo(double heSo) {
	A.PhongTo(heSo);
	B.PhongTo(heSo);
	C.PhongTo(heSo);
}

void TamGiac::ThuNho(double heSo) {
	A.ThuNho(heSo);
	B.ThuNho(heSo);
	C.ThuNho(heSo);
}
