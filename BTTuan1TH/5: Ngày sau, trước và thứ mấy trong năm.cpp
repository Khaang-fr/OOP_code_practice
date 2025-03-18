#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool namnhuan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int SoNgayCuaThang(int month, int year) {

if (month < 1 || month > 12) return -1; 

    if (month == 2) {
        return namnhuan(year) ? 29 : 28; 
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

Date NgayTiepTheo(Date date) {
    int maxDay = SoNgayCuaThang(date.month, date.year);
    
    if (maxDay == -1 || date.day < 1   || date.day > maxDay) {
        exit(0);
    }

    if (date.day < maxDay) { 
        date.day++;
    } else { 
        date.day = 1;
        if (date.month < 12) {
            date.month++;
        } else { 
            date.month = 1;
            date.year++;
        }
    }
    
    return date;
}

Date ngayTruoc (Date date) {
	int maxDay = SoNgayCuaThang(date.month, date.year);
	
	if (maxDay == -1 || date.day < 1   || date.day > maxDay) {
		exit(0);
	}

	if (date.day > 1) { 
		date.day--;
	} else { 
		if (date.month > 1) {
			date.month--;
			date.day = SoNgayCuaThang(date.month, date.year);
		} else { 
			date.month = 12;
			date.year--;
			date.day = SoNgayCuaThang(date.month, date.year);
		}
	}
	
	return date;
}

int ngayThu (Date date) {
	int ngay = 0;
	for (int i = 1; i < date.month; i++) {
		ngay += SoNgayCuaThang(i, date.year);
	}
	ngay += date.day;
	return ngay;
}

int main() {
	Date date;
	cin >> date.day >> date.month >> date.year;
	if (SoNgayCuaThang(date.month, date.year) == -1) {
	    return 0; 
    	}
    
	Date ngayTiepTheo = NgayTiepTheo(date);
	cout << ngayTiepTheo.day << "/" << ngayTiepTheo.month << "/" << ngayTiepTheo.year << endl;
	Date ngayTruocDo = ngayTruoc(date);
	cout << ngayTruocDo.day << "/" << ngayTruocDo.month << "/" << ngayTruocDo.year << endl;

	cout << ngayThu(date) << endl;
    
    return 0;
}
