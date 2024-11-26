#include "QuanLy.h"

QuanLy::QuanLy() : NhanVien(){
    tyLeThuong = 0;
}

double QuanLy::TienThuong(){
    return (tyLeThuong / 100) * LuongCoBan;
}

void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap ty le thuong (0 - 100%): ";
    cin >> tyLeThuong;
}

void QuanLy::Xuat(){
    NhanVien::Xuat();
    cout << "Tien thuong: " << TienThuong() << "\n";
}