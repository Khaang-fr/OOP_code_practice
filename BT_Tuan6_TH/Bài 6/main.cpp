#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main(){
    ifstream in("XYZ.INP");
    ofstream out("XYZ.OUT");
    int x,y,z; in>>x>>y>>z;
    vector<KH*> v;
    string ten; int sl; double dg;
    for(int i=0;i<x;i++){
        in>>ws; getline(in,ten);
        in>>sl>>dg;
        v.push_back(new A(ten,sl,dg));
    }
    for(int i=0;i<y;i++){
        in>>ws; getline(in,ten);
        in>>sl>>dg;
        int nam; in>>nam;
        v.push_back(new B(ten,sl,dg,nam));
    }
    for(int i=0;i<z;i++){
        in>>ws; getline(in,ten);
        in>>sl>>dg;
        v.push_back(new C(ten,sl,dg));
    }

    double tong=0;
    for(auto p:v){
        double tt=p->tinhTien();
        cout<<p->getTen()<<' '<<fixed<<setprecision(2)<<tt<<"\n";
        tong+=tt;
    }
    out<<"TongSoTienCongTy "<<fixed<<setprecision(2)<<tong<<"\n";
    for(auto p:v) delete p;
    in.close(); out.close();
    return 0;
}
