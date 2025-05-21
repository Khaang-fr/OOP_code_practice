#include "cMatrix.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
cMatrix::cMatrix() {
    rows = cols = 0;
}
cMatrix::cMatrix(int r, int c) {
    rows = r;
    cols = c;
    info.resize(rows, vector<double>(cols, 0));
}
cMatrix::~cMatrix() {
}
void cMatrix::set(int r, int c, int val) {
    this->info[r][c] = val;
}
double& cMatrix::operator() (int r, int c) {
    return info[r][c];
}
cMatrix cMatrix::operator+(cMatrix other) {
    if (rows != other.rows || cols != other.cols) {
        cout << "Khac so hang hoac khac so dong." << endl;
        exit(0);
    }
    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result(i, j) = info[i][j] + other.info[i][j];
    return result;
}
cMatrix cMatrix::operator-(cMatrix other) {
    if (rows != other.rows || cols != other.cols) {
        cout << "Khac so hang hoac khac so dong." << endl;
        exit(0);
    }
    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result(i, j) = info[i][j] - other.info[i][j];
    return result;
}
cMatrix cMatrix::operator*(cMatrix other) {
    if (cols != other.rows) {
        cout << "So cot phai bang so dong vector kia." << endl;
        exit(0);
    }   
    cMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result(i, j) += info[i][k] * other(k, j);
    return result;
}
vector<double> cMatrix::operator*(vector<double> arr) {
    if (cols != arr.size()) {
        cout << "So cot phai bang kich thuoc vector." << endl;
        exit(0);
    }   
    std::vector<double> result(rows, 0);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i] += info[i][j] * arr[j];
    return result;
}
