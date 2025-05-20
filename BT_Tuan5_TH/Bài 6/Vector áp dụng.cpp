#include <iostream>
#include <cmath>
using namespace std;

//cVector.h
//#pragma once
//#include <iostream>
//using namespace std;
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

//cVector.cpp
//#include "cVector.h"
//#include <iostream>
//#include <cmath>
//using namespace std;
cVector::cVector() {
    dims = 0;
    data = nullptr;
}
cVector::cVector(int d) {
    dims = d;
    data = new double[dims];
    for (int i = 0; i < dims; ++i)
        data[i] = 0;
}
cVector::cVector(const cVector& other) {
    dims = other.dims;
    data = new double[dims];
    for (int i = 0; i < dims; ++i)
        data[i] = other.data[i];
}
cVector::~cVector() {
    delete[] data;
}
int cVector::getDims() {
    return dims;
}
double cVector::getData(int index) {
    return data[index];
}
void cVector::setData(int index, double value) {
    data[index] = value;
}
double cVector::norm() {
    double sum = 0;
    for (int i = 0; i < dims; ++i)
        sum += data[i] * data[i];
    return sqrt(sum);
}
cVector cVector::operator+(const cVector& other) {
    cVector result(dims);
    for (int i = 0; i < dims; ++i)
        result.data[i] = data[i] + other.data[i];
    return result;
}
cVector cVector::operator-(const cVector& other) {
    cVector result(dims);
    for (int i = 0; i < dims; ++i)
        result.data[i] = data[i] - other.data[i];
    return result;
}
cVector cVector::operator*(double scalar) {
    cVector result(dims);
    for (int i = 0; i < dims; ++i)
        result.data[i] = data[i] * scalar;
    return result;
}
cVector& cVector::operator=(const cVector& other) {
    if (this != &other) {
        delete[] data;
        dims = other.dims;
        data = new double[dims];
        for (int i = 0; i < dims; ++i)
            data[i] = other.data[i];
    }
    return *this;
}
bool cVector::operator==(const cVector& other) {
    if (dims != other.dims)
        return false;
    for (int i = 0; i < dims; ++i)
        if (data[i] != other.data[i])
            return false;
    return true;
}
double cVector::dot(const cVector& other) {
    double result = 0;
    for (int i = 0; i < dims; ++i)
        result += data[i] * other.data[i];
    return result;
}
void cVector::print() {
    cout << *this << endl;
}

//main.cpp
//#include "cVector.h"
//#include <iostream>
//#include <cmath>
//úing namespace std;
int main() {
    cVector v1, v2;
    cin >> v1;
    cin >> v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cVector sum = v1 + v2;
    cout << "Tong: " << sum << endl;

    cout << "Do lon v1: " << v1.norm() << endl;
    cout << "Tich vo huong: " << v1.dot(v2) << endl;

    return 0;
}
