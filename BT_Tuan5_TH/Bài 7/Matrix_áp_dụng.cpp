#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//cMatrix.h
//#pragma once
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
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

//cMatrix.cpp
//#include "cMatrix.h"
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
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

//main.cpp
//#include "cMatrix.h"
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
int main() {
    cMatrix A(3, 3);
    cMatrix B(3, 3);
    cout << "Nhap ma tran A: " << endl;
    cin >> A;
    cout << "Nhap ma tran B: " << endl;
    cin >> B;
    cout << "A + B = " << endl;
    cout << A + B;
    cout << "A - B = " << endl;
    cout << A - B;
    cout << "A * B = " << endl;
    cout << A * B;
    vector<double> arr = {1, 2, 3};
    cout << "A * arr = " << endl;
    vector<double> result = A * arr;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
