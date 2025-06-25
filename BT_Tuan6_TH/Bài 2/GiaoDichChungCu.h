#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "GiaoDich.h"

class GiaoDichChungCu : public GiaoDich {
    string maCan;
    int tang;
public:
    GiaoDichChungCu(string m, string n, double dg, double dt, string mc, int t)
        : GiaoDich(m,n,dg,dt), maCan(mc), tang(t) {}
    double tinhThanhTien() const override {
        if (tang == 1) return dienTich * donGia * 2;
        if (tang >= 15) return dienTich * donGia * 1.2;
        return dienTich * donGia;
    }
    void xuat() const override {
        cout << ma << " | " << ngay << " | " << fixed << setprecision(2) << tinhThanhTien()
             << " | " << maCan << " | Tang " << tang << endl;
    }
};
