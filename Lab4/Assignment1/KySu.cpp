#include "KySu.h"

KySu::KySu() : NhanVien(){
    soGioLamThem = 0;
}

double KySu::TienThuong(){
    return soGioLamThem * 100000;
}

void KySu::Nhap(){
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> soGioLamThem;
}

void KySu::Xuat(){
    NhanVien::Xuat();
    cout << "Tien thuong: " << TienThuong() << " VND\n";
}