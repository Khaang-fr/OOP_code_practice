#include <iostream>
#include <vector>
using namespace std;

int main() {
    int na, nb; 
    cin >> na >> nb;
    
    if (na == 0 || nb == 0 || na > nb) { //Loại trường hợp mảng rỗng
        cout << "0" << endl;
        return 0;
    }

    vector<int> a(na);
    for (auto &num : a) {
        cin >> num;
    }

    vector<int> b(nb);
    for (auto &num : b) {
        cin >> num;
    }

    vector<int> c;
    int count = 0;

    for (int i = 0; i <= nb - na; i++) {
        if (a[0] == b[i]) {    //Tìm phần tử đầu của mảng a trên mảng b
            bool match = true; 
            for (int j = 0; j < na; j++) {
                if (a[j] != b[j + i]) {  //Kiểm tra các phần tử tiếp theo có giống mảng a không 
                    match = false;
                    break;
                }
            }
            if (match) {
                count++; 
                c.push_back(i);
            }
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << c[i] << (i == count - 1 ? "\n" : " ");
    }
    return 0;
}
