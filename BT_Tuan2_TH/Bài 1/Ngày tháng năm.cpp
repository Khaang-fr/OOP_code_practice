#include "NgayThangNam.h"
#include <iostream>
using namespace std;

static bool namnhuan(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int maxDay(int thang, int nam) {
	switch (thang) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (namnhuan(nam)) {
			return 29;
		}
		else {
			return 28;
		}
	default:
		return 0;
	}
}

void NgayThangNam::Nhap() {
	do {
		cout << "Nhap ngay: ";
		cin >> iNgay;
		cout << "Nhap thang: ";
		cin >> iThang;
		cout << "Nhap nam: ";
		cin >> iNam;

		if (iThang < 1 || iThang > 12) {
			cout << "Thang khong hop le. Vui long nhap lai." << endl;
			continue;
		}

		int max = maxDay(iThang, iNam);
		if (iNgay < 1 || iNgay > max) {
			cout << "Ngay khong hop le. Vui long nhap lai." << endl;
			continue;
		}
		if (iNam < 0) {
			cout << "Nam khong hop le. Vui long nhap lai." << endl;
			continue;
		}

		break;
	} while (true);
}

void NgayThangNam::Xuat() const {
	cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

void NgayThangNam::NgayThangNamTiepTheo() const {
	int max = maxDay(iThang, iNam);
	if (iNgay < max) {
		cout << iNgay + 1 << "/" << iThang << "/" << iNam;
		return;
	}
	else {
		if (iThang != 12) {
			cout << "1/" << iThang + 1 << "/" << iNam;
			return;
		}
		else {
			cout << "1/1/" << iNam + 1;
			return;
		}
	}
}
