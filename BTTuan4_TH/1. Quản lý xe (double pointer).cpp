#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Vehicle {
private:
    string mSC;
    string hoTen;
    string soXe;
    double doanhThu;
    
public:
    Vehicle() {
        this->mSC="";
        this->hoTen="";
        this->soXe="";
        this->doanhThu=0.0;
    }
    void Nhap();
    void Xuat();
    double GetDoanhThu();
    void SetDoanhThu(double dt);
    ~Vehicle() {
        cout << "bye!" << endl;
    }
};

void Vehicle::Nhap() {
    cout << "Nhap ma so chuyen: "; getline(cin, this->mSC);
    cout << "Nhap Ho ten: "; getline(cin, this->hoTen);
    cout << "Nhap bien kiem soat: "; getline(cin, this->soXe);
    cout << "Nhap doanh thu: "; cin >> this->doanhThu;
    cin.ignore();
}
void Vehicle::Xuat() {
    cout << "Ma so chuyen: " << this->mSC << endl;
    cout << "Ho ten: " << this->hoTen << endl;
    cout << "Bien kiem soat: " << this->soXe << endl;
    cout << "Doanh thu: " << this->doanhThu << endl;
}

double Vehicle::GetDoanhThu() {
    return this->doanhThu;
}
void Vehicle::SetDoanhThu(double dt) {
    if (dt != 0)
    {
        this->doanhThu = dt;
    }
    else {
        cout << "Doanh thu phai > 0"<<endl;
    }
}

class InternalVehicle:public Vehicle {
private:
    string soTuyen;
    int soKM;
public:
    void Nhap();
    void Xuat();
};

void InternalVehicle::Nhap() { 
    Vehicle::Nhap();
    cout << "Nhap so tuyen:"; getline(cin, this->soTuyen);
    cout << "Nhap so km:"; cin >> this->soKM;
    cin.ignore();
}

void InternalVehicle::Xuat() {
    Vehicle::Xuat();
    cout << "So tuyen: " << this->soTuyen << endl;
    cout << "So km: " << this->soKM << endl;
}

class ExternalVehicle: public Vehicle {
private:
    string noiDen;
    int soNgayDi;
public:
    void Nhap();
    void Xuat();

};

void ExternalVehicle::Nhap() {
    Vehicle::Nhap();
    cout << "Nhap noi den: "; getline(cin, this->noiDen);
    cout << "Nhap so ngay: "; cin >> this->soNgayDi;
    cin.ignore();
}
void ExternalVehicle::Xuat() {
    Vehicle::Xuat();
    cout << "Noi den: " << this->noiDen << endl;
    cout << "So ngay di: " << this->soNgayDi << endl;
}

class QuanLy {
private:
    Vehicle **V;
    int loaiXe;
    int k, h;
    int n;
public:
    QuanLy() {
        this->k = 0;
        this->h = 0;
        this->n = 0;
        this->V = new Vehicle*[20];
    }
    ~QuanLy() {
        for (int i = 0; i < n; i++) {
            delete V[i];
        }
        delete[] V;
    }
    double TongDoanhThuXeNoiThanh(InternalVehicle *p[], int n) {
        double tong = 0;
        for (int i = 0; i < n; i++) {
            tong += p[i]->GetDoanhThu();
        }
        return tong;
    }
    double TongDoanhThuXeNgoaiThanh(ExternalVehicle *p[], int n) {
        double tong = 0;
        for (int i = 0; i < n; i++) {
            tong += p[i]->GetDoanhThu();
        }
        return tong;
    }

    void XuatDanhSachNoiThanh(InternalVehicle *in[], int h) {
        cout << "Danh sach xe noi thanh:" << endl;
        for (int i = 0; i < h; i++) {
            cout << "Chuyen xe thu " << i + 1 << ":" << endl;
            in[i]->Xuat();
            cout << "------------------------" << endl;
        }
    }

    void NhapGopHaiDanhSach(Vehicle **v, int &n) {
        do {
            cout << "Nhap so chuyen xe: "; cin >> n;
        } while (n < 1 || n > 9);
        for (int i = 0; i < n; i++) {
            cout << "Bac nhap loai xe nao? 1: Xe noi thanh, 2: Xe ngoai thanh: "; cin >> loaiXe;
            cin.ignore();
            if (loaiXe == 1) {
                v[i] = new InternalVehicle();
            } else if (loaiXe == 2) {
                v[i] = new ExternalVehicle();
            } else {
                cout << "Khong co loai xe nay!" << endl;
                i--;
                continue;
            }
            v[i]->Nhap();
        }
    }

    void XuatDanhSachNgoaiThanh(ExternalVehicle *ex[], int k) {
        cout << "Danh sach xe ngoai thanh:" << endl;
        for (int i = 0; i < k; i++) {
            cout << "Chuyen xe thu " << i + 1 << ":" << endl;
            ex[i]->Xuat();
            cout << "------------------------" << endl;
        }
    }

    void Menu() {
        do {
            cout << "1. Nhap danh sach xe" << endl;
            cout << "2. Xuat danh sach xe noi thanh" << endl;
            cout << "3. Xuat danh sach xe ngoai thanh" << endl;
            cout << "4. Tinh tong doanh thu xe noi thanh" << endl;
            cout << "5. Tinh tong doanh thu xe ngoai thanh" << endl;
            cout << "6. Tinh tong doanh thu ca hai loai xe" << endl;
            cout << "7. Thoat" << endl;
            cout << "Moi ban lua chon: "; cin >> n;
            cin.ignore();

            switch (n) {
            case 1: 
                NhapGopHaiDanhSach(V, n); 
                break;
            case 2: 
                XuatDanhSachNoiThanh(reinterpret_cast<InternalVehicle**>(V), h); 
                break;
            case 3: 
                XuatDanhSachNgoaiThanh(reinterpret_cast<ExternalVehicle**>(V), k); 
                break;
            case 4: {
                double dtNoiThanh = TongDoanhThuXeNoiThanh(reinterpret_cast<InternalVehicle**>(V), h);
                cout << "Tong doanh thu xe noi thanh: " << dtNoiThanh << endl;
                }
                break;
            case 5: {
                double dtNgoaiThanh = TongDoanhThuXeNgoaiThanh(reinterpret_cast<ExternalVehicle**>(V), k);
                cout << "Tong doanh thu xe ngoai thanh: " << dtNgoaiThanh << endl;
                }
                break;
            case 6: {
                double dtNoiThanh = TongDoanhThuXeNoiThanh(reinterpret_cast<InternalVehicle**>(V), h);
                double dtNgoaiThanh = TongDoanhThuXeNgoaiThanh(reinterpret_cast<ExternalVehicle**>(V), k);
                cout << "Tong doanh thu ca hai loai xe: " << dtNoiThanh + dtNgoaiThanh << endl;
                }
                break;
            case 7: 
                cout << "Thoat chuong trinh." << endl;
                break;
            default: 
                cout << "Vui long nhap so tu 1 den 7." << endl;
                break;
            }
        } while (n != 7);
    }
};

int main()
{
    QuanLy q;
    q.Menu();
   
    return 0;

}
