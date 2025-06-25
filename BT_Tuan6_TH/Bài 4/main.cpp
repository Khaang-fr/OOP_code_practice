#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include "NV.h"
#include "KTV.h"
#include "LTV.h"

int main(){
    vector<NV*> v;
    int n;
    cout<<"So LTV: ";cin>>n;
    for(int i=0;i<n;i++){
        string m,t,sd,em; int tu,ot; double cb;
        cin>>m>>t>>tu>>sd>>em>>cb>>ot;
        v.push_back(new LTV(m,t,tu,sd,em,cb,ot));
    }
    cout<<"So KTV: ";cin>>n;
    for(int i=0;i<n;i++){
        string m,t,sd,em; int tu,loi; double cb;
        cin>>m>>t>>tu>>sd>>em>>cb>>loi;
        v.push_back(new KTV(m,t,tu,sd,em,cb,loi));
    }

    cout<<"\n--- DS NV ---\n";
    for(auto p:v) p->xuat();

    double sum = 0;
    for(auto p:v) sum += p->tinhLuong();
    double avg = sum/v.size();

    cout<<"\n--- NV luong < TB ---\n";
    for(auto p:v) if(p->tinhLuong()<avg) p->xuat();

    auto cmp=[&](bool findMax){
        auto it = minmax_element(v.begin(),v.end(),
            [&](NV* a,NV* b){
                return findMax ?
                    a->tinhLuong()<b->tinhLuong() :
                    a->tinhLuong()>b->tinhLuong();
            });
        return findMax? *it.second : *it.first;
    };

    cout<<"\nNV cao nhat:\n"; cmp(true)->xuat();
    cout<<"NV thap nhat:\n"; cmp(false)->xuat();

    NV* ltv = nullptr;
    double maxL = -1e18;
    for(auto p:v){
        LTV* pa = dynamic_cast<LTV*>(p);
        if(pa && pa->tinhLuong()>maxL){
            maxL = pa->tinhLuong();
            ltv = pa;
        }
    }
    if(ltv){
        cout<<"\nLTV cao nhat:\n"; ltv->xuat();
    }

    NV* ktv = nullptr;
    double minK = 1e18;
    for(auto p:v){
        KTV* pa = dynamic_cast<KTV*>(p);
        if(pa && pa->tinhLuong()<minK){
            minK = pa->tinhLuong();
            ktv = pa;
        }
    }
    if(ktv){
        cout<<"\nKTV thap nhat:\n"; ktv->xuat();
    }

    for(auto p:v) delete p;

    return 0;
}
