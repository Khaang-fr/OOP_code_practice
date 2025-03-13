#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ngayThang {
    int ngay, thang, nam;
};

struct gioPhut {
    int gio, phut;
};

bool containsSpace(const string& str) {
    for (char ch : str) {
        if (ch == ' ') {
            return true;
        }
    }
    return false;
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

bool containsNumber(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

bool containsSpecialCharacter(const string& str) {
    for (char ch : str) {
        if (!isalnum(ch) && ch != ' ') {
            return true;
        }
    }
    return false;
}

bool noLongerThan5(const string& str) {
    return str.length() <= 5;
}

class ChuyenBay {
    private:
        string maChuyenBay;
        ngayThang ngayBay;
        gioPhut gioBay;
        string sanBayDi, sanBayDen;
    public:
        void nhap();
        void xuat();
        void TimKiemChuyenBay(ChuyenBay cb[], int n); 
        void SapXepChuyenBay(ChuyenBay cb[], int n);
        void ChuyenBayTrongNgayVaNoiDi(ChuyenBay cb[], int n);
        void soChuyenBayTuSanBay(ChuyenBay cb[], int n);
};

void ChuyenBay::nhap() {
    do {
        cout << "Nhap ma chuyen bay: ";
        getline(cin, maChuyenBay);
        if (containsSpace(maChuyenBay) || containsSpecialCharacter(maChuyenBay) || !noLongerThan5(maChuyenBay)) {
            cout << "Ma chuyen bay khong hop le. Vui long nhap lai." << endl;
        }
    } while (containsSpace(maChuyenBay) || containsSpecialCharacter(maChuyenBay) || !noLongerThan5(maChuyenBay));

    do {
        cout << "Nhap ngay bay: ";
        cin >> ngayBay.ngay >> ngayBay.thang >> ngayBay.nam;
        if (!realDay(ngayBay.ngay, ngayBay.thang, ngayBay.nam)) {
            cout << "Ngay bay khong hop le. Vui long nhap lai." << endl;
        }
    } while (!realDay(ngayBay.ngay, ngayBay.thang, ngayBay.nam));

    do {
        cout << "Nhap gio bay: ";
        cin >> gioBay.gio >> gioBay.phut;
        if (gioBay.gio < 0 || gioBay.gio > 23 || gioBay.phut < 0 || gioBay.phut > 59) {
            cout << "Gio bay khong hop le. Vui long nhap lai." << endl;
        }
    } while (gioBay.gio < 0 || gioBay.gio > 23 || gioBay.phut < 0 || gioBay.phut > 59);

    cin.ignore();  

    do {
        cout << "Nhap san bay di: ";
        getline(cin, sanBayDi);
        if (containsSpecialCharacter(sanBayDi) || containsNumber(sanBayDi)) {
            cout << "San bay di khong hop le. Vui long nhap lai." << endl;
        }
    } while (containsSpecialCharacter(sanBayDi) || containsNumber(sanBayDi));

    do {
        cout << "Nhap san bay den: ";
        getline(cin, sanBayDen);
        if (containsSpecialCharacter(sanBayDen) || containsNumber(sanBayDen)) {
            cout << "San bay den khong hop le. Vui long nhap lai." << endl;
        }
    } while (containsSpecialCharacter(sanBayDen) || containsNumber(sanBayDen));
}


void ChuyenBay::xuat() {
    cout << "Ma chuyen bay: " << maChuyenBay << " - ";
    cout << "Ngay bay: " << ngayBay.ngay << "/" << ngayBay.thang << "/" << ngayBay.nam << " - ";
    cout << "Gio bay: " << gioBay.gio << ":" << gioBay.phut << " - ";
    cout << "San bay di: " << sanBayDi << " - ";
    cout << "San bay den: " << sanBayDen << endl;
}

void ChuyenBay::TimKiemChuyenBay(ChuyenBay cb[], int n) {
    string maChuyenBay;
    cout << "Nhap ma chuyen bay can tim: ";
    getline(cin, maChuyenBay);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (cb[i].maChuyenBay == maChuyenBay) {
            cout << "Chuyen bay can tim la: ";
            cb[i].xuat();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay co ma " << maChuyenBay << endl;
    }
}

void ChuyenBay::SapXepChuyenBay(ChuyenBay cb[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cb[i].ngayBay.nam > cb[j].ngayBay.nam) {
                swap(cb[i], cb[j]);
            } else if (cb[i].ngayBay.nam == cb[j].ngayBay.nam) {
                if (cb[i].ngayBay.thang > cb[j].ngayBay.thang) {
                    swap(cb[i], cb[j]);
                } else if (cb[i].ngayBay.thang == cb[j].ngayBay.thang) {
                    if (cb[i].ngayBay.ngay > cb[j].ngayBay.ngay) {
                        swap(cb[i], cb[j]);
                    } else if (cb[i].ngayBay.ngay == cb[j].ngayBay.ngay) {
                        if (cb[i].gioBay.gio > cb[j].gioBay.gio) {
                            swap(cb[i], cb[j]);
                        } else if (cb[i].gioBay.gio == cb[j].gioBay.gio) {
                            if (cb[i].gioBay.phut > cb[j].gioBay.phut) {
                                swap(cb[i], cb[j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void ChuyenBay::ChuyenBayTrongNgayVaNoiDi(ChuyenBay cb[], int n) {
    int ngay, thang, nam;
    cout << "Nhap ngay can tim: ";
    cin >> ngay >> thang >> nam;
    cin.ignore();
    string sanBayDi;
    cout << "Nhap san bay di can tim: ";
    getline(cin, sanBayDi);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (cb[i].ngayBay.ngay == ngay && cb[i].ngayBay.thang == thang && cb[i].ngayBay.nam == nam && cb[i].sanBayDi == sanBayDi) {
            cout << "Chuyen bay can tim la: ";
            cb[i].xuat();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay di tu " << sanBayDi << " trong ngay " << ngay << "/" << thang << "/" << nam << endl;
    }
}

void ChuyenBay::soChuyenBayTuSanBay(ChuyenBay cb[], int n) {
    string sanBayDi;
    cout << "Nhap san bay di can tim: ";
    getline(cin, sanBayDi);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (cb[i].sanBayDi == sanBayDi) {
            count++;
        }
    }
    cout << "So chuyen bay di tu " << sanBayDi << " la: " << count << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n; cin >> n;
    cin.ignore();
    ChuyenBay *cb = new ChuyenBay[n];
    for (int i = 0; i < n; i++) {
        cb[i].nhap();
    }
    cout << endl;
    cb[0].SapXepChuyenBay(cb, n);
    for (int i = 0; i < n; i++) {
        cb[i].xuat();
    }
    cb[0].TimKiemChuyenBay(cb, n);
    cout << endl;
    cb[0].ChuyenBayTrongNgayVaNoiDi(cb, n);
    cout << endl;
    cb[0].soChuyenBayTuSanBay(cb, n);
    delete[] cb;
    fclose(stdin);
    return 0;
}
