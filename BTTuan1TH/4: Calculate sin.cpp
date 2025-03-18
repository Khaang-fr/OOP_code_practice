#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Sin(double x, double accuracy) {
    // Chuẩn hóa x vào khoảng [-2π, 2π] để tăng tính chính xác
    double PI = 3.14159265358979323846;
    x = fmod(x, 2 * PI);
    
    double term = x;
    double res = x;
    int n = 1;
    
    while (fabs(term) >= accuracy) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        res += term;
        n++;
        // Đảm bảo không bị lặp vô hạn
        if (n > 100) break;
    }
    return res;
}

int main() {
    double x;
    cin >> x;
    double result = Sin(x, 0.00001);
    cout << fixed << setprecision(5) << result << endl;
    return 0;
}
