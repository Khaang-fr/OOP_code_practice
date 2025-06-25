#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class GiaoDich {
protected:
    string ma, ngay;
    double donGia, dienTich;
public:
    GiaoDich(string _ma, string _ngay, double _dg, double _dt)
        : ma(_ma), ngay(_ngay), donGia(_dg), dienTich(_dt) {}
    virtual double tinhThanhTien() const = 0;
    string getNgay() const { return ngay; }
    virtual void xuat() const {
        cout << ma << " | " << ngay << " | " << fixed << setprecision(2) << tinhThanhTien() << endl;
    }
    virtual ~GiaoDich() {}
};
