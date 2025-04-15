#pragma once

#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class cCandidate 
{
    protected:
        long long mhs;
        string ten;
        int ngay, thang, nam;
        float toan, van, anh;
    public:
        cCandidate();
        ~cCandidate();
        void nhap();
        void xuat();
        float getTotalScore() const;
};
