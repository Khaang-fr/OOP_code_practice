#pragna once
class Diem
{
protected: 
        double dx, dy;
public:
	Diem();
	Diem(double x, double y);
	~Diem();
	void Nhap();
    double getDx() const { return dx; }
    double getDy() const { return dy; }
	void Xuat() const;
	void TinhTien(double x, double y);
	void Quay(int goc);
	void PhongTo(double heSo);
	void ThuNho(double heSo);
	double TinhKhoangCach(Diem a) const;
};
