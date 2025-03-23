#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Index 0 is constant term, 1 is x, 2 is x^2, etc.

    // Format number to remove trailing zeros
    string formatNumber(double num) const {
        // Handle integer values
        if (floor(num) == num) {
            return to_string(int(num));
        }
        
        // Format double with precision
        ostringstream oss;
        oss << fixed << setprecision(10) << num;
        string str = oss.str();
        
        // Remove trailing zeros
        str.erase(str.find_last_not_of('0') + 1, string::npos);
        
        // Remove trailing decimal point if necessary
        if (str.back() == '.') {
            str.pop_back();
        }
        
        return str;
    }

public:
    // Create a polynomial with specified degree or 0 degree
    Polynomial(int degree = 0) {
        coefficients.resize(degree + 1, 0);
    }

    // Constructor with coefficient list
    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {
        removeTrailingZeros();
    }

    // Constructor with initializer list
    Polynomial(initializer_list<double> coeffs) : coefficients(coeffs) {
        removeTrailingZeros();
    }

    // Remove trailing zeros
    void removeTrailingZeros() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    // Get degree of polynomial
    int degree() const {
        return coefficients.empty() ? 0 : coefficients.size() - 1;
    }

    // Evaluate polynomial at value x
    double evaluate(double x) const {
        double result = 0.0;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    // Input a polynomial
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

    // Output a polynomial
    void output() const {
        cout << toString() << endl;
    }

    // Addition of polynomials
    Polynomial add(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    // Subtraction of polynomials
    Polynomial subtract(const Polynomial& other) const {
        vector<double> result = coefficients;
        result.resize(max(result.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        
        Polynomial p(result);
        return p;
    }

    // String representation of the polynomial
    string toString() const {
        if (coefficients.empty()) {
            return "0";
        }
        
        string result;
        bool firstTerm = true;
        
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] == 0) continue;
            
            // Handle sign
            if (firstTerm) {
                if (coefficients[i] < 0) {
                    result += "-";
                }
                firstTerm = false;
            } else {
                result += (coefficients[i] < 0) ? " - " : " + ";
            }
            
            double absCoeff = abs(coefficients[i]);
            
            // Handle coefficient and variable
            if (i == 0) {
                // Constant term
                result += formatNumber(absCoeff);
            } else if (i == 1) {
                // x term
                if (absCoeff == 1) {
                    result += "x";
                } else {
                    result += formatNumber(absCoeff) + "x";
                }
            } else {
                // Higher power terms
                if (absCoeff == 1) {
                    result += "x^" + to_string(i);
                } else {
                    result += formatNumber(absCoeff) + "x^" + to_string(i);
                }
            }
        }
        
        return result;
    }

    // Friend function for output stream
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
