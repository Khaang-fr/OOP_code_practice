#pragma once
#include <iostream>
using namespace std;
class NgayThangNam
{
private:
	int iNgay = 1, iThang = 1, iNam = 1;
public:
	void Nhap();
	void Xuat() const;
	void NgayThangNamTiepTheo() const;
};
