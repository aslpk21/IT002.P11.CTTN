#include "TamGiac.cpp"

int main(){
    float x1, x2, x3, y1, y2, y3;
    float alpha, distance;

    cout << "Nhap toa do 3 diem A, B, C cua tam giac (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << "Nhap huong tinh tien (don vi: do): ";
    cin >> alpha;

    cout << "Nhap do dai tinh tien: ";
    cin >> distance;

    TamGiac TG(x1, y1, x2, y2, x3, y3);

    TG.TinhTien(alpha, distance);
    cout << "Toa do cua tam giac sau khi tinh tien: \n";
    TG.Xuat();

    return 0;
}
