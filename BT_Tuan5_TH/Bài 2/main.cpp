#include <iostream>
using namespace std;
#include "PhanSo.h"

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat (tu/mau): ";
    cin >> ps1;
    cout << "Nhap phan so thu hai (tu/mau): ";
    cin >> ps2;

    cout << "Phan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;

    PhanSo sum = ps1 + ps2;
    cout << "Tong hai phan so: " << sum << endl;

    PhanSo diff = ps1 - ps2;
    cout << "Hieu hai phan so: " << diff << endl;

    PhanSo prod = ps1 * ps2;
    cout << "Tich hai phan so: " << prod << endl;

    PhanSo quot = ps1 / ps2;
    cout << "Thuong hai phan so: " << quot << endl;

    if (ps1 == ps2) {
        cout << "Hai phan so bang nhau." << endl;
    } else if (ps1 > ps2) {
        cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
    } else {
        cout << "Phan so thu nhat nho hon phan so thu hai." << endl;
    }

    return 0;
}
