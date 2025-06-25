#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "NV.h"
using namespace std;

class LTV:public NV{
    int ot;
public:
    LTV(string m,string t,int tu,string sd,string em,double cb,int o)
     : NV(m,t,tu,sd,em,cb),ot(o){}
    double tinhLuong()const override {return luongCB+ot*200000;}
};
