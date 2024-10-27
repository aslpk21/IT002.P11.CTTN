#include "Diem.cpp"

int main() {
    cout << "Khoi tao diem voi constructor mac dinh: \n";
    Diem x;
    cout << "Toa do diem x: \n";
    x.Xuat();

    cout << "\nKhoi tao diem voi constructor khoi tao: \n";
    int a, b;
    cout << "Nhap vao toa do khoi tao: \n";
    cin >> a >> b;
    Diem y(a, b);
    cout << "Toa do diem y: \n";
    y.Xuat();

    // Sử dụng constructor sao chép
    Diem z(y);
    cout << "\nToa do diem z: \n";
    z.Xuat();

    cout << "\nNhap vao toa do tinh tien: \n";
    cin >> a >> b;
    y.TinhTien(a, b);
    cout << "Toa do diem y sau khi tinh tien: \n";
    y.Xuat();

    return 0;
}
