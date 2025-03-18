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

// So sánh hai phân số
bool LonHon(PhanSo a, PhanSo b) {
    // Chuyển về cùng mẫu số để so sánh
    long long tuso1 = (long long)a.tu * b.mau;
    long long tuso2 = (long long)b.tu * a.mau;
    
    // Nếu một mẫu số âm, kết quả so sánh sẽ bị đảo ngược
    if ((a.mau < 0 && b.mau > 0) || (a.mau > 0 && b.mau < 0))
        return tuso1 < tuso2;
    
    return tuso1 > tuso2;
}

int main () {
    PhanSo a, b;   
    do {
       cin >> a.tu >> a.mau >> b.tu >> b.mau;
    } while (a.mau == 0 || b.mau == 0);
    
    if (LonHon(a, b)) {
        a = Rutgon(a);
        if (a.mau == 1) cout << a.tu;
        else cout << a.tu << "/" << a.mau;
    } else {
        b = Rutgon(b);
        if (b.mau == 1) cout << b.tu;
        else cout << b.tu << "/" << b.mau;
    }
    return 0;
}
