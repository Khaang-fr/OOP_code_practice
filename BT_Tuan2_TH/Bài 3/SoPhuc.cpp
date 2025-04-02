#include "SoPhuc.h"
#include <iostream>
using namespace std;

void SoPhuc::Nhap() {
	cout << "Nhap phan thuc: "; cin >> iThuc;
	cout << "Nhap phan ao: "; cin >> iAo;
}

void SoPhuc::Xuat() {
	if (iAo != 0) {
		if (iAo > 0) {
			cout << iThuc << " + " << iAo << "i" << endl;
		}
		else {
			cout << iThuc << " - " << -iAo << "i" << endl;
		}
	}
	else {
		cout << iThuc << endl;
	}
}

void SoPhuc::Tong() {
	SoPhuc temp;
	temp.Nhap();
	temp.iThuc += iThuc;
	temp.iAo += iAo;
	cout << "Tong 2 so phuc: ";
	temp.Xuat();
}

void SoPhuc::Hieu() {
	SoPhuc temp;
	temp.Nhap();
	temp.iThuc = iThuc -  temp.iThuc;
	temp.iAo = iAo - temp.iAo;
	cout << "Hieu 2 so phuc: ";
	temp.Xuat();
}

void SoPhuc::Tich() {
	SoPhuc temp;
	temp.Nhap();
	int iThucTemp = temp.iThuc;
	temp.iThuc = iThuc * temp.iThuc - iAo * temp.iAo;
	temp.iAo = iThuc * temp.iAo + iAo * iThucTemp;
	cout << "Tich 2 so phuc: ";
	temp.Xuat();
}

void SoPhuc::Thuong() {
	SoPhuc temp;
	temp.Nhap();
	int iThucTemp = temp.iThuc;
	temp.iThuc = (iThuc * temp.iThuc + iAo * temp.iAo) / (temp.iThuc * temp.iThuc + temp.iAo * temp.iAo);
	temp.iAo = (iAo * temp.iThuc - iThuc * temp.iAo) / (temp.iThuc * temp.iThuc + temp.iAo * temp.iAo);
	cout << "Thuong 2 so phuc: ";
	temp.Xuat();
}
