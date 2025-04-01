#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct tienTe {
    double tiGia;
};

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

class GiaoDich {
private:
    string maGiaoDich;
    NgayThang ngayGiaoDich;
    double donGia;
    int soLuong;
public:
    GiaoDich() : maGiaoDich(""), donGia(0), soLuong(0) {}
    ~GiaoDich() {
        cout << "bye!" << endl;
    }
    void nhap();
    void xuat();
    double getDonGia() const {
        return donGia;
    }
    double getSoLuong() const {
        return soLuong;
    }
};

void GiaoDich::nhap() {
    cout << "Nhap ma giao dich: "; getline(cin, this->maGiaoDich);
    do {
        cout << "Nhap ngay giao dich (dd mm yyyy): ";
        cin >> this->ngayGiaoDich.ngay >> this->ngayGiaoDich.thang >> this->ngayGiaoDich.nam;
        if (this->ngayGiaoDich.ngay < 1 || this->ngayGiaoDich.ngay > 31 ||
            this->ngayGiaoDich.thang < 1 || this->ngayGiaoDich.thang > 12 ||
            this->ngayGiaoDich.nam < 1900) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai." << endl;
        } else {
            break;
        }
    } while (true);
    cout << "Nhap don gia: "; cin >> this->donGia;
    cout << "Nhap so luong: "; cin >> this->soLuong;
    cin.ignore();
}

void GiaoDich::xuat() {
    cout << "Ma giao dich: " << this->maGiaoDich << endl;
    cout << "Ngay giao dich: "; ngayGiaoDich.hienThi(); cout << endl;
    cout << "Don gia: " << this->donGia << " - So luong: " << this->soLuong << endl;
}

class Vang : public GiaoDich {
private:
    string loaiVang;
    double thanhTien;
public:
    Vang() : loaiVang(""), thanhTien(0) {}
    void nhap();
    void xuat();
    double getThanhTien() const {
        return thanhTien;
    }
    ~Vang() {
        cout << "bye!" << endl;
    }
};

void Vang::nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai vang: "; getline(cin, this->loaiVang);
    this->thanhTien = this->getDonGia() * this->getSoLuong();
}

void Vang::xuat() {
    GiaoDich::xuat();
    cout << "Loai vang: " << this->loaiVang << endl;
    cout << "Thanh tien: " << this->thanhTien << endl;
}

class TienTe : public GiaoDich {
private:
    static tienTe Euro;
    static tienTe USD;
    string loaiTien;
    double thanhTien;
public:
    TienTe() : loaiTien(""), thanhTien(0) {}
    void nhap();
    void xuat();
    double getThanhTien() const {
        return thanhTien;
    }
    string getLoaiTien() const {
        return loaiTien;
    }
    ~TienTe() {
        cout << "bye!" << endl;
    }
};

tienTe TienTe::Euro = {27679};
tienTe TienTe::USD = {25600};

void TienTe::nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai tien: "; getline(cin, this->loaiTien);
    if (this->loaiTien == "Vietnam") {
        this->thanhTien = this->getDonGia() * this->getSoLuong();
    } else {
        if (this->loaiTien == "Euro") {
            this->thanhTien = this->getDonGia() * this->getSoLuong() * Euro.tiGia;
        } else if (this->loaiTien == "USD") {
            this->thanhTien = this->getDonGia() * this->getSoLuong() * USD.tiGia;
        }
    }
}

void TienTe::xuat() {
    GiaoDich::xuat();
    cout << "Loai tien: " << this->loaiTien << endl;
    cout << "Thanh tien: " << this->thanhTien << endl;
}

class QuanLy {
private:
    vector<Vang> danhSachVang;
    vector<TienTe> danhSachTienTe;

public:
    QuanLy() {}
    void Menu();
    void themGiaoDichVang();
    void themGiaoDichTienTe();
    void hienThiDanhSachGiaoDich();
    void vangCoThanhTienCaoNhat();
    void tienTeEuroCoThanhTienThapNhat();
    void hienThiGiaoDichLonHonMotTy();
    ~QuanLy() {
        cout << "bye!" << endl;
        danhSachVang.clear();
        danhSachTienTe.clear();
    }
};

const double ty = 1e9;

