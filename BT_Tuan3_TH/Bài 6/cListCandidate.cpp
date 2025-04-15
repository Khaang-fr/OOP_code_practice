#include <iostream> 
#include <string>
#include <vector>
using namespace std;
#include "cCandidate.h" 
#include "cListCandidate.h"

void cListCandidate::nhap() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        cCandidate a;
        a.cCandidate::nhap();
        ds.push_back(a);
    }
}

void cListCandidate::xuatDanhSachDat() {
    cout << "\nDanh sach thi sinh dat (tong diem > 15):\n";
    for (int i = 0; i < ds.size(); i++) {
        ds[i].cCandidate::xuat();
    }
}
float cCandidate::getTotalScore() const {
    return toan + van + anh;
}

void cListCandidate::DiemCaoNhat() {
    if (ds.empty()) {
        cout << "Danh sach rong, khong co thi sinh nao.\n";
        return;
    }

    int indexMax = 0;
    float maxScore = ds[0].getTotalScore();

    for (int i = 1; i < ds.size(); i++) {
        float currentScore = ds[i].getTotalScore();
        if (currentScore > maxScore) {
            maxScore = currentScore;
            indexMax = i;
        }
    }

    cout << "\nThi sinh co tong diem cao nhat:\n";
    ds[indexMax].cCandidate::xuat();
}

void cListCandidate::SapXepTongDiemGiamDan() {
    for (int i = 0; i < ds.size() - 1; i++) {
        for (int j = i + 1; j < ds.size(); j++) {
            if (ds[i].getTotalScore() < ds[j].getTotalScore()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}
