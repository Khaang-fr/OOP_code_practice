#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    friend ostream& operator<<(ostream& os, const PhanSo& ps)
    {
        if (ps.mau == 0) {
            os << "Khong hop le!";
        } else if (ps.tu == 0) {
            os << "0";
        } else if (ps.mau < 0) {
            os << -ps.tu << "/" << -ps.mau;
        } else {
            os << ps.tu << "/" << ps.mau;
        }
        return os;
    }
    friend istream& operator>>(istream& is, PhanSo& ps)
    {
        is >> ps.tu >> ps.mau;
        return is;
    }
    PhanSo operator+(PhanSo b);
    PhanSo operator-(PhanSo b);
    PhanSo operator*(PhanSo b);
    PhanSo operator/(PhanSo b);
    bool operator==(PhanSo b);
    bool operator>(PhanSo b);
    bool operator<(PhanSo b);
};
