#include<bits/stdc++.h>
#include "TamGiac.h"
#define PI 3.14159265358979323846

void TamGiac::Nhap() {
    int x, y;
    cout << "Nhap Dinh A(x, y): ";
    cin >> x >> y;
    A = Dinh(x, y);

    cout << "Nhap Dinh B(x, y): ";
    cin >> x >> y;
    B = Dinh(x, y);

    cout << "Nhap Dinh C(x, y): ";
    cin >> x >> y;
    C = Dinh(x, y);
}

void TamGiac::Xuat(){
    cout << "Toa do Dinh A cua tam giac: \n";
    A.Xuat();
    cout << "Toa do Dinh B cua tam giac: \n";
    B.Xuat();
    cout << "Toa do Dinh C cua tam giac: \n";
    C.Xuat();
}

void TamGiac::TinhTien(){
    int x, y;
    cout << "\nNhap gia tri tinh tien (dx, dy): ";
    cin >> x >> y;
    A.TinhTien(x, y);
    B.TinhTien(x, y);
    C.TinhTien(x, y);
    cout << "Tam giac sau khi tinh tien:\n";
    Xuat();
}

void TamGiac::PhongTo(){
    float scale;
    cout << "\nNhap he so phong to: ";
    cin >> scale;
    A.SetHoanhDo(A.GetHoanhDo() * scale);
    A.SetTungDo(A.GetTungDo() * scale);
    B.SetHoanhDo(B.GetHoanhDo() * scale);
    B.SetTungDo(B.GetTungDo() * scale);
    C.SetHoanhDo(C.GetHoanhDo() * scale);
    C.SetTungDo(C.GetTungDo() * scale);
    cout << "Tam giac sau khi phong to: \n";
    Xuat();
}

void TamGiac::ThuNho(){
    float scale;
    cout << "\nNhap he so thu nho: ";
    cin >> scale;
    if (scale == 0) {
        cout << "He so thu nho phai khac 0!" << "\n";
        return;
    }
    A.SetHoanhDo(A.GetHoanhDo() / scale);
    A.SetTungDo(A.GetTungDo() / scale);
    B.SetHoanhDo(B.GetHoanhDo() / scale);
    B.SetTungDo(B.GetTungDo() / scale);
    C.SetHoanhDo(C.GetHoanhDo() / scale);
    C.SetTungDo(C.GetTungDo() / scale);
    cout << "Tam giac sau khi thu nho: \n";
    Xuat();
}

void TamGiac::Quay(){
    float alpha;
    cout << "\nNhap goc quay (do): ";
    cin >> alpha;
    alpha = alpha * PI / 180.0;

    float xA = A.GetHoanhDo() * cos(alpha) - A.GetTungDo() * sin(alpha);
    float yA = A.GetHoanhDo() * sin(alpha) + A.GetTungDo() * cos(alpha);
    A.SetHoanhDo(xA);
    A.SetTungDo(yA);

    float xB = B.GetHoanhDo() * cos(alpha) - B.GetTungDo() * sin(alpha);
    float yB = B.GetHoanhDo() * sin(alpha) + B.GetTungDo() * cos(alpha);
    B.SetHoanhDo(xB);
    B.SetTungDo(yB);

    float xC = C.GetHoanhDo() * cos(alpha) - C.GetTungDo() * sin(alpha);
    float yC = C.GetHoanhDo() * sin(alpha) + C.GetTungDo() * cos(alpha);
    C.SetHoanhDo(xC);
    C.SetTungDo(yC);

    cout << "Tam giac sau khi quay: \n";
    Xuat();
}