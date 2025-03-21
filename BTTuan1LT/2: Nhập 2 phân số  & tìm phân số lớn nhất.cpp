#include <iostream> 
using namespace std;

struct PhanSo{
    int tu, mau;
};

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
    a = Rutgon(a);
    b = Rutgon(b);
    if (a.tu/a.mau > b.tu/b.mau) {
        if (a.mau == 1) cout << a.tu;
        else cout << a.tu << "/" << a.mau;
    } else {
        if (b.mau == 1) cout << b.tu;
        else cout << b.tu << "/" << b.mau;
    }
    return 0;
}
