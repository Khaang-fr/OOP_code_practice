#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class Candidate 
{
    private:
        long long mhs;
        string ten;
        int ngay, thang, nam;
        float toan, van, anh;
    public:
        void nhap();
        void xuat();
};

class TestCandidate
{
    private:
        vector<Candidate> ds;
    public:
        void nhap();
        void xuatDanhSachDat();
};

void Candidate::nhap() {
    cin>> mhs;
    cin.ignore();
    getline(cin, ten);
    cin>> ngay>> thang>> nam;
    cin>> toan>> van>> anh; 
}
void Candidate::xuat() {
    if (toan + van + anh > 15) {
        cout<< mhs<< " "<< ten<< " "<< ngay<< " "<< thang<< " "<< nam<< " "<< toan<< " "<< van<< " "<< anh<< " " << endl;
    }
}
void TestCandidate::nhap() {
    int n;
    cin>> n;
    for (int i=0; i<n; i++) {
        Candidate a;
        a.Candidate::nhap();
        ds.push_back(a);
    }
}
void TestCandidate::xuatDanhSachDat() {
    for (int i=0; i<ds.size(); i++) {
        ds[i].Candidate::xuat();
    }
}
int main() {
    TestCandidate test;
    test.TestCandidate::nhap();
    cout << endl;
    test.TestCandidate::xuatDanhSachDat();
    return 0;
}
