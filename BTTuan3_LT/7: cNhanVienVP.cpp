#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct NgayThang {
    int ngay;
    int thang;
    int nam;
    NgayThang() {
        ngay = 1;
        thang = 1;
        nam = 2025;
    }
    NgayThang(int ng, int th, int n) {
        ngay = ng;
        thang = th;
        nam = n;
    }
    void hienThi() const {
        cout << setfill('0') << setw(2) << ngay << "/" 
             << setfill('0') << setw(2) << thang << "/" 
             << nam;
    }
    string toString() const {
        char buffer[11];
        sprintf(buffer, "%02d/%02d/%04d", ngay, thang, nam);
        return string(buffer);
    }
};

class NhanVienVP {
private:
    string maNhanVien;
    string hoTen;
    NgayThang ngaySinh;
    double luong;

public:
    NhanVienVP() {
        maNhanVien = "";
        hoTen = "";
        ngaySinh = NgayThang();
        luong = 0.0;
    }
    NhanVienVP(string maNV, string ht, NgayThang ns, double l) {
        maNhanVien = maNV;
        hoTen = ht;
        ngaySinh = ns;
        luong = l;
    }
    NhanVienVP(string maNV, string ht, int ngay, int thang, int nam, double l) {
        maNhanVien = maNV;
        hoTen = ht;
        ngaySinh = NgayThang(ngay, thang, nam);
        luong = l;
    }
    string getMaNhanVien() const {
        return maNhanVien;
    }
    string getHoTen() const {
        return hoTen;
    }
    NgayThang getNgaySinh() const {
        return ngaySinh;
    }
    int getNgay() const {
        return ngaySinh.ngay;
    }
    int getThang() const {
        return ngaySinh.thang;
    }
    int getNam() const {
        return ngaySinh.nam;
    }
    double getLuong() const {
        return luong;
    }
    void setMaNhanVien(string maNV) {
        maNhanVien = maNV;
    }
    void setHoTen(string ht) {
        hoTen = ht;
    }
    void setNgaySinh(NgayThang ns) {
        ngaySinh = ns;
    }
    void setNgaySinh(int ngay, int thang, int nam) {
        ngaySinh.ngay = ngay;
        ngaySinh.thang = thang;
        ngaySinh.nam = nam;
    }
    void setLuong(double l) {
        luong = l;
    }
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNhanVien);
        
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        
        cout << "Nhap ngay sinh:" << endl;
        cout << "  Ngay: ";
        cin >> ngaySinh.ngay;
        cout << "  Thang: ";
        cin >> ngaySinh.thang;
        cout << "  Nam: ";
        cin >> ngaySinh.nam;
        
        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore();
    }
    void xuat() const {
        cout << "Ma nhan vien: " << maNhanVien << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: ";
        ngaySinh.hienThi();
        cout << endl;
        cout << "Luong: " << luong << endl;
    }
    int tinhTuoi(int namHienTai) const {
        return namHienTai - ngaySinh.nam;
    }
    void tuoiCaoNhat (NhanVienVP nv[], int n) {
        int Max=0;
        for (int i=0; i<n; i++) {
            int temp = nv[i].tinhTuoi(2025);
            Max = max(temp, Max);
        }
        cout << "Nhan vien cao tuoi nhat la:" << endl;
        for (int i=0; i<n; i++) {
            if (nv[i].tinhTuoi(2025) == Max) {
                nv[i].xuat();
                cout << endl;
            }
        }
    }
};

void LuongCaoNhat(NhanVienVP nv[], int n) {
    if (n <= 0) {
        cout << "Khong co nhan vien nao!" << endl;
        return;
    }
    
    double maxLuong = nv[0].getLuong();
    for (int i = 1; i < n; i++) {
        if (nv[i].getLuong() > maxLuong) {
            maxLuong = nv[i].getLuong();
        }
    }
    
    cout << "Nhan vien co luong cao nhat (" << fixed << setprecision(0) << maxLuong << "):" << endl;
    for (int i = 0; i < n; i++) {
        if (nv[i].getLuong() == maxLuong) {
            nv[i].xuat();
            cout << endl;
        }
    }
}

double tinhTongLuong(NhanVienVP nv[], int n) {
    double tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += nv[i].getLuong();
    }
    return tongLuong;
}

bool soSanhTheoLuong(const NhanVienVP &a, const NhanVienVP &b) {
    return a.getLuong() < b.getLuong();
}

void sapXepTheoLuongTangDan(NhanVienVP nv[], int n) {
    sort(nv, nv + n, soSanhTheoLuong);
}

int main() {
    int n; cin >> n;
    cin.ignore();
    NhanVienVP *nv;
    nv = new NhanVienVP[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;
        nv[i].nhap();
    }
    cout << "Danh sach nhan vien sap xep theo luong tang dan" << endl;
    sapXepTheoLuongTangDan(nv, n);
    for (int i = 0; i < n; i++) {
        cout << "Thong tin nhan vien " << i + 1 << " (Luong: " << fixed << setprecision(0) << nv[i].getLuong() << "):" << endl;
        nv[i].xuat();
    }
    cout << "Nhan vien co tuoi cao nhat" << endl;
    nv->tuoiCaoNhat(nv, n);
    cout << "Nhan vien co luong cao nhat" << endl;
    LuongCaoNhat(nv, n); 
    cout << "Tong luong cong ty phai tra: " << endl;
    double tongLuong = tinhTongLuong(nv, n);
    cout << "Tong luong: " << fixed << setprecision(0) << tongLuong << endl;  
    delete[] nv;
    return 0;
}
