#include "cMatrix.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
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
