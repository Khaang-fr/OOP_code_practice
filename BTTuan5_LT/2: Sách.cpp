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
    cout << "Nhap ma sach: "; cin >> this->maSach; cout << endl;
    cout << "Nhap ngay nhap: "; cin >> this->ngayNhap.ngay >> this->ngayNhap.thang >> this->ngayNhap.nam; cout << endl;
    cout << "Nhap don gia cuon sach: "; cin >> this->DonGia; cout << endl;
    cout << "Nhap so luong cuon sach: "; cin >> this->soLuong; cout << endl;
    cout << "Nhap nha xuat ban cuon sach: "; cin >> this->NXB; cout <<endl;
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
};

void sachGiaoKhoa::nhap() {
    Sach::Nhap();
    cout << "Nhap tinh trang cua sach: "; cin >> tinhTrang; cout << endl;
    thanhTien = this->tinhThanhTien();
}

void sachGiaoKhoa::xuat() {
    Sach::Xuat();
    cout << "Tinh trang cua sach: " << this->tinhTrang;
    cout << "Thanh tien tong sach la: " << this->thanhTien;
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
};

void sachThamKhao::nhap() {
    
}

class QuanLy : public sachGiaoKhoa, public sachThamKhao 
{
public:
    
};
