#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Openness
{
protected: 
    int rate;
    string Highmsg = "Nguoi co diem cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc...";
    string Lowmsg = "Nguoi co diem thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh, quen thuoc va thuc te.";
public:
    Openness();
    Openness(int O);
    ~Openness();
    void Nhap();
    void Xuat();
};

Openness::Openness() {
    rate = 0;
}
Openness::Openness(int O) {
    rate = O;
}
Openness::~Openness() {

}
void Openness::Nhap() {
    cin >> this->rate;
}
void Openness::Xuat() {
    cout << this->rate << "-" << "San sang trai nghiem (O) ";
    if (rate >= 70) {
        cout << Highmsg << endl;
    } else if (rate <= 30) {
        cout <<  Lowmsg << endl;
    } else {
        cout << "Khong xac dinh ro" << endl;
    }
}

class Coscientiousness
{
protected:
    int rate;
    string Highmsg = "Nguoi co diem cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot. Ho thuong la nguoi gan bo,trung thanh voi to chuc.";
    string Lowmsg = "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu ky luat cua to chuc kem.";
public:
    Coscientiousness();
    Coscientiousness(int C);
    ~Coscientiousness();
    void Nhap();
    void Xuat();
};

Coscientiousness::Coscientiousness() {
    rate = 0;
}
Coscientiousness::Coscientiousness(int C) {
    rate = C;
}
Coscientiousness::~Coscientiousness() {

}
void Coscientiousness::Nhap() {
    cin >> this->rate;
}
void Coscientiousness::Xuat() {
    cout << this->rate << "-" << "Tu chu tan tam (C) ";
    if (rate >= 70) {
        cout << Highmsg << endl;
    } else if (rate <= 30) {
        cout <<  Lowmsg << endl;
    } else {
        cout << "Khong xac dinh ro" << endl;
    }
}

class Extraversion
{
protected:
    int rate;
    string Highmsg = "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than.";
    string Lowmsg = "Nguoi co diem thap o yeu to nay thuong ngai giao tiep, khong thich su noi bat, thich duoc lam viec doc lap.";
public:
    Extraversion();
    Extraversion(int E);
    ~Extraversion();
    void Nhap();
    void Xuat();
};
Extraversion::Extraversion() {
    rate = 0;
}
Extraversion::Extraversion(int E) {
    rate = E;
}
Extraversion::~Extraversion() {

}
void Extraversion::Nhap() {
    cin >> this->rate;
}
void Extraversion::Xuat() {
    cout << this->rate << "-" << "Huong ngoai (E) ";
    if (rate >= 70) {
        cout << Highmsg << endl;
    } else if (rate <= 30) {
        cout <<  Lowmsg << endl;
    } else {
        cout << "Khong xac dinh ro" << endl;
    }
}

class Agreeableness
{
protected:
    int rate;
    string Highmsg = "Nguoi co diem cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi 'thieu chinh kien'.";
    string Lowmsg = "Nguoi co diem thap thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao.";
public:
    Agreeableness();
    Agreeableness(int A);
    ~Agreeableness();
    void Nhap();
    void Xuat();
};

Agreeableness::Agreeableness() {
    rate = 0;
}
Agreeableness::Agreeableness(int A) {
    rate = A;
}
Agreeableness::~Agreeableness() {

}
void Agreeableness::Nhap() {
    cin >> this->rate;
}
void Agreeableness::Xuat() {
    cout << this->rate << "-" << "Hoa dong de chiu (A) ";
    if (rate >= 70) {
        cout << Highmsg << endl;
    } else if (rate <= 30) {
        cout <<  Lowmsg << endl;
    } else {
        cout << "Khong xac dinh ro" << endl;
    }
}

class Neuroticism
{
protected:
    int rate;
    string Highmsg = "Nguoi co diem cao o yeu to nay thuong co cac cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem.";
    string Lowmsg = "Nguoi co diem thap o yeu to nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than.";
public: 
    Neuroticism();
    Neuroticism(int N);
    ~Neuroticism();
    void Nhap();
    void Xuat();
};

Neuroticism::Neuroticism() : rate(0) {}
Neuroticism::Neuroticism(int N) : rate(N) {}
Neuroticism::~Neuroticism() {}
void Neuroticism::Nhap() {
    cin >> this->rate;
}
void Neuroticism::Xuat() {
    cout << this->rate << "-Bat on cam xuc (N) ";
    if (rate >= 70) {
        cout << Highmsg << endl;
    } else if (rate <= 30) {
        cout <<  Lowmsg << endl;
    } else {
        cout << "Khong xac dinh ro" << endl;
    }
}

class Personality : public Openness, public Coscientiousness, public Extraversion, public Agreeableness, public Neuroticism
{
private:
    bool LuuY;
public:
    Personality();
    Personality(int o, int c, int e, int a, int n);
    ~Personality();
    void Nhap();
    void Xuat();
    bool getCare() {
        return LuuY;
    }
};

Personality::~Personality() {
    Openness::~Openness();
    Coscientiousness::~Coscientiousness();
    Extraversion::~Extraversion();
    Agreeableness::~Agreeableness();
    Neuroticism::~Neuroticism();
}
Personality::Personality(int o, int c, int e, int a, int n)
    : Openness(o), Coscientiousness(c), Extraversion(e), Agreeableness(a), Neuroticism(n) {}

Personality::Personality() {
    Openness();
    Coscientiousness();
    Extraversion();
    Agreeableness();
    Neuroticism();
}
void Personality::Nhap() {
    Openness::Nhap();
    Coscientiousness::Nhap();
    Extraversion::Nhap();
    Agreeableness::Nhap();
    Neuroticism::Nhap();
    if (Coscientiousness::rate <= 30 || Neuroticism::rate >= 70 || Neuroticism::rate >= 70 && Extraversion::rate <= 30) {
        LuuY = true;
    } else {
        LuuY = false;
    }
}
void Personality::Xuat() {
    Openness::Xuat();
    Coscientiousness::Xuat();
    Extraversion::Xuat();
    Agreeableness::Xuat();
    Neuroticism::Xuat();
}

int main() {
    vector<Personality*> danhSachTinhCach;
    cout  << "Nhap so nguoi ban muon nhap: ";
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nNhap ket qua tinh cach nguoi thu " << i + 1 << ":" << endl;
        Personality* temp = new Personality();
        temp->Nhap();
        danhSachTinhCach.push_back(temp);
    }

    int x;
    cout << "Nhap so cua nguoi mang thong tin muon xuat: "; cin >> x;
    danhSachTinhCach[x]->Xuat();

    for (int i = 0; i < n; i++) {
        if (!danhSachTinhCach[i]->getCare()) {
            continue;
        }
        cout << "\nKet qua tinh cach nguoi can luu y co thu tu " << i + 1 << ":" << endl;
        danhSachTinhCach[i]->Xuat();
    }
    return 0;
}
