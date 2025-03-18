#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

bool containsNumber(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

class HocSinh {
	private:
		string hoTen;
		float toan, van, anh;
		string hocLuc;
		float dtb;

	public:
		void nhap();
		void tinhDiemTrungBinh();
		void xepLoai();
		void dtbCaoNhat(HocSinh hs[], int n);
		void timKiemTheoTen(HocSinh hs[], int n);
		void toanThapNhat(HocSinh hs[], int n);
		void xuat();
};

void HocSinh::nhap() {
	do {
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		if (containsNumber(hoTen)) { //Nhập lại nếu có số trong họ tên
			cout << "Ho ten khong hop le. Vui long nhap lai.\n";
		}
	} while (containsNumber(hoTen));

    do {
        cout << "Nhap diem toan: ";
        if (cin >> toan &&đủ
    bool found = false;

    for (int i = 0; i < n; i++) {
        string lowerName = toLowerCase(hs[i].hoTen);
        if (lowerName.find(lowerTen) != string::npos) {
            cout << "Hoc sinh can tim la: ";
            hs[i].xuat();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh co ten chua '" << ten << "'" << endl;
    }
}

void HocSinh::toanThapNhat(HocSinh hs[], int n) {
	HocSinh min = hs[0];
	for (int i = 1; i < n; i++) {
		if (hs[i].toan < min.toan) {
			min = hs[i];
		}
	}
	cout << "Hoc sinh co diem toan thap nhat la: ";
	min.xuat();
}

int main() {
    int n; cin >> n;
    cin.ignore();
	HocSinh *hs;
    hs = new HocSinh[n];
	for (int i = 0; i < n; i++) {
		hs[i].nhap();
		hs[i].tinhDiemTrungBinh();
		hs[i].xepLoai();
	}
	for (int i = 0; i < n; i++) {
		hs[i].xuat();
	}
	hs[0].dtbCaoNhat(hs, n);
	hs[0].timKiemTheoTen(hs, n);
	hs[0].toanThapNhat(hs, n);
    delete[] hs;
	return 0;
}
