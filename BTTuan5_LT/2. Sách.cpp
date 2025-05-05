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
    string getNXB() const {
        return NXB;
    }
    virtual ~Sach() {
        cout << "bye!" << endl;
    }
};

void Sach::Nhap() {
    cout << "Nhap ma sach: "; getline(cin, this->maSach);
    cout << "Nhap ngay nhap: "; cin >> this->ngayNhap.ngay >> this->ngayNhap.thang >> this->ngayNhap.nam;
    cout << "Nhap don gia cuon sach: "; cin >> this->DonGia;
    cout << "Nhap so luong cuon sach: "; cin >> this->soLuong;
    cin.ignore();
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
        double tien = this->getDonGia() * this->getSoLuong() + this->thue;
        return tien;
    }
    double getThanhTien() {
        return thanhTien;
    }
};

void sachThamKhao::nhap() {
    Sach::Nhap();
    cout << "Nhap so thue: "; cin >> this->thue;
    cin.ignore();
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
    Sach** danhSach; // Double pointer to manage Sach objects
    int soLuong;     // Total number of Sach objects
public:
    QuanLy() {
        this->danhSach = nullptr;
        this->soLuong = 0;
    }
    ~QuanLy() {
        for (int i = 0; i < soLuong; i++) {
            delete danhSach[i];
        }
        delete[] danhSach;
    }
    void nhapDanhSach() {
        cout << "Nhap so luong sach: "; cin >> soLuong; cout << endl;
        while (soLuong < 0) {
            cout << "So luong sach phai lon hon hoac bang 0. Nhap lai: ";
            cin >> soLuong;
        }
        cin.ignore();
        danhSach = new Sach*[soLuong];
        for (int i = 0; i < soLuong; i++) {
            int loai;
            cout << "Nhap loai sach (1: Sach Giao Khoa, 2: Sach Tham Khao): ";
            cin >> loai;
            cin.ignore();
            if (loai == 1) {
                danhSach[i] = new sachGiaoKhoa();
            } else if (loai == 2) {
                danhSach[i] = new sachThamKhao();
            } else {
                cout << "Loai khong hop le. Mac dinh la Sach Giao Khoa." << endl;
                danhSach[i] = new sachGiaoKhoa();
            }
            danhSach[i]->Nhap();
        }
    }
    void xuatDanhSach() {
        for (int i = 0; i < soLuong; i++) {
            danhSach[i]->Xuat();
            cout << endl;
        }
    }
    void tongThanhTien() {
        double sum = 0.0;
        for (int i = 0; i < soLuong; i++) {
            sachGiaoKhoa* sgk = dynamic_cast<sachGiaoKhoa*>(danhSach[i]);
            sachThamKhao* stk = dynamic_cast<sachThamKhao*>(danhSach[i]);
            if (sgk) {
                sum += sgk->getThanhTien();
            } else if (stk) {
                sum += stk->getThanhTien();
            }
        }
        cout << "Tong thanh tien la: " << sum << endl;
    }
    void trungBinhCongSTK() {
        double sum = 0.0;
        int count = 0;
        for (int i = 0; i < soLuong; i++) {
            sachThamKhao* stk = dynamic_cast<sachThamKhao*>(danhSach[i]);
            if (stk) {
                sum += stk->getDonGia();
                count++;
            }
        }
        if (count > 0) {
            cout << "Trung binh cong don gia cac sach tham khao la: " << sum / count << endl;
        } else {
            cout << "Khong co sach tham khao nao." << endl;
        }
    }
    void inSachTheoNXB(const string& nxb) {
        cout << "Danh sach sach thuoc NXB \"" << nxb << "\":" << endl;
        bool found = false;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i]->getNXB() == nxb) {
                danhSach[i]->Xuat();
                found = true;
            }
        }
        if (!found) {
            cout << "Khong co sach nao thuoc NXB \"" << nxb << "\"." << endl;
        }
    }
    void Menu() {
        int check;
        do {
            cout << "1. Nhap danh sach sach" << endl;
            cout << "2. Xuat danh sach sach" << endl;
            cout << "3. Tinh tong thanh tien" << endl;
            cout << "4. Tinh trung binh cong don gia cac sach tham khao" << endl;
            cout << "5. In sach theo NXB" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> check;
            cin.ignore();
            switch (check) {
                case 1: {
                    nhapDanhSach();
                    break;
                }
                case 2: {
                    xuatDanhSach();
                    break;
                }
                case 3: {
                    tongThanhTien();
                    break;
                }
                case 4: {
                    trungBinhCongSTK();
                    break;
                }
                case 5: {
                    string nxb;
                    cout << "Nhap ten NXB: ";
                    getline(cin, nxb);
                    inSachTheoNXB(nxb);
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
};

int main() {
    QuanLy q;
    q.Menu();
   
    return 0;
}
