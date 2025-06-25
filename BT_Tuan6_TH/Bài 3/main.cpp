#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "SinhVien.h"

int main(){
    vector<SinhVien*> v;
    int n;
    cout<<"So sv Cao Dang: "; cin>>n;
    for(int i=0;i<n;i++){
        string m,t,d; int c; double b,tn;
        cin>>m>>t>>d>>c>>b>>tn;
        v.push_back(new CD(m,t,d,c,b,tn));
    }
    cout<<"So sv Dai Hoc: "; cin>>n;
    for(int i=0;i<n;i++){
        string m,t,d,lv; int c; double b,dlv;
        cin>>m>>t>>d>>c>>b>>lv>>dlv;
        v.push_back(new DH(m,t,d,c,b,lv,dlv));
    }
    cout<<"\n--- Danh sach SV ---\n";
    for(auto p:v) p->xuat();

    cout<<"\n--- SV Tot nghiep ---\n";
    for(auto p:v) if(p->isTotNghiep()) p->xuat();

    cout<<"\n--- SV Khong tot nghiep ---\n";
    for(auto p:v) if(!p->isTotNghiep()) p->xuat();

    auto cmpDTB=[&](bool isDH){
        vector<double> a;
        for(auto p:v)
            if((isDH && p->getLoai()=="DH") ||
               (!isDH && p->getLoai()=="CD"))
                a.push_back(p->getDTB());
        return a.empty()?0:*max_element(a.begin(),a.end());
    };

    cout<<"\nDTB cao nhat DH: "<<cmpDTB(true)
        <<"\nDTB cao nhat CD: "<<cmpDTB(false)<<endl;

    int cntDhNN=0, cntCdNN=0;
    for(auto p:v){
        if(!p->isTotNghiep()){
            if(p->getLoai()=="DH") cntDhNN++;
            else cntCdNN++;
        }
    }
    cout<<"So DH khong TN: "<<cntDhNN
        <<"\nSo CD khong TN: "<<cntCdNN<<endl;

    for(auto p:v) delete p;
    return 0;
}
