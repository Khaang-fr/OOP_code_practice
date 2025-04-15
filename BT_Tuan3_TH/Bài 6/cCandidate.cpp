#include <iostream> 
#include <string>
#include <vector>
using namespace std;
#include "cCandidate.h"

cCandidate::cCandidate() {
    mhs = 0;
    ten = "";
    ngay = thang = nam = 0;
    toan = van = anh = 0.0;
}

cCandidate::~cCandidate() {

}

cListCandidate::cListCandidate() {

}

cListCandidate::~cListCandidate() {
    ds.clear();
}

void cCandidate::nhap() {
    cout << "Nhap ma hoc sinh: ";
    cin >> mhs;
    cin.ignore();
    cout << "Nhap ten hoc sinh: ";
    getline(cin, ten);
    cout << "Nhap ngay, thang, nam sinh (dd mm yyyy): ";
    cin >> ngay >> thang >> nam;
    cout << "Nhap diem Toan, Van, Anh: ";
    cin >> toan >> van >> anh; 
}

void cCandidate::xuat() {
    if (toan + van + anh > 15) {
        cout << "Ma hoc sinh: " << mhs << endl
             << "Ho ten: " << ten << endl
             << "Ngay sinh: " << ngay << " " << thang << " " << nam << endl
             << "Diem toan, van va anh: " << toan << " " << van << " " << anh << endl;
    }
}
