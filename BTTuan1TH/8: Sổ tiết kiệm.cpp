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
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    auto isLeapYear = [](int year) -> bool {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    };
    
    auto daysSince0 = [daysInMonth, isLeapYear](NgayThang date) -> int {
        int totalDays = date.ngay;
        
        for (int m = 1; m < date.thang; m++) {
            if (m == 2 && isLeapYear(date.nam)) {
                totalDays += 29;
            } else {
                totalDays += daysInMonth[m];
            }
        }
        
        for (int y = 0; y < date.nam; y++) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }
        
        return totalDays;
    };
    
    int days1 = daysSince0(ngayMoSo);
    int days2 = daysSince0(ngayHienTai);
    
    return days2 - days1;
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
        void RutTien(SoTietKiem stk[], int n, string maSo, double soTienRut, float laiSuatNganHan, float laiSuatDaiHan);
        void LietKe(SoTietKiem stk[], int n);
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
        cout << "Nhap loai tiet kiem (Ngan han/Dai han): ";
        getline(cin, loaiTietKiem);
        
        if (loaiTietKiem == "Ngan han" || loaiTietKiem == "Dai han") {
            break;
        }
        cout << "Loai tiet kiem khong hop le. Vui long nhap 'Ngan han' hoac 'Dai han'.\n";
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
    cout << "So tien gui: " << soTienGui << " - ";
    cout << "Tien hien tai: " << tienHienTai << endl;
}

void SoTietKiem::TinhToanTienHienTai(float laiSuatNganHan, float laiSuatDaiHan) {
    if (loaiTietKiem == "Ngan han") {
        tienHienTai = soTienGui + soTienGui * (1 + laiSuatNganHan/100) * DaysCounter(ngayMoSo, ngayHienTai) / 365;
        cout << "Tien hien tai cua so tiet kiem " << maSo << " la: " << tienHienTai << endl;
    } else {
        tienHienTai = soTienGui + soTienGui * (1 + laiSuatDaiHan/100) * DaysCounter(ngayMoSo, ngayHienTai) / 365;
        cout << "Tien hien tai cua so tiet kiem " << maSo << " la: " << tienHienTai << endl;
    }
}

void SoTietKiem::RutTien(SoTietKiem stk[], int n, string maSo, double soTienRut, float laiSuatNganHan, float laiSuatDaiHan) {
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (stk[i].maSo == maSo) {
            found = true;
            
            float laiSuatApDung = (stk[i].loaiTietKiem == "Ngan han") ? laiSuatNganHan : laiSuatDaiHan;
            bool isEarlyWithdrawal = false;
            
            if (noLongerThan6Months(stk[i].ngayMoSo, stk[i].ngayHienTai)) {
                if (stk[i].loaiTietKiem == "Dai han") {
                    isEarlyWithdrawal = true;
                    cout << "CANH BAO: Rut tien truoc thoi han (chua du 6 thang)." << endl;
                    cout << "Tien lai se duoc tinh theo lai suat ngan han." << endl;
                    
                    laiSuatApDung = laiSuatNganHan * 0.7; 
                }
            }
            
            stk[i].tienHienTai = stk[i].soTienGui * (1 + laiSuatApDung) * DaysCounter(stk[i].ngayMoSo, stk[i].ngayHienTai) / 365;
            
            if (isEarlyWithdrawal) {
                cout << "Lai suat ap dung: " << laiSuatApDung << " (Giam do rut som)" << endl;
                cout << "So du hien tai sau dieu chinh: " << stk[i].tienHienTai << endl;
            }
            
            if (soTienRut <= 0) {
                cout << "So tien rut khong hop le." << endl;
                return;
            }
            
            if (soTienRut > stk[i].tienHienTai) {
                cout << "So tien rut vuot qua so du hien tai (" << stk[i].tienHienTai << ")." << endl;
                return;
            }
            
            stk[i].tienHienTai -= soTienRut;
            cout << "Rut tien thanh cong. So du moi: " << stk[i].tienHienTai << endl;
            return;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay so tiet kiem voi ma so " << maSo << "." << endl;
    }
}

void SoTietKiem::SapXep(SoTietKiem stk[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool shouldSwap = false;
            
            if (stk[i].soTienGui < stk[j].soTienGui) {
                shouldSwap = true;
            }
            else if (stk[i].soTienGui == stk[j].soTienGui) {
                if (stk[i].ngayMoSo.nam > stk[j].ngayMoSo.nam) {
                    shouldSwap = true;
                }
                else if (stk[i].ngayMoSo.nam == stk[j].ngayMoSo.nam && 
                         stk[i].ngayMoSo.thang > stk[j].ngayMoSo.thang) {
                    shouldSwap = true;
                }
                else if (stk[i].ngayMoSo.nam == stk[j].ngayMoSo.nam && 
                         stk[i].ngayMoSo.thang == stk[j].ngayMoSo.thang && 
                         stk[i].ngayMoSo.ngay > stk[j].ngayMoSo.ngay) {
                    shouldSwap = true;
                }
            }
            
            if (shouldSwap) {
                SoTietKiem temp = stk[i];
                stk[i] = stk[j];
                stk[j] = temp;
            }
        }
    }
}

