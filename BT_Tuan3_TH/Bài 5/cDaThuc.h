#pragma once
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
        if (floor(num) == num) {
            return to_string(int(num));
        }
        ostringstream oss;
        oss << fixed << setprecision(10) << num;
        string str = oss.str();
        str.erase(str.find_last_not_of('0') + 1, string::npos);
        if (str.back() == '.') {
            str.pop_back();
        }
        return str;
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
    void removeTrailingZeros() {
        while (!heSo.empty() && heSo.back() == 0) {
            heSo.pop_back();
        }
    }
    int degree() const {
        return heSo.empty() ? 0 : heSo.size() - 1;
    }
    double tinhGiaTri(double x) const {
        double res = 0.0;
        for (size_t i = 0; i < heSo.size(); ++i) {
            res += heSo[i] * pow(x, i);
        }
        return res;
    }
    void nhap() {
        int deg;
        cout << "Nhap bac: ";
        cin >> deg;
        
        heSo.resize(deg + 1);
        
        for (int i = deg; i >= 0; --i) {
            cout << "Nhap he so " << i << ": ";
            cin >> heSo[i];
        }
        removeTrailingZeros();
    }
    void xuat() const {
        cout << toString() << endl;
    }
    cDaThuc tong(const cDaThuc& other) const {
        vector<double> res = heSo;
        res.resize(max(res.size(), other.heSo.size()), 0);
        
        for (size_t i = 0; i < other.heSo.size(); ++i) {
            res[i] += other.heSo[i];
        }
        
        cDaThuc p(res);
        return p;
    }
    cDaThuc hieu(const cDaThuc& other) const {
        vector<double> res = heSo;
        res.resize(max(res.size(), other.heSo.size()), 0);
        
        for (size_t i = 0; i < other.heSo.size(); ++i) {
            res[i] -= other.heSo[i];
        }
        cDaThuc p(res);
        return p;
    }
    string toString() const {
        if (heSo.empty()) {
            return "0";
        }
        string res;
        bool firstTerm = true;
        for (int i = heSo.size() - 1; i >= 0; --i) {
            if (heSo[i] == 0) continue;
            
            if (firstTerm) {
                if (heSo[i] < 0) {
                    res += "-";
                }
                firstTerm = false;
            } else {
                res += (heSo[i] < 0) ? " - " : " + ";
            }          
            double absHeSo = abs(heSo[i]);
            if (i == 0) {
                res += Num(absHeSo);
            } else if (i == 1) {
                if (absHeSo == 1) {
                    res += "x";
                } else {
                    res += Num(absHeSo) + "x";
                }
            } else {
                if (absHeSo == 1) {
                    res += "x^" + to_string(i);
                } else {
                    res += Num(absHeSo) + "x^" + to_string(i);
                }
            }
        }
        return res;
    }
    friend ostream& operator<<(ostream& os, const cDaThuc& poly) {
        os << poly.toString();
        return os;
    }
};
