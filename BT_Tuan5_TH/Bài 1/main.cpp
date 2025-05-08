#include "SoPhuc.h"
#include <iostream>
using namespace std;
int main()
{
    SoPhuc a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << "Tong: " << c << endl;
    c = a - b;
    cout << "Hieu: " << c << endl;
    c = a * b;
    cout << "Tich: " << c << endl;
    c = a / b;
    cout << "Thuong: " << c << endl;
    bool equal = a == b;
    cout << "So phuc a " << (equal ? "bang" : "khong bang") << " so phuc b" << endl;
    bool notEqual = a != b;
    cout << "So phuc a " << (notEqual ? "khong bang" : "bang") << " so phuc b" << endl;
    return 0;
}
