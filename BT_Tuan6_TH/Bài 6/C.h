#include "KH.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class C:public KH{
public:
    C(string t,int s,double d):KH(t,s,d){}
    double tinhTien()const override{
        return sl*dg*0.5*1.1;
    }
};