void QuanLy::Menu() {
    int check;
    do {
        cout << "1. Them giao dich vang" << endl;
        cout << "2. Them giao dich tien te" << endl;
        cout << "3. Hien thi danh sach giao dich" << endl;
        cout << "4. Tim giao dich vang co thanh tien cao nhat" << endl;
        cout << "5. Tim giao dich tien te loai Euro co thanh tien thap nhat" << endl;
        cout << "6. Hien thi giao dich co thanh tien lon hon 1.000.000.000" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> check;
        cin.ignore();

        switch (check) {
        case 1:
            themGiaoDichVang();
            break;
        case 2:
            themGiaoDichTienTe();
            break;
        case 3:
            hienThiDanhSachGiaoDich();
            break;
        case 4:
            vangCoThanhTienCaoNhat();
            break;
        case 5:
            tienTeEuroCoThanhTienThapNhat();
            break;
        case 6:
            hienThiGiaoDichLonHonMotTy();
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while (check != 0);
}

void QuanLy::themGiaoDichVang() {
    Vang vang;
    cout << endl << "Nhap thong tin giao dich vang:" << endl;
    vang.nhap();
    danhSachVang.push_back(vang);
    cout << "Da them giao dich vang thanh cong." << endl;
}

void QuanLy::themGiaoDichTienTe() {
    TienTe tienTe;
    cout << endl << "Nhap thong tin giao dich tien te:" << endl;
    tienTe.nhap();
    danhSachTienTe.push_back(tienTe);
    cout << "Da them giao dich tien te thanh cong." << endl;
}

void QuanLy::hienThiDanhSachGiaoDich() {
    cout << endl << "Danh sach giao dich vang:" << endl;
    for (size_t i = 0; i < danhSachVang.size(); ++i) {
        cout << endl << "Giao dich vang " << i + 1 << ":" << endl;
        danhSachVang[i].xuat();
    }

    cout << endl << "Danh sach giao dich tien te:" << endl;
    for (size_t i = 0; i < danhSachTienTe.size(); ++i) {
        cout << endl << "Giao dich tien te " << i + 1 << ":" << endl;
        danhSachTienTe[i].xuat();
    }
}

void QuanLy::vangCoThanhTienCaoNhat() {
    if (danhSachVang.empty()) {
        cout << "Khong co giao dich vang nao." << endl;
        return;
    }
    Vang *maxVang = &danhSachVang[0];
    for (size_t i = 1; i < danhSachVang.size(); ++i) {
        if (danhSachVang[i].getThanhTien() > maxVang->getThanhTien()) {
            maxVang = &danhSachVang[i];
        }
    }
    cout << endl << "Giao dich vang co thanh tien cao nhat:" << endl;
    maxVang->xuat();
}

void QuanLy::tienTeEuroCoThanhTienThapNhat() {
    TienTe *minTienTe = nullptr;
    for (size_t i = 0; i < danhSachTienTe.size(); ++i) {
        if (danhSachTienTe[i].getThanhTien() > 0 && danhSachTienTe[i].getThanhTien() < ty && danhSachTienTe[i].getLoaiTien() == "Euro") {
            if (minTienTe == nullptr || danhSachTienTe[i].getThanhTien() < minTienTe->getThanhTien()) {
                minTienTe = &danhSachTienTe[i];
            }
        }
    }

    if (minTienTe != nullptr) {
        cout << endl << "Giao dich tien te loai Euro co thanh tien thap nhat:" << endl;
        minTienTe->xuat();
    } else {
        cout << "Khong co giao dich tien te loai Euro nao." << endl;
    }
}

void QuanLy::hienThiGiaoDichLonHonMotTy() {
    cout << endl << "Danh sach giao dich co thanh tien lon hon 1.000.000.000:" << endl;

    for (size_t i = 0; i < danhSachVang.size(); ++i) {
        if (danhSachVang[i].getThanhTien() > ty) {
            cout << endl << "Giao dich vang " << i + 1 << ":" << endl;
            danhSachVang[i].xuat();
        }
    }

    for (size_t i = 0; i < danhSachTienTe.size(); ++i) {
        if (danhSachTienTe[i].getThanhTien() > ty) {
            cout << endl << "Giao dich tien te " << i + 1 << ":" << endl;
            danhSachTienTe[i].xuat();
        }
    }
}

int main() {
    QuanLy menu;
    menu.Menu();
    return 0;
}
