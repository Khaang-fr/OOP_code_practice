#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Openness
{
protected: 
    int rate;
    string Highmsg = "Người có điểm cao ở yếu tố này thường là người thích những ý tưởng mới, thích hiểu biết nhiều lĩnh vực nhưng đồng thời cũng thích tự do, không thích bị ràng buộc…";
    string Lowmsg = "Người có điểm thấp ở yếu tố này thường khá bảo thủ, khó tiếp nhận những ý tưởng mới, lạ. Họ thích sự ổn định, quen thuộc và thực tế.";
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
    cout << "O" << this->rate << "-";
}

class Coscientiousness
{
protected:
    int rate;
    string Highmsg = "Người có điểm cao ở yếu tố này thường là người chăm chỉ, có khả năng chịu áp lực tốt. Họ thường là người gắn bó,trung thành với tổ chức.";
    string Lowmsg = "Người có điểm thấp ở yếu tố này thường dễ bỏ cuộc, khả năng chịu áp lực, tuân thủ kỷ luật của tổ chức kém.";
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
    cout << "C" << this->rate << "-";
}

class Extraversion
{
protected:
    int rate;
    string Highmsg = "Người có điểm cao ở yếu tố này thường là người nhiệt tình, năng động, giao tiếp tốt, thích thể hiện bản thân.";
    string Lowmsg = "Người có điểm thấp ở yếu tố này thường ngại giao tiếp, không thích sự nổi bật, thích được làm việc độc lập.";
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
    cout << "E" << this->rate << "-";
}

class Agreeableness
{
protected:
    int rate;
    string Highmsg = "Người có điểm cao ở yếu tố này thường thân thiện, cởi mở, đồng cảm với mọi người nhưng nhiều khi 'thiếu chính kiến'.";
    string Lowmsg = "Người có điểm thấp thường đặt lợi ích của bản thân lên trên, ít đồng cảm, chia sẻ với đồng nghiệp, có tính cạnh tranh cao.";
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
    cout << "A" << this->rate << "-";
}

class Neuroticism
{
protected:
    int rate;
    string Highmsg = "Người có điểm cao ở yếu tố này thường có các cảm xúc tiêu cực như: lo lắng, bực bội, tự ti, yếu đuối và khả năng chịu áp lực kém.";
    string Lowmsg = "Người có điểm thấp ở yếu tố này thường kiểm soát được cảm xúc, ứng phó với căng thẳng tốt, ít bị bên ngoài ảnh hưởng đến tâm trạng của bản thân.";
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
    cout << "N" << this->rate;
}

class Personality : public Openness, public Coscientiousness, public Extraversion, public Agreeableness, public Neuroticism
{
public:
    Personality();
    Personality(int o, int c, int e, int a, int n);
    ~Personality();
    void Nhap();
    void Xuat();
};

Personality::Personality() {
    Openness::~Openness();
    Coscientiousness::~Coscientiousness();
    Extraversion::~Extraversion();
    Agreeableness::~Agreeableness();
    Neuroticism::~Neuroticism();
}
Personality::Personality(int o, int c, int e, int a, int n) {
    Openness(o);
    Coscientiousness(c);
    Extraversion(e);
    Agreeableness(a);
    Neuroticism(n);
}
Personality::~Personality() {
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
        Personality* temp;
        temp->Personality::Nhap();
        danhSachTinhCach.push_back(temp);
    }
}
