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

int main () {
    PhanSo a;   
    do {
       cin >> a.tu >> a.mau;
    } while (a.mau == 0);
    int gcd = GCD(a.tu, a.mau);
    a.tu /= gcd;
    a.mau /= gcd;
    if (a.mau < 0) {
        a.tu = -a.tu;
        a.mau = -a.mau;
    }
    if (a.mau == 1) cout << a.tu;
    else cout << a.tu << "/" << a.mau;
    return 0;
}
