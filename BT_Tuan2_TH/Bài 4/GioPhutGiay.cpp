#include "GioPhutGiay.h"
#include <iostream>
using namespace std;

void GioPhutGiay::Nhap() {
	cout << "Nhap gio: "; cin >> iGio;
	cout << "Nhap phut: "; cin >> iPhut;
	cout << "Nhap giay: "; cin >> iGiay;
	if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
		cout << "Du lieu nhap khong hop le. Nhap lai: " << endl;
		Nhap();
	}
}

void GioPhutGiay::Xuat() {
	cout << "Thoi gian: " << iGio << " gio, " << iPhut << " phut, " << iGiay << " giay." << endl;
}

void GioPhutGiay::TinhCongThemMotGiay() {
	iGiay++;
	if (iGiay == 60) {
		iGiay = 0;
		iPhut++;
		if (iPhut == 60) {
			iPhut = 0;
			iGio++;
			if (iGio == 24) {
				iGio = 0;
			}
		}
	}
	cout << "Thoi gian sau khi cong them 1 giay: " << iGio << " gio, " << iPhut << " phut, " << iGiay << " giay." << endl;
}
