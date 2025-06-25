#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class MatrixBase {
public:
    virtual ~MatrixBase() {}
    virtual void set(int r, int c, int val) = 0;
    virtual double& at(int r, int c) = 0;
    virtual const double& at(int r, int c) const = 0;
    virtual MatrixBase* add(const MatrixBase& other) const = 0;
    virtual MatrixBase* sub(const MatrixBase& other) const = 0;
    virtual MatrixBase* mul(const MatrixBase& other) const = 0;
    virtual vector<double> mul(const vector<double>& arr) const = 0;
    virtual void input(istream& is) = 0;
    virtual void output(ostream& os) const = 0;
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;
};
