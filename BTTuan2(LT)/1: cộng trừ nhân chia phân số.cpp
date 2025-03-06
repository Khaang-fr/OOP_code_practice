#include <iostream>
using namespace std;

class PhanSo {
    private:
        int tu, mau;
    public:
        void nhap() {
            do {
                cin >> tu >> mau;
            } while (mau == 0);
        }
        void cong(PhanSo a, PhanSo b) {
            tu = a.tu * b.mau + b.tu * a.mau;
            mau = a.mau * b.mau;
        }
        void tru(PhanSo a, PhanSo b) {
            tu = a.tu * b.mau - b.tu * a.mau;
            mau = a.mau * b.mau;
        }
        void nhan(PhanSo a, PhanSo b) {
            tu = a.tu * b.tu;
            mau = a.mau * b.mau;
        }
        void chia(PhanSo a, PhanSo b) {
            tu = a.tu * b.mau;
            mau = a.mau * b.tu;
        }
        void rutgon() {
            int a = tu, b = mau;
            while (b != 0) {
                int r = a % b;
                a = b;
                b = r;
            }
            tu /= a;
            mau /= a;
            if (mau < 0) {
                tu = -tu;
                mau = -mau;
            }
            if (mau == 1) cout << tu;
            else cout << tu << "/" << mau;
        }
        void xuat() {
            if (mau == 1) cout << tu;
            else cout << tu << "/" << mau;
        }
};

int main() {
    PhanSo a, b;
    a.nhap();
    b.nhap();
    PhanSo c;
    c.cong(a, b);
    c.rutgon();
    c.xuat();
    c.tru(a, b);
    c.rutgon();
    c.xuat();
    c.nhan(a, b);
    c.rutgon();
    c.xuat();
    c.chia(a, b);
    c.rutgon();
    c.xuat();
    return 0;
}
