#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NgayThang {
    int ngay, thang, nam;
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

class Sach {
private:
    string maSach;
    NgayThang ngayNhap;
    double DonGia;
    int soLuong;
    string NXB;
public:
    Sach() {
        maSach = "";
        ngayNhap = NgayThang();
        DonGia = 0.0;
        soLuong = 0;
        NXB = "";
    }
    Sach(string ma, NgayThang Ngay, double gia, int luong, string nxb) {
        maSach = ma;
        ngayNhap = NgayThang(Ngay.ngay, Ngay.thang, Ngay.nam);
        DonGia = gia;
        soLuong = luong;
        NXB = nxb;
    }
    Sach(string ma, int ngay, int thang, int nam, double gia, int luong, string nxb) {
        maSach = ma;
        ngayNhap = NgayThang(ngay, thang, nam);
        DonGia = gia;
        soLuong = luong;
        NXB = nxb;
    }
    void Nhap();
    void Xuat();
    double getDonGia() const {
        return DonGia;
    }
    int getSoLuong() const {
        return soLuong;
    }
    ~Sach() {
        cout << "bye!" << endl;
    }
};

void Sach::Nhap() {
    cout << "Nhap ma sach: "; getline(cin, this->maSach);
    cout << "Nhap ngay nhap: "; cin >> this->ngayNhap.ngay >> this->ngayNhap.thang >> this->ngayNhap.nam;
    cout << "Nhap don gia cuon sach: "; cin >> this->DonGia;
    cout << "Nhap so luong cuon sach: "; cin >> this->soLuong;
    cout << "Nhap nha xuat ban cuon sach: "; getline(cin, this->NXB);
}

void Sach::Xuat() {
    cout << "Ma sach: " << this->maSach << endl;
    cout << "Ngay nhap sach: "; this->ngayNhap.hienThi(); cout << endl;
    cout << "Don gia cua cuon sach: " << this->DonGia << " - "
         << "So luong cuon sach: " << this->soLuong << endl;
    cout << "Nha xuat ban cuon sach: " << this->NXB << endl;
}

class sachGiaoKhoa : public Sach
{
private: 
    string tinhTrang;
    double thanhTien;
public:
    void nhap();
    void xuat();
    double tinhThanhTien() {
        double tien;
        if (tinhTrang == "moi") {
            tien = this->getSoLuong() * this->getDonGia();
        } else {
            tien = this->getSoLuong() * this->getDonGia() / 2;
        }
        return tien;
    }
    double getThanhTien() {
        return thanhTien;
    }
};

void sachGiaoKhoa::nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang cua sach: "; getline(cin, this->tinhTrang); cout << endl;
    thanhTien = this->sachGiaoKhoa::tinhThanhTien();
}

void sachGiaoKhoa::xuat() {
    Sach::Xuat();
    cout << "Tinh trang cua sach: " << this->tinhTrang << endl;
    cout << "Thanh tien tong sach la: " << this->thanhTien << endl;
}

class sachThamKhao : public Sach 
{
private:
    double thue;
    double thanhTien;
public:
    void nhap();
    void xuat();
    double tinhThanhTien() {
        return this->getDonGia() * this->getSoLuong() + this->thue;
    }
    double getThanhTien() {
        return thanhTien;
    }
};

void sachThamKhao::nhap() {
    Sach::Nhap();
    cin.ignore();
    cout << "Nhap so thue: "; cin >> this->thue; cout << endl;
    this->thanhTien = sachThamKhao::tinhThanhTien();
}

void sachThamKhao::xuat() {
    Sach::Xuat();
    cout << "Thue: " << this->thue << endl;
    cout << "Thanh tien tong sach la: " << this->thanhTien << endl;
}

class QuanLy 
{
private:
    sachGiaoKhoa gk[10];
    sachThamKhao tk[10];
    int k, h;
    int check;
public:
    QuanLy() { 
        this->k = 0;
        this->h = 0;
        this->check = 0;
    }
    void nhapDanhSach(sachGiaoKhoa sgk[], int& h, sachThamKhao stk[], int& k) {
        do {
            cout << "Nhap so sach giao khoa: "; cin >> h; cout << endl;
            if (h < 1 || h > 10) {
                cout << "Vui long nhap so tu 1 den 10." << endl;
            }
        } while (h < 1 || h > 10);
        cin.ignore();
        for (int i = 0; i < h; i++) {
            sgk[i].sachGiaoKhoa::nhap();
        }

        do {
            cout << "Nhap so sach tham khao: "; cin >> k; cout << endl;
            if (k < 1 || k > 10) {
                cout << "Vui long nhap so tu 1 den 10." << endl;
            }
        } while (k < 1 || k > 10);
        cin.ignore();
        for (int i = 0; i < k; i++) {
            stk[i].sachThamKhao::nhap();
        }
    }
    void xuatDanhSach(sachGiaoKhoa sgk[], int h, sachThamKhao stk[], int k) {
        for (int i = 0; i < h; i++) {
            sgk[i].xuat();
        }
        cout << endl;
        for (int i = 0; i < k; i++) {
            stk[i].xuat();
        }
    }
    void tongThanhTien(sachGiaoKhoa sgk[], int h, sachThamKhao stk[], int k) {
        double sum = 0.0;
        for (int i = 0; i < h; i++) {
            sum += sgk[i].getThanhTien();
        }
        for (int i = 0; i < k; i++) {
            sum += stk[i].getThanhTien();
        }
        cout << "Tong thanh tien la: " << sum << endl;
    }
    void trungBinhCongSTK(sachThamKhao stk[], int k) {
        double sum = 0.0;
        for (int i = 0; i < k; i++) {
            sum+= stk[i].getDonGia();
        }
        cout << "Trung binh cong don gia cac sach tham khao la: " << sum << endl;
    }
    void Menu();
};

void QuanLy::Menu() {
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Nhap danh sach sach" << endl;
        cout << "2. Xuat danh sach sach" << endl;
        cout << "3. Tinh tong thanh tien" << endl;
        cout << "4. Tinh trung binh cong don gia cac sach tham khao" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> check;
        cin.ignore();
        switch (check) {
            case 1: {
                nhapDanhSach(gk, h, tk, k);
                break;
            }
            case 2: {
                xuatDanhSach(gk, h, tk, k);
                break;
            }
            case 3: {
                tongThanhTien(gk, h, tk, k);
                break;
            }
            case 4: {
                trungBinhCongSTK(tk, k);
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh." << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
            }
        }
    } while (check != 0);
}

int main() {
    QuanLy q;
    q.Menu();
   
    return 0;
}
