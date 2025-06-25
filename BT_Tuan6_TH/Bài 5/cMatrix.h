#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#include "MatrixBase.h"

class cMatrix : public MatrixBase
{
private:
    int rows, cols;
    vector<vector<double>> info;
public:
    cMatrix() : rows(0), cols(0) {}
    cMatrix(int r, int c) : rows(r), cols(c), info(r, vector<double>(c, 0)) {}
    ~cMatrix() override {}
    void set(int r, int c, int val) override { info[r][c] = val; }
    double& at(int r, int c) override { return info[r][c]; }
    const double& at(int r, int c) const override { return info[r][c]; }
    int getRows() const override { return rows; }
    int getCols() const override { return cols; }
    MatrixBase* add(const MatrixBase& other) const override {
        if (rows != other.getRows() || cols != other.getCols()) {
            cout << "Khac so hang hoac khac so dong." << endl;
            exit(0);
        }
        cMatrix* result = new cMatrix(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result->info[i][j] = info[i][j] + other.at(i, j);
        return result;
    }
    MatrixBase* sub(const MatrixBase& other) const override {
        if (rows != other.getRows() || cols != other.getCols()) {
            cout << "Khac so hang hoac khac so dong." << endl;
            exit(0);
        }
        cMatrix* result = new cMatrix(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result->info[i][j] = info[i][j] - other.at(i, j);
        return result;
    }
    MatrixBase* mul(const MatrixBase& other) const override {
        if (cols != other.getRows()) {
            cout << "So cot phai bang so dong vector kia." << endl;
            exit(0);
        }
        cMatrix* result = new cMatrix(rows, other.getCols());
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.getCols(); ++j)
                for (int k = 0; k < cols; ++k)
                    result->info[i][j] += info[i][k] * other.at(k, j);
        return result;
    }
    vector<double> mul(const vector<double>& arr) const override {
        if (cols != arr.size()) {
            cout << "So cot phai bang kich thuoc vector." << endl;
            exit(0);
        }
        vector<double> result(rows, 0);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result[i] += info[i][j] * arr[j];
        return result;
    }
    void input(istream& is) override {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                is >> info[i][j];
    }
    void output(ostream& os) const override {
        os << "[";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                os << info[i][j] << "\t";
            }
            if (i != rows - 1) os << endl;
        }
        os << "]" << endl;
    }
};
