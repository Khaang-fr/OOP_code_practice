#include "SinhVien.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DH : public SinhVien {
    string luanVan;
    double diemLV;
public:
    DH(string m,string t,string d,int c,double b,string lv,double dlv)
      : SinhVien(m,t,d,c,b), luanVan(lv), diemLV(dlv) {}
    bool isTotNghiep() const override {
        return tc>=170 && dtb>=5 && diemLV>=5;
    }
    string getLoai() const override { return "DH"; }
    void xuat() const override {
        SinhVien::xuat();
        cout<<" "<<luanVan<<" "<<diemLV<<" ["<<(isTotNghiep()?"TN":"K TN")<<"]\n";
    }
};
