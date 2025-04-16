#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
class cPhanSo {
    private:
        int tu;
        int mau;
    public:
        cPhanSo(int tu = 0, int mau = 1);
        void Nhap();
        void Xuat();
        void RutGon();
        double GiaTri() const;
        bool operator>(const cPhanSo &other) const;
        bool operator<(const cPhanSo &other) const;
        bool operator==(const cPhanSo &other) const;
        cPhanSo operator+(const cPhanSo &other) const;
        int GetTu() const;
        int GetMau() const;
        bool TuLaSoNguyenTo() const;
};
