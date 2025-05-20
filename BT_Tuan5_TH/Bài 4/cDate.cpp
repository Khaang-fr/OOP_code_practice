#include "cDate.h"
#include <iostream>
#include <iomanip>
using namespace std;
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
