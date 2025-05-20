#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class cDaThuc {
private:
    vector<double> heSo;

    string Num(double num) const {
        if (floor(num) == num) return to_string(int(num));
        ostringstream oss;
        oss << fixed << setprecision(10) << num;
        string str = oss.str();
        str.erase(str.find_last_not_of('0') + 1, string::npos);
        if (str.back() == '.') str.pop_back();
        return str;
    }

    void removeTrailingZeros() {
        while (!heSo.empty() && fabs(heSo.back()) < 1e-9) {
            heSo.pop_back();
        }
    }

public:
    cDaThuc(int degree = 0) {
        heSo.resize(degree + 1, 0);
    }
    cDaThuc(const vector<double>& coeffs) : heSo(coeffs) {
        removeTrailingZeros();
    }
    cDaThuc(initializer_list<double> coeffs) : heSo(coeffs) {
        removeTrailingZeros();
    }

    int degree() const {
        return heSo.empty() ? 0 : heSo.size() - 1;
    }

    double tinhGiaTri(double x) const {
        double res = 0.0;
        for (int i = heSo.size() - 1; i >= 0; --i) {
            res = res * x + heSo[i];
        }
        return res;
    }

    void nhap() {
        int deg;
        cout << "Nhap bac cua da thuc: ";
        cin >> deg;
        heSo.resize(deg + 1);
        for (int i = deg; i >= 0; --i) {
            cout << "He so bac " << i << ": ";
            cin >> heSo[i];
        }
        removeTrailingZeros();
    }

    void xuat() const {
        cout << *this << endl;
    }

    string toString() const {
        if (heSo.empty()) return "0";
        string res;
        bool first = true;
        for (int i = heSo.size() - 1; i >= 0; --i) {
            if (fabs(heSo[i]) < 1e-9) continue;
            double hs = heSo[i];
            if (!first) res += (hs < 0 ? " - " : " + ");
            else if (hs < 0) res += "-";
            if (i == 0 || fabs(hs) != 1) res += Num(fabs(hs));
            if (i >= 1) res += "x";
            if (i >= 2) res += "^" + to_string(i);
            first = false;
        }
        return res.empty() ? "0" : res;
    }

    friend ostream& operator<<(ostream& os, const cDaThuc& p) {
        os << p.toString();
        return os;
    }

    cDaThuc operator+(const cDaThuc& other) const {
        vector<double> res(max(heSo.size(), other.heSo.size()), 0);
        for (size_t i = 0; i < res.size(); ++i) {
            if (i < heSo.size()) res[i] += heSo[i];
            if (i < other.heSo.size()) res[i] += other.heSo[i];
        }
        return cDaThuc(res);
    }

    cDaThuc operator-(const cDaThuc& other) const {
        vector<double> res(max(heSo.size(), other.heSo.size()), 0);
        for (size_t i = 0; i < res.size(); ++i) {
            if (i < heSo.size()) res[i] += heSo[i];
            if (i < other.heSo.size()) res[i] -= other.heSo[i];
        }
        return cDaThuc(res);
    }

    cDaThuc operator*(const cDaThuc& other) const {
        int deg1 = this->degree();
        int deg2 = other.degree();
        vector<double> res(deg1 + deg2 + 1, 0);
        for (int i = 0; i <= deg1; ++i) {
            for (int j = 0; j <= deg2; ++j) {
                res[i + j] += heSo[i] * other.heSo[j];
            }
        }
        return cDaThuc(res);
    }

    const vector<double>& getHeSo() const {
        return heSo;
    }
};

int main() {
    cDaThuc p1{1, 2, 3}; 
    cDaThuc p2{0, -2, 4};

    cout << "P1(x): " << p1 << endl;
    cout << "P2(x): " << p2 << endl;

    cout << "Tong: " << (p1 + p2) << endl;
    cout << "Hieu: " << (p1 - p2) << endl;
    cout << "Tich: " << (p1 * p2) << endl;

    double x = 2;
    cout << "Gia tri P1(" << x << ") = " << p1.tinhGiaTri(x) << endl;

    return 0;
}
