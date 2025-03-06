#include <iostream>
#include <vector>
using namespace std;

int main() {
    int na, nb; cin>> na >> nb;
    vector<int> a(na);
    for (auto &num : a) {
        cin >> num;
    }
    vector<int> b(nb);
    for (auto &num : b) {
        cin >> num;
    }
    vector<int> c;
    int count =0 ;
    for (int i = 0; i < nb; i++) {
        if (a[0] == b[i]) {
            for (int j = 0; j < na; j++) {
                if (a[j] != b[j+i]) {
                    break;
                } if (j== na-1) {
                    count++;
                    c.push_back(i);
                }
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << c[i] << " ";
    }
    return 0;
}
