#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string ms, ten, diaChi;
    int tc;
    double dtb;
public:
    SinhVien(string _ms, string _ten, string _dc, int _tc, double _dtb)
      : ms(_ms), ten(_ten), diaChi(_dc), tc(_tc), dtb(_dtb) {}
    virtual bool isTotNghiep() const = 0;
    virtual double getDTB() const { return dtb; }
    virtual string getLoai() const = 0;
    virtual void xuat() const {
        cout << ms<<" "<<ten<<" "<<diaChi<<" "<<tc<<" "<<dtb;
    }
    virtual ~SinhVien() {}
};
