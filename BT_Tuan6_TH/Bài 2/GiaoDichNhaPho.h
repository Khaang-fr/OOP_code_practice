#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
    string loai;
    string diaChi;
public:
    GiaoDichNhaPho(string m, string n, double dg, double dt, string l, string dc)
        : GiaoDich(m,n,dg,dt), loai(l), diaChi(dc) {}
    double tinhThanhTien() const override {
        if (loai == "cao cap") return dienTich * donGia;
        else return dienTich * donGia * 0.9;
    }
    void xuat() const override {
        cout << ma << " | " << ngay << " | " << fixed << setprecision(2) << tinhThanhTien()
             << " | " << loai << " | " << diaChi << endl;
    }
};
