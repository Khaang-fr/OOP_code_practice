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
        return namnhuan(year) ? 29 : 28; //Nếu là năm nhuận tháng 2 chỉ có 28 ngày
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

Date NgayTiepTheo(Date date) {
    int maxDay = SoNgayCuaThang(date.month, date.year);

    if (date.day < maxDay) { 
        date.day++;
    } else { 
        date.day = 1; //Sang tháng mới
        if (date.month < 12) {
            date.month++;
        } else { 
            date.month = 1; //Sang năm mới
            date.year++;
        }
    }
    
    return date;
}

Date ngayTruoc (Date date) {
	if (date.day > 1) { 
		date.day--;
	} else { 
		if (date.month > 1) {
			date.month--; //Lùi lại 1 tháng
			date.day = SoNgayCuaThang(date.month, date.year);
		} else { 
			date.month = 12;
			date.year--; //Lùi lại 1 năm
			date.day = SoNgayCuaThang(date.month, date.year);
		}
	}
	
	return date;
}

bool realDay(int day, int month, int year) {
    if (year < 0) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    if (month == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return day <= 29;
        }
        return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return day <= 31;
}

int ngayThu (Date date) {
	int ngay = 0;
	for (int i = 1; i < date.month; i++) {
		ngay += SoNgayCuaThang(i, date.year); //Cộng các ngày của tháng trước lại
	}
	ngay += date.day; //Và ngày hiện tại
	return ngay;
}

int main() {
	Date date;
	do {
		cin >> date.day >> date.month >> date.year;
	} while (!realDay(date.day, date.month, date.year));
    
	Date ngayTiepTheo = NgayTiepTheo(date);
	cout << ngayTiepTheo.day << "/" << ngayTiepTheo.month << "/" << ngayTiepTheo.year << endl;
	Date ngayTruocDo = ngayTruoc(date);
	cout << ngayTruocDo.day << "/" << ngayTruocDo.month << "/" << ngayTruocDo.year << endl;

	cout << ngayThu(date) << endl;
    
    return 0;
}
