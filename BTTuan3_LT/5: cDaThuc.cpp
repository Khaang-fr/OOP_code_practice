#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients;

public:
    Polynomial() {}
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

    double operator()(double x) const {
        return evaluate(x);
    }

    Polynomial operator+(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    Polynomial operator*(double scalar) const {
        vector<double> result(coefficients.size());
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] = coefficients[i] * scalar;
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        if (coefficients.empty() || other.coefficients.empty()) {
            return Polynomial();
        }

        vector<double> result(degree() + other.degree() + 1, 0);
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        
        return Polynomial(result);
    }

    Polynomial derivative() const {
        if (coefficients.size() <= 1) {
            return Polynomial({0});
        }
        
        vector<double> result(coefficients.size() - 1);
        for (size_t i = 1; i < coefficients.size(); ++i) {
            result[i - 1] = coefficients[i] * i;
        }
        
        return Polynomial(result);
    }

    Polynomial integral(double C = 0) const {
        vector<double> result(coefficients.size() + 1);
        result[0] = C;
        
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i + 1] = coefficients[i] / (i + 1);
        }
        
        return Polynomial(result);
    }

    double getCoefficient(int power) const {
        return (power >= 0 && power < static_cast<int>(coefficients.size())) ? 
               coefficients[power] : 0;
    }

    void setCoefficient(int power, double value) {
        if (power < 0) return;
        
        if (power >= static_cast<int>(coefficients.size())) {
            coefficients.resize(power + 1, 0);
        }
        
        coefficients[power] = value;
        removeTrailingZeros();
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
                result += to_string(absCoeff);
            } else if (i == 1) {
                if (absCoeff == 1) {
                    result += "x";
                } else {
                    result += to_string(absCoeff) + "x";
                }
            } else {
                if (absCoeff == 1) {
                    result += "x^" + to_string(i);
                } else {
                    result += to_string(absCoeff) + "x^" + to_string(i);
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
