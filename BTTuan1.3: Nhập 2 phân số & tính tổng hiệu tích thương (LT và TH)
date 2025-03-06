#include <iostream> 
using namespace std;

struct PhanSo{
    int tu, mau;
};

PhanSo operator+(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau + b.tu * a.mau;
    c.mau = a.mau * b.mau;
    return c;
}

PhanSo operator-(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau - b.tu * a.mau;
    c.mau = a.mau * b.mau;
    return c;
}

PhanSo operator*(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.tu;
    c.mau = a.mau * b.mau;
    return c;
}

PhanSo operator/(PhanSo a, PhanSo b) {
    PhanSo c;
    c.tu = a.tu * b.mau;
    c.mau = a.mau * b.tu;
    return c;
}

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

PhanSo Rutgon(PhanSo a) {
    int gcd = GCD(a.tu, a.mau);
    a.tu /= gcd;
    a.mau /= gcd;
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
    return a;
}

int main () {
    PhanSo a, b;   
    do {
       cin >> a.tu >> a.mau >> b.tu >> b.mau;
    } while (a.mau == 0 || b.mau==0);
    PhanSo c = a +b;
    PhanSo d = a- b;
    PhanSo e = a * b;
    PhanSo f = a / b;
    c = Rutgon(c);
    d = Rutgon(d);
    e = Rutgon(e);
    f = Rutgon(f);
    if (c.mau == 1) cout << c.tu;
    else cout << c.tu << "/" << c.mau;
    cout << endl;
    if (d.mau == 1) cout << d.tu;
    else cout << d.tu << "/" << d.mau;
    cout << endl;
    if (e.mau == 1) cout << e.tu;
    else cout << e.tu << "/" << e.mau;
    cout << endl;
    if (f.mau == 1) cout << f.tu;
    else cout << f.tu << "/" << f.mau;
    return 0;
}
