#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
bool isRealDate(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1) return false;
    const int daysInMonth[] = {31, 28 + (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return d <= daysInMonth[m - 1];
}
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
