#include "KySu.h"

KySu::KySu() : NhanVien() {
    soGioLamThem = 0;
}

double KySu::TienThuong() {
    return soGioLamThem * 100000;
}

void KySu::Nhap() {
    cout << "Nhap thong tin ky su: \n";
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> soGioLamThem;
}

void KySu::Xuat() {
    cout << "\nThong tin ky su: \n";
    NhanVien::Xuat();
    cout << "Tien thuong: " << fixed << setprecision(0) << TienThuong() << " VND\n";
}
