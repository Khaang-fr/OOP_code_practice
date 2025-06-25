#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
public:
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
    }
    virtual void xuat() const {
        cout << "Ho ten: " << hoTen << ", Ngay sinh: " << ngaySinh;
    }
    virtual double tinhLuong() const = 0;
    virtual int layTuoi() const = 0;
    virtual ~NhanVien() {}
};
