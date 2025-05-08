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
