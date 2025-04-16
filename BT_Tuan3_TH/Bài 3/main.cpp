#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <cmath>
#include "cDSPhanSo.h"
using namespace std;

int main() {
    cDSPhanSo ds;
    ds.Nhap();
    ds.Xuat();
    ds.Tong();
    ds.Max();
    ds.Min();
    ds.TuLaSoNguyenToLonNhat();
    ds.SapXepTangDan();
    ds.SapXepGiamDan();
    return 0;
}
