#pragma once
class cDaGiac : public Diem
{
    private:
        Diem *d;
        int n;
    public:
        cDaGiac();
        cDaGiac(int n);
        ~cDaGiac();
        void Nhap();
        void Xuat() const;
        string KiemTraLoai() const;
        double TinhChuVi() const;
        double TinhDienTich() const;
        void TinhTien();
        void Quay(int goc);
        void PhongTo(double heSo);
        void ThuNho(double heSo);
};
