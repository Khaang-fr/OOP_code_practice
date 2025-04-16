#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include "cArray.h"
#include <cmath>
using namespace std;

int main() {
    cArray arr;
    arr.Nhap();
    cout << "Mang da nhap: ";
    arr.Xuat();
    arr.CountX();
    if (arr.isAscending()) {
        cout << "Mang da sap xep tang dan." << endl;
    } else {
        cout << "Mang khong sap xep tang dan." << endl;
    }
    arr.smallestOdd();
    arr.largestPrime();
    arr.SapXepTangDan();
    arr.SapXepGiamDan();
    return 0;
}
