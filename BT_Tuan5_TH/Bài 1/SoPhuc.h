#pragma once
#include <iostream>
using namespace std;

class SoPhuc
{
private:
    float thuc, ao;
public:
    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        if (sp.ao >= 0)
            os << sp.thuc << " + " << sp.ao << "i";
        else
            os << sp.thuc << " - " << -sp.ao << "i";
        return os;
    }
    friend istream& operator>>(istream& is, SoPhuc& sp) {
        is >> sp.thuc >> sp.ao;
        return is;
    }
    SoPhuc operator+(const SoPhuc& b) const;
    SoPhuc operator-(SoPhuc b);
    SoPhuc operator*(SoPhuc b);
    SoPhuc operator/(SoPhuc b);
};
