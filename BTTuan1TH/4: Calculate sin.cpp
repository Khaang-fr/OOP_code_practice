#include <iostream>
#include <cmath>
using namespace std;

double Sin(double x, double accuracy) {
    double term = x;
    double res = x;
    int n = 1;

    while (fabs(term) >= accuracy) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        res += term;
        n++;
    }

    return res;
}

int main() {
    double x;
    cin >> x;
    double result = Sin(x, 0.00001);

    cout << result << endl;

    return 0;
}
