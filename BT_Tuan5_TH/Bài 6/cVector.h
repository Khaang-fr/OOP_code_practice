#pragma once
#include <iostream>
using namespace std;
class cVector {
private:
    int dims;
    double* data;
public:
    cVector();
    cVector(int);
    cVector(const cVector&);
    ~cVector();
    int getDims();
    double getData(int);
    void setData(int, double);
    double norm();
    cVector operator+(const cVector&);
    cVector operator-(const cVector&);
    cVector operator*(double);
    cVector& operator=(const cVector&);
    bool operator==(const cVector&);
    double dot(const cVector&);
    void print();
    friend ostream& operator<<(ostream& os, const cVector& u) {
        os << "(";
        for (int i = 0; i < u.dims; ++i) {
            os << u.data[i];
            if (i < u.dims - 1)
                os << " ";
        }
        os << ")";
        return os;
    }
    friend istream& operator>>(istream& is, cVector& u) {
        cout << "Nhap so chieu: ";
        is >> u.dims;
        delete[] u.data;
        u.data = new double[u.dims];
        cout << "Nhap " << u.dims << " gia tri: ";
        for (int i = 0; i < u.dims; ++i)
            is >> u.data[i];
        return is;
    }
};
