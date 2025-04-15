#pragma once
#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class cListCandidate : public cCandidate
{
    private:
        vector<cCandidate> ds;
    public:
        cListCandidate();
        ~cListCandidate();
        void nhap();
        void xuatDanhSachDat();
        void DiemCaoNhat();
        void SapXepTongDiemGiamDan();
};
