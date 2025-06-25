#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
    char loai;
public:
    GiaoDichDat(string m, string n, double dg, double dt, char l)
        : GiaoDich(m,n,dg,dt), loai(l) {}
    double tinhThanhTien() const override {
        if (loai == 'A') return dienTich * donGia * 1.5;
        else return dienTich * donGia;
    }
};
