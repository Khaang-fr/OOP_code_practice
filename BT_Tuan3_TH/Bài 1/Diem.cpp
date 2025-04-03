#include "Diem.h"
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846

Diem::Diem() {
	dx = 0;
	dy = 0;
}

Diem::Diem(double x, double y) {
	dx = x;
	dy = y;
}

Diem::~Diem() {}

void Diem::Nhap() {
	cout << "x: "; cin >> dx;
	cout << "y: "; cin >> dy;
	cout << endl;
}

void Diem::Xuat() const {
	cout << "(" << dx << ", " << dy << ")" << endl;
}

void Diem::TinhTien(double dx1, double dy1) {
	dx += dx1;
	dy += dy1;
}

void Diem::Quay(int goc) {
	double radian = goc * M_PI / 180;
	double x = dx * cos(radian) - dy * sin(radian);
	double y = dx * sin(radian) + dy * cos(radian);
	dx = x;
	dy = y;
}

void Diem::PhongTo(double heSo) {
	dx *= heSo;
	dy *= heSo;
}

void Diem::ThuNho(double heSo) {
	dx /= heSo;
	dy /= heSo;
}

double Diem::TinhKhoangCach(Diem a) const {
	return sqrt(pow(dx - a.dx, 2) + pow(dy - a.dy, 2));
}
