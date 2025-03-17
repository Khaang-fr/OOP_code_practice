#include <iostream> 
using namespace std;

//Tạo struct phân số
struct PhanSo{
    int tu, mau;
};

//Tạo hàm trả về ước chung lớn nhất
int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//Tạo hàm trả về phân số đã được rút gọn
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

    if (a.tu/a.mau > b.tu/b.mau) {              //Kiểm tra số lớn hơn
        if (a.mau == 1) cout << a.tu;
        else cout << a.tu << "/" << a.mau;
    } else {
        if (b.mau == 1) cout << b.tu;
        else cout << b.tu << "/" << b.mau;
    }
    return 0;
}
