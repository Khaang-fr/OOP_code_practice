#pragma once
class cDSPhanSo {
    private:
        int n;
        int *tu;
        int *mau;
    public:
        cDSPhanSo();
        cDSPhanSo(int n);
        ~cDSPhanSo();
        void Nhap();
        void Xuat();
        void Xuat(int t, int m);
        void RutGon(int &a, int &b);
        void Tong();
        void Max();
        void Min();
        void TuLaSoNguyenToLonNhat();
        void SapXepTangDan();
        void SapXepGiamDan();
};
