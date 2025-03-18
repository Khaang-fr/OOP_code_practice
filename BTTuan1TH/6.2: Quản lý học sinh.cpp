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
		if (containsNumber(hoTen)) {
			cout << "Ho ten khong hop le. Vui long nhap lai.\n";
		}
	} while (containsNumber(hoTen));

    do {
        cout << "Nhap diem toan: ";
        if (cin >> toan && toan >= 0 && toan <= 10) {
            break;
        }
        cout << "Diem toan khong hop le. Vui long nhap lai.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    } while (true);

	do {
        cout << "Nhap diem van: ";
        if (cin >> van && van >= 0 && van <= 10) {
            break;
        }
        cout << "Diem van khong hop le. Vui long nhap lai.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    } while (true);

    do {
        cout << "Nhap diem anh: ";
        if (cin >> anh && anh >= 0 && anh <= 10) {
            break;
        }
        cout << "Diem anh khong hop le. Vui long nhap lai.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    } while (true);

	cin.ignore();
}

void HocSinh::tinhDiemTrungBinh() {
	dtb = (2*toan + van + anh) / 4;
}

void HocSinh::xepLoai() {
	if (dtb >= 9) {hocLuc = "Xuat sac";}
	else if (dtb >= 8) {hocLuc = "Gioi";}
	else if (dtb >= 6.5) {hocLuc = "Kha";}
	else if (dtb >= 5) {hocLuc = "Trung binh";}
	else {hocLuc = "Yeu";}
}

void HocSinh::xuat() {
	cout << "Ho ten: " << hoTen << " - ";
	cout << "Toan: " << toan << " - ";
	cout << "Van: " << van << " - ";
	cout << "Anh: " << anh << " - ";
	cout << "Diem trung binh: " << dtb << " - ";
	cout << "Hoc luc: " << hocLuc << endl;
}

void HocSinh::dtbCaoNhat(HocSinh hs[], int n) {
	HocSinh max = hs[0];
	for (int i = 1; i < n; i++) {
		if (hs[i].dtb > max.dtb) {
			max = hs[i];
		}
	}
	cout << "Hoc sinh co diem trung binh cao nhat la: " ;
	max.xuat();
}

void HocSinh::timKiemTheoTen(HocSinh hs[], int n) {
    string ten;
    cout << "Nhap ten hoc sinh can tim: ";
    getline(cin, ten);
    
    string lowerTen = toLowerCase(ten); 
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
    if (n==0) {
        return 0;
    }
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
	hs[0].toanThapNhat(hs, n);
    hs[0].timKiemTheoTen(hs, n);
    delete[] hs;
	return 0;
}
