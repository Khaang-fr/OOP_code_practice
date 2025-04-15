#include <string>
#include <iostream>
#include <math.h>
#include <string>
#include "cArray.h"
#include <iomanip>
#include <cmath>
using namespace std;
void cArray::Nhap() {
    cout << "Nhap so phan tu: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i+1 << ":";
        cin >> a[i];
    }
}
void cArray::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void cArray::CountX() {
    int x; 
    cout << "Nhap so muon dem: ";
    cin >> x;
    int count =0;
    for (int i = 0; i< n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    cout << "Co " << count << " phan tu co gia tri " << x  << endl;
}
bool cArray::isAscending() {
    for (int i = 0; i < n; i++) {
        if (a[i] > a[i+1]) {
            return false;
        }
    }
    return true;
}
void cArray::smallestOdd() {
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            min = a[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < min) {
            min = a[i];
        }
    }
    cout << "So le nho nhat la: " << min << endl;
    if (min == 0) {
        cout << "Mang khong co so le." << endl;
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void cArray::largestPrime() {
    int max = 0;
    for (int  i = 0; i < n; i++) {
        if (isPrime(a[i]) && a[i] > max) {
            max = a[i];
        }
    }
    cout << "So nguyen to lon nhat la: ";
    if (max == 0) {
        cout << "Mang khong co so nguyen to" << endl;
    } else {
        cout << max << endl;
    }
}
void cArray::SapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Mang sau khi sap xep tang dan: ";
    Xuat();
}
void cArray::SapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Mang sau khi sap xep giam dan: ";
    Xuat();
}
