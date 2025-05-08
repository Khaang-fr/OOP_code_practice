#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include <string>
using namespace std;
void Vehicle::Nhap() {
    cout << "Nhap ma so chuyen: "; getline(cin, this->mSC);
    cout << "Nhap Ho ten: "; getline(cin, this->hoTen);
    cout << "Nhap bien kiem soat: "; getline(cin, this->soXe);
    cout << "Nhap doanh thu: "; cin >> this->doanhThu;
    cin.ignore();
}
void Vehicle::Xuat() {
    cout << "Ma so chuyen: " << this->mSC << endl;
    cout << "Ho ten: " << this->hoTen << endl;
    cout << "Bien kiem soat: " << this->soXe << endl;
    cout << "Doanh thu: " << this->doanhThu << endl;
}

double Vehicle::GetDoanhThu() {
    return this->doanhThu;
}
void Vehicle::SetDoanhThu(double dt) {
    if (dt != 0)
    {
        this->doanhThu = dt;
    }
    else {
        cout << "Doanh thu phai > 0"<<endl;
    }
}