void SoTietKiem::TimKiem(SoTietKiem stk[], int n, string maSo, int CMND) {
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (stk[i].maSo == maSo && stk[i].CMND == CMND) {
            found = true;
            cout << "Tim thay so tiet kiem: " << endl;
            stk[i].xuat();
            return;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay so tiet kiem phu hop." << endl;
    }
}

void SoTietKiem::LietKe(SoTietKiem stk[], int n) {
    NgayThang tuNgay, denNgay;
    bool hasResults = false;
    
    cout << "Nhap tu ngay (dd mm yyyy): ";
    cin >> tuNgay.ngay >> tuNgay.thang >> tuNgay.nam;
    
    if (!isRealDay(tuNgay.ngay, tuNgay.thang, tuNgay.nam)) {
        cout << "Ngay khong hop le!" << endl;
        return;
    }
    
    cout << "Nhap den ngay (dd mm yyyy): ";
    cin >> denNgay.ngay >> denNgay.thang >> denNgay.nam;
    
    if (!isRealDay(denNgay.ngay, denNgay.thang, denNgay.nam)) {
        cout << "Ngay khong hop le!" << endl;
        return;
    }
    
    auto isBeforeOrEqual = [](NgayThang date1, NgayThang date2) -> bool {
        if (date1.nam < date2.nam) return true;
        if (date1.nam > date2.nam) return false;
        if (date1.thang < date2.thang) return true;
        if (date1.thang > date2.thang) return false;
        return date1.ngay <= date2.ngay;
    };
    
    cout << "\nDanh sach so tiet kiem mo tu ngay " 
         << tuNgay.ngay << "/" << tuNgay.thang << "/" << tuNgay.nam
         << " den ngay " 
         << denNgay.ngay << "/" << denNgay.thang << "/" << denNgay.nam << ":\n";
    
    for (int i = 0; i < n; i++) {
        if (isBeforeOrEqual(tuNgay, stk[i].ngayMoSo) && isBeforeOrEqual(stk[i].ngayMoSo, denNgay)) {
            stk[i].xuat();
            hasResults = true;
        }
    }
    
    if (!hasResults) {
        cout << "Khong tim thay so tiet kiem nao trong khoang thoi gian nay.\n";
    }
}

int main() {
    freopen("input.txt" , "r", stdin);

    int n;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    cin.ignore();
    
   SoTietKiem *stk = new SoTietKiem[n];    
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":" << endl;
        stk[i].nhap();
    }
        
    float laiSuatNganHan, laiSuatDaiHan;
    cout << "\nNhap lai suat ngan han: ";
    cin >> laiSuatNganHan;
    cout << "Nhap lai suat dai han: ";
    cin >> laiSuatDaiHan;    
    for (int i = 0; i < n; i++) {
        stk[i].TinhToanTienHienTai(laiSuatNganHan, laiSuatDaiHan);
    }

    stk->SapXep(stk, n);
    
    cout << "\nDanh sach so tiet kiem sau khi sap xep theo so tien gui:" << endl;
    for (int i = 0; i < n; i++) {
        stk[i].xuat();
    }
    
    int choice = 0;
    do {
        cout << "\nVui long chon hanh dong ban muon thuc hien: \n";
        cout << "1. Tim kiem\n";
        cout << "2. Rut tien\n";
        cout << "3. Liet ke so tiet kiem\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                string maSoTim;
                int CMNDTim;
                cout << "Nhap ma so: ";
                cin >> maSoTim;
                cout << "Nhap CMND: ";
                cin >> CMNDTim;
                stk->TimKiem(stk, n, maSoTim, CMNDTim);
                break;
            }
            
            case 2: {
                string maSoRut;
                double soTienRut;
                cout << "Nhap ma so: ";
                cin >> maSoRut;
                cout << "Nhap so tien rut: ";
                cin >> soTienRut;
                stk->RutTien(stk, n, maSoRut, soTienRut, laiSuatNganHan, laiSuatDaiHan);
                break;
            }

            case 3:
                stk->LietKe(stk, n);
                break;
            
            case 0:
                cout << "Tam biet!" << endl;
                break;
                
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (choice != 0);
    
    delete[] stk;
    fclose(stdin);
    return 0;
}
