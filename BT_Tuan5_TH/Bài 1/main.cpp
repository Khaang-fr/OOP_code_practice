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
    
    return 0;
}
