#include <iostream>
#include <iomanip>
using namespace std;

bool isRealDate(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1) return false;
    const int daysInMonth[] = {31, 28 + (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return d <= daysInMonth[m - 1];
}

//cDate.h
//pragma once
//#include <iostream>
//#include <iomanip>
//using namespace std;
class cDate {
    private:
        int ngay, thang, nam;
        static const int daysInMonth[12];

        static bool isLeapYear(int y) {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        }

        static int getDaysInMonth(int m, int y) {
            if (m == 2) return isLeapYear(y) ? 29 : 28;
            return daysInMonth[m - 1];
        }

        void normalize() {
            while (ngay > getDaysInMonth(thang, nam)) {
                ngay -= getDaysInMonth(thang, nam);
                thang++;
                if (thang > 12) {
                    thang = 1;
                    nam++;
                }
            }
            while (ngay < 1) {
                thang--;
                if (thang < 1) {
                    thang = 12;
                    nam--;
                }
                ngay += getDaysInMonth(thang, nam);
            }
        }

    public:
        cDate(int d=1, int m=1, int y=2024) : ngay(d), thang(m), nam(y) {normalize();}
        cDate operator+(int d) const;
        cDate operator-(int d) const;
        int operator-(const cDate& other) const;
        cDate& operator++() { ngay++; normalize(); return *this; }
        cDate operator++(int) { cDate t = *this; ++(*this); return t; }
        cDate& operator--() { ngay--; normalize(); return *this; }
        cDate operator--(int) { cDate t = *this; --(*this); return t; }
        friend ostream& operator<<(ostream& os, const cDate& t) {
            os << t.ngay << "/" << t.thang << "/" << t.nam;
            return os;
        }
        friend istream& operator>>(istream& is, cDate& t) {
            do {
                is >> t.ngay >> t.thang >> t.nam;
                if (!isRealDate(t.ngay, t.thang, t.nam)) {
                    cout << "Thoi gian khong hop le, vui long nhap lai." << endl;
                    is.clear();
                    is.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (!isRealDate(t.ngay, t.thang, t.nam));
            return is;
        }
};
const int cDate::daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


//cDate.cpp
//#include "cDate.h"
//#include <iostream>
//#include <iomanip>
//using namespace std;
cDate cDate::operator+(int d) const {
    cDate tmp = *this;
    tmp.ngay += d;
    tmp.normalize();
    return tmp;
}
cDate cDate::operator-(int d) const {
    cDate tmp = *this;
    tmp.ngay -= d;
    tmp.normalize();
    return tmp;
}
int cDate::operator-(const cDate& other) const {
    int days = 0;
    cDate tmp = *this;
    while (tmp.ngay != other.ngay || tmp.thang != other.thang || tmp.nam != other.nam) {
        days++;
        tmp.ngay--;
        if (tmp.ngay < 1) {
            tmp.thang--;
            if (tmp.thang < 1) {
                tmp.thang = 12;
                tmp.nam--;
            }
            tmp.ngay += getDaysInMonth(tmp.thang, tmp.nam);
        }
    }
    return days;
}

//main.cpp
//#include "cDate.h"
//#include <iostream>
//#include <iomanip>
//using namespace std;
int main() {
    cDate start, end;
    double S, rate;

    cout << "Nhap ngay gui (dd/mm/yyyy): "; cin >> start;
    cout << "Nhap ngay rut (dd/mm/yyyy): "; cin >> end;
    cout << "Nhap so tien gui: "; cin >> S;
    cout << "Nhap lai suat (%/nam): "; cin >> rate;

    int days = end - start;
    double interest = S * rate * days / 365 / 100;
    double total = S + interest;

    cout << "So ngay gui: " << days << " ngay\n";
    cout << "Tien lai: " << fixed << setprecision(2) << interest << endl;
    cout << "Tong so tien nhan duoc: " << total << endl;
    return 0;
}
