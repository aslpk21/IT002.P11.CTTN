#include "ThiSinh.cpp"
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    vector<ThiSinh> dsThiSinh(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        dsThiSinh[i].Nhap();
    }

    cout << "\nThi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; i++) {
        if (dsThiSinh[i].Tong() > 15) {
            dsThiSinh[i].Xuat();
        }
    }

    ThiSinh max = dsThiSinh[0];
    for (int i = 1; i < n; i++) {
        if (dsThiSinh[i].Tong() > max.Tong()) {
            max = dsThiSinh[i];
        }
    }

    cout << "\nThi sinh co tong diem cao nhat:\n";
    max.Xuat();

    return 0;
}
