#include "TamGiac.cpp"
using namespace std;

int main(){
    TamGiac tmp;
    cout << "Nhap toa do cac diem tam giac:\n";
    tmp.Nhap();
    cout << "Tam giac hien tai: \n";
    tmp.Xuat();
    tmp.TinhTien();
    tmp.PhongTo();
    tmp.ThuNho();
    tmp.Quay();
    return 0;
}