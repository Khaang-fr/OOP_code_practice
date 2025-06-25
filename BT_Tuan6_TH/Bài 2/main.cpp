#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "GiaoDich.h"

int main() {
    vector<GiaoDich*> ds;
    int nDat, nNha, nCu;
    cout << "So luong giao dich Dat: "; cin >> nDat;
    for (int i = 0; i < nDat; i++) {
        string m, n; double dg, dt; char l;
        cout << "Nhap (Ma Ngay dg dt Loai): ";
        cin >> m >> n >> dg >> dt >> l;
        ds.push_back(new GiaoDichDat(m, n, dg, dt, l));
    }
    cout << "So luong giao dich Nha pho: "; cin >> nNha;
    cin.ignore();
    for (int i = 0; i < nNha; i++) {
        string m, n, l, dc; double dg, dt;
        cout << "Nhap (Ma Ngay dg dt Loai DiaChi): ";
        cin >> m >> n >> dg >> dt;
        cin.ignore();
        getline(cin, l);
        getline(cin, dc);
        ds.push_back(new GiaoDichNhaPho(m, n, dg, dt, l, dc));
    }
    cout << "So luong giao dich Chung cu: "; cin >> nCu;
    for (int i = 0; i < nCu; i++) {
        string m, n, mc; double dg, dt; int t;
        cout << "Nhap (Ma Ngay dg dt MaCan Tang): ";
        cin >> m >> n >> dg >> dt >> mc >> t;
        ds.push_back(new GiaoDichChungCu(m, n, dg, dt, mc, t));
    }

    int cntDat = 0, cntNha = 0, cntCu = 0;
    for (auto p : ds) {
        if (dynamic_cast<GiaoDichDat*>(p)) cntDat++;
        else if (dynamic_cast<GiaoDichNhaPho*>(p)) cntNha++;
        else if (dynamic_cast<GiaoDichChungCu*>(p)) cntCu++;
    }
    cout << "\nTong giao dich Dat: " << cntDat
         << "\nTong giao dich Nha pho: " << cntNha
         << "\nTong giao dich Chung cu: " << cntCu << endl;

    double sumCu = 0;
    for (auto p : ds)
        if (auto q = dynamic_cast<GiaoDichChungCu*>(p))
            sumCu += q->tinhThanhTien();
    cout << fixed << setprecision(2)
         << "Trung binh thanh tien chung cu: "
         << (cntCu ? sumCu / cntCu : 0) << endl;

    double maxNha = 0; GiaoDichNhaPho* bestNha = nullptr;
    for (auto p : ds) if (auto q = dynamic_cast<GiaoDichNhaPho*>(p)) {
        if (q->tinhThanhTien() > maxNha) {
            maxNha = q->tinhThanhTien();
            bestNha = q;
        }
    }
    cout << "\nGiao dich Nha pho co thanh tien cao nhat:\n";
    if (bestNha) bestNha->xuat();

    cout << "\nGiao dich thang 12/2024:\n";
    for (auto p : ds) {
        string ngay = p->getNgay();
        if (ngay.length() >= 10) {
            int th = stoi(ngay.substr(3, 2));
            int nm = stoi(ngay.substr(6, 4));
            if (th == 12 && nm == 2024) p->xuat();
        }
    }

    for (auto p : ds) delete p;

    return 0;
}
