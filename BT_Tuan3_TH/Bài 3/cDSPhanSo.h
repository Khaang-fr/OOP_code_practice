#pragma once
#include "cPhanSo.h"
class cDSPhanSo {
    private:
        int n;
        cPhanSo *arr;
    public:
        cDSPhanSo();
        cDSPhanSo(int n);
        ~cDSPhanSo();
        void Nhap();
        void Xuat();
        void Tong();
        void Max();
        void Min();
        void TuLaSoNguyenToLonNhat();
        void SapXepTangDan();
        void SapXepGiamDan();
};
