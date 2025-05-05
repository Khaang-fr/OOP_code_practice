#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV, hoTen, diaChi;
    int tongSoTC;
    double diemTB;
public:
    virtual void nhap() {
        cout << "Nhap ma SV: "; getline(cin, maSV);
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap dia chi: "; getline(cin, diaChi);
        cout << "Nhap tong so tin chi: "; cin >> tongSoTC;
        cout << "Nhap diem trung binh: "; cin >> diemTB;
        cin.ignore();
    }

    virtual void xuat() const {
        cout << "Ma SV: " << maSV << "\n"
             << "Ho ten: " << hoTen << "\n"
             << "Dia chi: " << diaChi << "\n"
             << "Tong so tin chi: " << tongSoTC << "\n"
             << "Diem trung binh: " << diemTB << "\n";
    }

    virtual bool totNghiep() const = 0;
    virtual bool laDaiHoc() const { return false; }
    virtual double getDiemTB() const { return diemTB; }

    virtual ~SinhVien() {}
};

class CaoDang : public SinhVien {
private:
    double diemTotNghiep;
public:
    void nhap() {
        SinhVien::nhap();
        cout << "Nhap diem tot nghiep: ";
        cin >> diemTotNghiep;
        cin.ignore();
    }

    void xuat() const {
        SinhVien::xuat();
        cout << "Diem tot nghiep: " << diemTotNghiep << "\n"
             << "He: Cao dang";
        if (totNghiep()) cout << " (Dat tot nghiep)";
        else cout << " (Khong dat)";
        cout << "\n";
    }

    bool totNghiep() const {
        return (tongSoTC >= 110 && diemTB >= 5 && diemTotNghiep >= 5);
    }
};

class DaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void nhap() {
        SinhVien::nhap();
        cout << "Nhap ten luan van: ";
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
        cin.ignore();
    }

    void xuat() const {
        SinhVien::xuat();
        cout << "Ten luan van: " << tenLuanVan << "\n"
             << "Diem luan van: " << diemLuanVan << "\n"
             << "He: Dai hoc";
        if (totNghiep()) cout << " (Dat tot nghiep)";
        else cout << " (Khong dat)";
        cout << "\n";
    }

    bool totNghiep() const {
        return (tongSoTC >= 145 && diemTB >= 5 && diemLuanVan >= 5);
    }

    bool laDaiHoc() const {
        return true;
    }
};

int main() {
    vector<SinhVien*> ds;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        int loai;
        cout << "1. Cao dang | 2. Dai hoc: ";
        cin >> loai;
        cin.ignore();

        SinhVien* sv;
        if (loai == 1) sv = new CaoDang();
        else sv = new DaiHoc();

        sv->nhap();
        ds.push_back(sv);
    }

    cout << "DANH SACH SINH VIEN\n";
    for (SinhVien* sv : ds) {
        sv->xuat();
    }

    cout << "SINH VIEN DAT TOT NGHIEP\n";
    for (SinhVien* sv : ds) {
        if (sv->totNghiep()) {
            sv->xuat();
        }
    }

    cout << "SINH VIEN KHONG DAT TOT NGHIEP\n";
    for (SinhVien* sv : ds) {
        if (!sv->totNghiep()) {
            sv->xuat();
        }
    }

    cout << "SINH VIEN DAI HOC CO DIEM TB CAO NHAT" << endl;
    double maxDiem = -1;
    SinhVien* bestSV = nullptr;
    for (SinhVien* sv : ds) {
        if (sv->laDaiHoc() && sv->getDiemTB() > maxDiem) {
            maxDiem = sv->getDiemTB();
            bestSV = sv;
        }
    }
    if (bestSV) bestSV->xuat();
    else cout << "Khong co sinh vien dai hoc nao.\n";

    for (SinhVien* sv : ds)
        delete sv;

    return 0;
}
