#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#include "cMatrix.h"

int main() {
    MatrixBase* A = new cMatrix(3, 3);
    MatrixBase* B = new cMatrix(3, 3);
    cout << "Nhap ma tran A: " << endl;
    A->input(cin);
    cout << "Nhap ma tran B: " << endl;
    B->input(cin);

    cout << "A + B = " << endl;
    MatrixBase* C = A->add(*B);
    C->output(cout);
    delete C;

    cout << "A - B = " << endl;
    C = A->sub(*B);
    C->output(cout);
    delete C;

    cout << "A * B = " << endl;
    C = A->mul(*B);
    C->output(cout);
    delete C;

    vector<double> arr = {1, 2, 3};
    cout << "A * arr = " << endl;
    vector<double> result = A->mul(arr);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete A;
    delete B;
    return 0;
}
