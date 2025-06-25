#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "KH.h"

class A:public KH{
public:
    A(string t,int s,double d):KH(t,s,d){}
    double tinhTien()const override{
        return sl*dg*1.1;
    }
};
