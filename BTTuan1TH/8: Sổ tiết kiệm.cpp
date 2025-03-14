#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct NgayThang {
    int ngay, thang, nam;
};

bool noSpecialCharacter(const string& str) {
    for (char ch : str) {
        if (!isalnum(ch) && ch != ' ') {
            return false;
        }
    }
    return true;
}

bool noSpace(const string& str) {
    for (char ch : str) {
        if (ch == ' ') {
            return false;
        }
    }
    return true;
}

bool noNumber(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int lengthWithoutSpace(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (ch != ' ') {
            count++;
        }
    }
    return count;
}

bool isRealDay(int day, int month, int year) {
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

bool noLongerThan6Months(NgayThang ngayMoSo, NgayThang ngayHienTai) {
    if (ngayHienTai.nam == ngayMoSo.nam) {
        if (ngayHienTai.thang - ngayMoSo.thang <= 6) {
            return true;
        }
    } else if (ngayHienTai.nam - ngayMoSo.nam == 1) {
        if (ngayHienTai.thang + 12 - ngayMoSo.thang <= 6) {
            return true;
        }
    }
    return false;
}

int DaysCounter(NgayThang ngayMoSo, NgayThang ngayHienTai) {
    int count = 0;
    if (ngayHienTai.nam == ngayMoSo.nam) {
        if (ngayHienTai.thang == ngayMoSo.thang) {
            count += ngayHienTai.ngay - ngayMoSo.ngay;
        } else {
            count += 30 - ngayMoSo.ngay + ngayHienTai.ngay;
        }
    } else {
        count += 30 - ngayMoSo.ngay + ngayHienTai.ngay;
    }
    return count;
}

class SoTietKiem {
    private:
        string maSo;
        string loaiTietKiem;
        string hoTen;
        int CMND;
        NgayThang ngayMoSo;
        double soTienGui;
        double tienHienTai;
    public:
        NgayThang ngayHienTai = {14, 3, 2025};
        void nhap();
        void xuat();
        void CapNhatLaiSuat();
        void TinhToanTienHienTai(float laiSuatNganHan, float laiSuatDaiHan);
        void SapXep(SoTietKiem stk[], int n);
        void TimKiem(SoTietKiem stk[], int n, string maSo, int CMND);
};

void SoTietKiem::nhap() {
    while (true) {
        cout << "Nhap ma so: ";
        getline(cin, maSo);
        if (noSpecialCharacter(maSo) && noSpace(maSo) && lengthWithoutSpace(maSo) <= 5) {
            break;
        }
        cout << "Ma so khong hop le. Vui long nhap lai.\n";
    }
    
    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        if (noNumber(hoTen) && noSpecialCharacter(hoTen) && lengthWithoutSpace(hoTen) <= 30) {
            break;
        }
        cout << "Ho ten khong hop le. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "Nhap CMND: ";
        cin >> CMND;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "CMND khong hop le. Vui long nhap lai.\n";
            continue;
        }

        string CMND_str = to_string(CMND);
        if (CMND_str.length() == 9 || CMND_str.length() == 12) {
            break;
        }
        cout << "CMND khong hop le. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> ngayMoSo.ngay >> ngayMoSo.thang >> ngayMoSo.nam;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ngay thang nam khong hop le. Vui long nhap lai.\n";
            continue;
        }

        if (isRealDay(ngayMoSo.ngay, ngayMoSo.thang, ngayMoSo.nam)) {
            break;
        }
        cout << "Ngay thang nam khong hop le. Vui long nhap lai.\n";
    }

    while (true) {
        cout << "Nhap so tien gui: ";
        cin >> soTienGui;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "So tien gui khong hop le. Vui long nhap lai.\n";
            continue;
        }

        if (soTienGui > 0) {
            break;
        }
        cout << "So tien gui khong hop le. Vui long nhap lai.\n";
    }

    cin.ignore();
}

void SoTietKiem::xuat() {
    cout << "Ma so: " << maSo << " - ";
    cout << "Loai tiet kiem: " << loaiTietKiem << " - ";
    cout << "Ho ten: " << hoTen << " - ";
    cout << "CMND: " << CMND << " - ";
    cout << "Ngay mo so: " << ngayMoSo.ngay << "/" << ngayMoSo.thang << "/" << ngayMoSo.nam << " - ";
    cout << "So tien gui: " << soTienGui << endl;
}

void SoTietKiem::CapNhatLaiSuat() {
    if (noLongerThan6Months(ngayMoSo, ngayHienTai)) {
        loaiTietKiem = "Ngan han";
    } else {
        loaiTietKiem = "Dai han";
    }
}

void SoTietKiem::TinhToanTienHienTai(float laiSuatNganHan, float laiSuatDaiHan) {
    if (loaiTietKiem == "Ngan han") {
        tienHienTai = soTienGui * (1 + laiSuatNganHan) * DaysCounter(ngayMoSo, ngayHienTai) / 365;
        cout << "Tien hien tai cua so tiet kiem " << maSo << " la: " << tienHienTai << endl;
    } else {
        tienHienTai = soTienGui * (1 + laiSuatDaiHan) * DaysCounter(ngayMoSo, ngayHienTai) / 365;
        cout << "Tien hien tai cua so tiet kiem " << maSo << " la: " << tienHienTai << endl;
    }
}



int main() {
    int n; cin >> n;
    cin.ignore();
    SoTietKiem *stk = new SoTietKiem[n];
    for (int i = 0; i < n; i++) {
        stk[i].nhap();
    }
    for (int i = 0; i < n; i++) {
        stk[i].xuat();
    }
    float laiSuatNganHan;
    float laiSuatDaiHan;
    cout << "Nhap lai suat ngan han: ";
    cin >> laiSuatNganHan;
    cout << "Nhap lai suat dai han: ";
    cin >> laiSuatDaiHan;
    for (int i = 0; i < n; i++) {
        stk[i].CapNhatLaiSuat();
    }
    
    cout << "Vui long chon hanh dong ban muon thuc hien: \n";
    cout << "1. Tinh toan tien hien tai\n";
    cout << "2. Sap xep\n";
    cout << "3. Tim kiem\n";
    int x; cin >> x;
    switch (x) {
        case 1:
            for (int i = 0; i < n; i++) {
                stk[i].TinhToanTienHienTai(laiSuatNganHan, laiSuatDaiHan);
            }
            break;
        case 2:
            stk->SapXep(stk, n);
            for (int i = 0; i < n; i++) {
                stk[i].xuat();
            }
            break;
        case 3:
            string maSo;
            int CMND;
            cout << "Nhap ma so: ";
            cin >> maSo;
            cout << "Nhap CMND: ";
            cin >> CMND;
            stk->TimKiem(stk, n, maSo, CMND);
            break;
    }
    return 0;
}
