#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients;
    string formatNumber(double num) const {
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
    Polynomial(int degree = 0) {
        coefficients.resize(degree + 1, 0);
    }

    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {
        removeTrailingZeros();
    }

    Polynomial(initializer_list<double> coeffs) : coefficients(coeffs) {
        removeTrailingZeros();
    }

    void removeTrailingZeros() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    int degree() const {
        return coefficients.empty() ? 0 : coefficients.size() - 1;
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    void input() {
        int deg;
        cout << "Enter the degree of the polynomial: ";
        cin >> deg;
        
        coefficients.resize(deg + 1);
        
        for (int i = deg; i >= 0; --i) {
            cout << "Enter coefficient for x^" << i << ": ";
            cin >> coefficients[i];
        }
        
        removeTrailingZeros();
    }

    void output() const {
        cout << toString() << endl;
    }

    Polynomial add(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    Polynomial subtract(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    string toString() const {
        if (coefficients.empty()) {
            return "0";
        }
        
        string result;
        bool firstTerm = true;
        
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] == 0) continue;
            
            if (firstTerm) {
                if (coefficients[i] < 0) {
                    result += "-";
                }
                firstTerm = false;
            } else {
                result += (coefficients[i] < 0) ? " - " : " + ";
            }
            
            double absCoeff = abs(coefficients[i]);
            
            if (i == 0) {
                result += formatNumber(absCoeff);
            } else if (i == 1) {
                if (absCoeff == 1) {
                    result += "x";
                } else {
                    result += formatNumber(absCoeff) + "x";
                }
            } else {
                if (absCoeff == 1) {
                    result += "x^" + to_string(i);
                } else {
                    result += formatNumber(absCoeff) + "x^" + to_string(i);
                }
            }
        }
        
        return result;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& poly) {
        os << poly.toString();
        return os;
    }
};

int main() {
    Polynomial p1(0);
    cout << "Created polynomial with degree 0: " << p1 << endl;
    
    Polynomial p2({1, 5, 2, 0, 3});
    cout << "Created polynomial: " << p2 << endl;
    
    double x = 2.0;
    cout << "P(" << x << ") = " << p2.evaluate(x) << endl;
    
    cout << "\nEnter a new polynomial:" << endl;
    Polynomial p3;
    p3.input();
    
    cout << "\nThe polynomial you entered: ";
    p3.output();
    
    Polynomial sum = p2.add(p3);
    cout << "\nSum of polynomials: " << sum << endl;
    
    Polynomial diff = p2.subtract(p3);
    cout << "Difference of polynomials: " << diff << endl;
    
    return 0;
}
