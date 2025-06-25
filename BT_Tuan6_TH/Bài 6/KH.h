#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class KH {
protected:
    string ten; int sl; double dg;
public:
    KH(string t,int s,double d):ten(t),sl(s),dg(d){}
    virtual double tinhTien() const=0;
    string getTen() const { return ten; }
    virtual ~KH(){}
};
