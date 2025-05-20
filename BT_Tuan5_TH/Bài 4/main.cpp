#include "cDate.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cDate start, end;
    double S, rate;

    cout << "Nhap ngay gui (dd/mm/yyyy): "; cin >> start;
    cout << "Nhap ngay rut (dd/mm/yyyy): "; cin >> end;
    cout << "Nhap so tien gui: "; cin >> S;
    cout << "Nhap lai suat (%/nam): "; cin >> rate;

    int days = end - start;
    double interest = S * rate * days / 365 / 100;
    double total = S + interest;

    cout << "So ngay gui: " << days << " ngay\n";
    cout << "Tien lai: " << fixed << setprecision(2) << interest << endl;
    cout << "Tong so tien nhan duoc: " << total << endl;
    return 0;
}
