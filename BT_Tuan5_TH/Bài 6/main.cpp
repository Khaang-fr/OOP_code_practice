#include "cVector.h"
#include <iostream>
#include <cmath>
using namespace std;
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
