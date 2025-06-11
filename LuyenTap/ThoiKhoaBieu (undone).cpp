#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isValidTimeFormat(const string timeStr) {
    if (timeStr.length() != 5 || timeStr[2] != ':') return false;
    for (int i = 0; i < 5; ++i) {
        if (i == 2) continue;
        if (!isdigit(timeStr[i])) return false;
    }
    return true;
}

int timeToMinutes(const string timeStr) {
    int hours, minutes, seconds;
    char colon;

    istringstream iss(timeStr);
    iss >> hours >> colon >> minutes;

    return hours * 60 + minutes;
}

class MonHoc
{
protected:
    string maMonHoc;
    string thoiGianBatDau;
    string thoiGianHoc;
    bool buoiSang;
public:
    MonHoc() {
        maMonHoc = "";
        thoiGianBatDau = "";
        thoiGianHoc = "";
        buoiSang = false;
    }
    MonHoc(string ma, string tgbd, string tgh) {
        maMonHoc = ma;
        thoiGianBatDau = tgbd;
        thoiGianHoc = tgh;
        buoiSang = timeToMinutes(tgbd) > 360 || timeToMinutes(tgbd) <= 1080;
    }
    virtual ~MonHoc() {
        // Destructor
        maMonHoc.clear();
        thoiGianBatDau.clear();
        thoiGianHoc.clear();
        buoiSang = false;
    }
    virtual void nhap() {
        do {
            cout << "Nhap ma mon hoc: ";
            getline(cin, maMonHoc);
            if (maMonHoc.empty()) {
                cout << "Ma mon hoc khong duoc de trong. Vui long nhap lai." << endl;
            }
            else if (maMonHoc.length() > 10) {
                cout << "Ma mon hoc khong duoc qua 10 ky tu. Vui long nhap lai." << endl;
                maMonHoc.clear();
            }
        } while (maMonHoc.empty());

        do {
            cout << "Nhap thoi gian bat dau (hh:mm): ";
            getline(cin, thoiGianBatDau);
            if (thoiGianBatDau.empty()) {
                cout << "Thoi gian bat dau khong duoc de trong. Vui long nhap lai." << endl;
            }
            else if (isValidTimeFormat(thoiGianBatDau) == false) {
                cout << "Thoi gian bat dau khong hop le. Vui long nhap theo dinh dang hh:mm." << endl;
                thoiGianBatDau.clear();
            }
        } while (thoiGianBatDau.empty() || isValidTimeFormat(thoiGianBatDau) == false);

        do {
            cout << "Nhap thoi gian hoc (hh:mm): ";
            getline(cin, thoiGianHoc);
            if (thoiGianHoc.empty()) {
                cout << "Thoi gian hoc khong duoc de trong. Vui long nhap lai." << endl;
            }
            else if (isValidTimeFormat(thoiGianHoc) == false) {
                cout << "Thoi gian hoc khong hop le. Vui long nhap theo dinh dang hh:mm." << endl;
                thoiGianHoc.clear();
            }
        } while (thoiGianHoc.empty() || isValidTimeFormat(thoiGianHoc) == false);

        buoiSang = timeToMinutes(thoiGianBatDau) > 360 || timeToMinutes(thoiGianBatDau) <= 1080;
    }
    virtual void xuat() const {
        cout << "Ma mon hoc: " << maMonHoc << endl;
        cout << "Thoi gian bat dau: " << thoiGianBatDau << endl;
        cout << "Thoi gian hoc: " << thoiGianHoc << endl;
        cout << "Day la mon hoc " << (buoiSang ? "buoi sang" : "buoi chieu") << endl;
    }
};

class HocTrenTruong : public MonHoc
{
private: 

public:
    HocTrenTruong() : MonHoc() {}

    HocTrenTruong(string ma, string tgbd, string tgh) : MonHoc(ma, tgbd, tgh) {}

    void nhap() override {
        MonHoc::nhap();
    }

    void xuat() const override {
        cout << "Mon hoc tren truong:" << endl;
        MonHoc::xuat();
    }
};

class HocOnline : public MonHoc
{
private:

public:
    HocOnline() : MonHoc() {}

    HocOnline(string ma, string tgbd, string tgh) : MonHoc(ma, tgbd, tgh) {}

    void nhap() override {
        MonHoc::nhap();
    }

    void xuat() const override {
        cout << "Mon hoc online:" << endl;
        MonHoc::xuat();
    }
};

class Tuhoc : public MonHoc
{
private:

public:
    Tuhoc() : MonHoc() {}

    Tuhoc(string ma, string tgbd, string tgh) : MonHoc(ma, tgbd, tgh) {}

    void nhap() override {
        MonHoc::nhap();
    }

    void xuat() const override {
        cout << "Mon hoc tu hoc:" << endl;
        MonHoc::xuat();
    }
};

class ThoiKhoaBieu
{
private:
    MonHoc** dsMonHoc;
    int soMonHoc;
public:
    ThoiKhoaBieu() : dsMonHoc(nullptr), soMonHoc(0) {}

    ~ThoiKhoaBieu() {
        for (int i = 0; i < soMonHoc; ++i) {
            delete dsMonHoc[i];
        }
        delete[] dsMonHoc;
    }

    void nhap() {
        cout << "Nhap so luong mon hoc: ";
        cin >> soMonHoc;
        cin.ignore();

        dsMonHoc = new MonHoc*[soMonHoc];
        for (int i = 0; i < soMonHoc; ++i) {
            int loaiMon;
            cout << "Nhap loai mon hoc (1: Hoc tren truong, 2: Hoc online, 3: Tu hoc): ";
            cin >> loaiMon;
            cin.ignore();

            if (loaiMon == 1) {
                dsMonHoc[i] = new HocTrenTruong();
            } else if (loaiMon == 2) {
                dsMonHoc[i] = new HocOnline();
            } else if (loaiMon == 3) {
                dsMonHoc[i] = new Tuhoc();
            } else {
                cout << "Loai mon hoc khong hop le. Vui long nhap lai." << endl;
                --i;
                continue;
            }
            dsMonHoc[i]->nhap();
        }
    }

    void xuat() const {
        cout << "Danh sach thoi khoa bieu:" << endl;
        for (int i = 0; i < soMonHoc; ++i) {
            dsMonHoc[i]->xuat();
            cout << endl;
        }
    }
};

int main() 
{
    ThoiKhoaBieu tkb;
    tkb.nhap();
    tkb.xuat();
    return 0;
}
