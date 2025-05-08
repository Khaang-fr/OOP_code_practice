#include <iostream>
using namespace std;
#include "PhanSo.h"
PhanSo PhanSo::operator+(PhanSo b) {
    PhanSo c;
    c.tu = this->tu * b.mau + b.tu * this->mau;
    c.mau = this->mau * b.mau;
    return c;
}
PhanSo PhanSo::operator-(PhanSo b) {
    PhanSo c;
    c.tu = this->tu * b.mau - b.tu * this->mau;
    c.mau = this->mau * b.mau;
    return c;
}
PhanSo PhanSo::operator*(PhanSo b) {
    PhanSo c;
    c.tu = this->tu * b.tu;
    c.mau = this->mau * b.mau;
    return c;
}
PhanSo PhanSo::operator/(PhanSo b) {
    PhanSo c;
    c.tu = this->tu * b.mau;
    c.mau = this->mau * b.tu;
    return c;
}
bool PhanSo::operator==(PhanSo b) {
    if (this->tu * b.mau == this->mau * b.tu) {
        return true;
    } else {
        return false;
    }
}
bool PhanSo::operator>(PhanSo b) {
    if (this->tu * b.mau > this->mau * b.tu) {
        return true;
    } else {
        return false;
    }
}
bool PhanSo::operator<(PhanSo b) {
    if (this->tu * b.mau < this->mau * b.tu) {
        return true;
    } else {
        return false;
    }
}
