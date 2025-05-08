#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class QuanLy 
{
private:
    Sach** danhSach;
    int soLuong;
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
