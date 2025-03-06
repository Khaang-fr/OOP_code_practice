#include <iostream>
using namespace std;

class SoPhuc
{
private:
    float thuc, ao;
public:
    void Nhap();
    void Xuat();
    SoPhuc Cong(SoPhuc);
    SoPhuc Tru(SoPhuc);
    void Nhan(SoPhuc  a, SoPhuc b) {
        thuc = a.thuc * b.thuc - a.ao * b.ao;
        ao = a.thuc * b.ao + a.ao * b.thuc;
    }
    void Chia(SoPhuc a, SoPhuc b) {
        thuc = (a.thuc * b.thuc + a.ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
        ao = (a.ao * b.thuc - a.thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
    }
};
void SoPhuc::Nhap()
{
    cin >> thuc >> ao;
}
void SoPhuc::Xuat()
{
    if (ao < 0) {
        cout << thuc << ao << "i" << endl;
    } else if (ao == 0) {
        cout << thuc << endl;
    } else {
        cout << thuc << "+" << ao << "i" << endl;
    }
}
SoPhuc SoPhuc::Cong(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = thuc + a.thuc;
    kq.ao = ao + a.ao;
    return kq;
}
SoPhuc SoPhuc::Tru(SoPhuc a)
{
    SoPhuc kq;
    kq.thuc = thuc - a.thuc;
    kq.ao = ao - a.ao;
    return kq;
}
int main()
{
    SoPhuc a, b, c;
    a.Nhap();
    b.Nhap();
    c = a.Cong(b);
    c.Xuat();
    c = a.Tru(b);
    c.Xuat();
    c.Nhan(a, b);
    c.Xuat();
    c.Chia(a, b);
    c.Xuat();
    return 0;
}
