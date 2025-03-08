#include <iostream>
#include <string>

using namespace std;

int main() {
  string hoTen;
  cout << "Nhap ho ten: " ;
  cin.ignore();
  getline(cin, hoTen);
  cout << endl;
  float toan, van;
  cin >> toan >> van;
  float dtb = (toan + van)/2;
  cout << "Diem trung binh la: " << dtb << endl;
  return 0;
}
