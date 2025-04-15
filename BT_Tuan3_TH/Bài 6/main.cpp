#include <iostream> 
#include <string>
#include <vector>
using namespace std;

#include "cCandidate.h"
#include "cListCandidate.h"

int main() {
    cListCandidate test;
    test.cListCandidate::nhap();
    cout << endl;
    test.cListCandidate::xuatDanhSachDat();
    test.cListCandidate::DiemCaoNhat();
    test.cListCandidate::SapXepTongDiemGiamDan();
    cout << "\nDanh sach thi sinh sau khi sap xep: ";
    test.cListCandidate::xuatDanhSachDat();
    return 0;
}
