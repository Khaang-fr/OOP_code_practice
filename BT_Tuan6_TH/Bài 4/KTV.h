#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include "NV.h"

class KTV:public NV{
    int loi;
public:
    KTV(string m,string t,int tu,string sd,string em,double cb,int l)
     : NV(m,t,tu,sd,em,cb),loi(l){}
    double tinhLuong()const override {return luongCB+loi*50000;}
};
