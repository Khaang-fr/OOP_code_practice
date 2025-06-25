#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class NV {
protected:
    string ms, ten; int tuoi; string sdt, email;
    double luongCB;
public:
    NV(string m,string t,int tu,string sd,string em,double cb)
     : ms(m),ten(t),tuoi(tu),sdt(sd),email(em),luongCB(cb){}
    virtual double tinhLuong() const =0;
    virtual void xuat() const {
        cout<<ms<<" "<<ten<<" "<<tuoi<<" "<<sdt<<" "<<email
            <<" "<<tinhLuong()<<"\n";
    }
    virtual ~NV(){}
};
