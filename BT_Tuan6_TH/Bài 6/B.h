#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
#include "KH.h"

class B:public KH{
    int nam;
public:
    B(string t,int s,double d,int n):KH(t,s,d),nam(n){}
    double tinhTien()const override{
        double km=min(nam*0.05,0.5);
        return sl*dg*(1-km)*1.1;
    }
};
