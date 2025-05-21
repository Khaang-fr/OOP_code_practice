#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class cMatrix
{
private:
    int rows, cols;
    vector<vector<double>> info;
public:
    cMatrix();
    cMatrix(int r, int c);
    ~cMatrix();
    void set(int r, int c, int val);
    double& operator() (int r, int c);
    cMatrix operator+(cMatrix other);
    cMatrix operator-(cMatrix other);
    cMatrix operator*(cMatrix other);
    vector<double> operator*(vector<double> arr);
    friend ostream& operator<<(ostream& os, cMatrix& M) {
        os << "[";
        for (int i = 0; i < M.rows; i++) {
            for (int j = 0; j < M.cols; j++) {
                os << M.info[i][j] << "\t";
            }
            if (i != M.rows - 1) {
                os << endl;
            }
        }
        os << "]";
        os << endl;
        return os;
    }
    friend istream& operator>>(istream& is, cMatrix& M) {
        for (int i = 0; i < M.rows; i++) {
            for (int j =0; j < M.cols; j++) {
                is >> M.info[i][j];
            }
        }
        return is;
    }
};
