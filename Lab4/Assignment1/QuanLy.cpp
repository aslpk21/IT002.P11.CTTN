#include "QuanLy.h"

QuanLy::QuanLy() : NhanVien() {
    tyLeThuong = 0;
}

double QuanLy::TienThuong() {
    return (tyLeThuong / 100) * LuongCoBan;
}

void QuanLy::Nhap() {
    cout << "Nhap thong tin quan ly:\n";
    NhanVien::Nhap();
    do {
        cout << "Nhap ty le thuong (0 - 100%): ";
        cin >> tyLeThuong;
        if (tyLeThuong < 0 || tyLeThuong > 100)
            cout << "Ty le thuong khong hop le. Nhap lai.\n";
    } while (tyLeThuong < 0 || tyLeThuong > 100);
    cout << "\n";
}

void QuanLy::Xuat() {
    cout << "\nThong tin quan ly: \n";
    NhanVien::Xuat();
    cout << "Tien thuong: " << fixed << setprecision(0) << TienThuong() << " VND\n";
}
