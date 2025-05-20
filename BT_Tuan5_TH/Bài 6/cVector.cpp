#include "cVector.h"
#include <iostream>
#include <cmath>
using namespace std;
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
