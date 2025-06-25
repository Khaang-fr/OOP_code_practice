#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "SinhVien.h"

class CD : public SinhVien {
    double thiTN;
public:
    CD(string m,string t,string d,int c,double b,double tn)
      : SinhVien(m,t,d,c,b), thiTN(tn) {}
    bool isTotNghiep() const override {
        return tc>=120 && dtb>=5 && thiTN>=5;
    }
    string getLoai() const override { return "CD"; }
    void xuat() const override {
        SinhVien::xuat();
        cout<<" "<<thiTN<<" ["<<(isTotNghiep()?"TN":"K TN")<<"]\n";
    }
};
