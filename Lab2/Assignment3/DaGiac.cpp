#include "DaGiac.h"
#include<cmath>
#define PI 3.14159265358979323846

void DaGiac::Nhap(){
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    Dinh = new Diem[n];

    for(int i=0 ;i<n; i++){
        int x, y;
        cout << "Nhap toa do dinh " << i + 1 << " (x, y): \n";
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

void DaGiac::Xuat() {
    cout << "\nToa do cac dinh cua da giac:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i + 1 << ": \n";
        Dinh[i].Xuat();
    }
}

void DaGiac::TinhTien() {
    int dx, dy;
    cout << "\nNhap gia tri tinh tien (dx, dy): ";
    cin >> dx >> dy;
    
    for (int i = 0; i < n; ++i) {
        Dinh[i].TinhTien(dx, dy);
    }
    cout << "Da giac sau khi tinh tien:\n";
    Xuat();
}

void DaGiac::PhongTo() {
    float scale;
    cout << "\nNhap he so phong to: ";
    cin >> scale;

    for (int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * scale);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * scale);
    }
    cout << "Da giac sau khi phong to:\n";
    Xuat();
}


void DaGiac::ThuNho() {
    float scale;
    cout << "\nNhap he so thu nho: ";
    cin >> scale;

    if (scale == 0) {
        cout << "He so thu nho phai khac 0!" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() / scale);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() / scale);
    }
    cout << "Da giac sau khi thu nho:\n";
    Xuat();
}

void DaGiac::Quay() {
    float alpha;
    cout << "\nNhap goc quay (do): ";
    cin >> alpha;

    alpha = alpha * PI / 180.0;

    for (int i = 0; i < n; ++i) {
        float x = Dinh[i].GetHoanhDo();
        float y = Dinh[i].GetTungDo();

        float newX = x * cos(alpha) - y * sin(alpha);
        float newY = x * sin(alpha) + y * cos(alpha);

        Dinh[i].SetHoanhDo(newX);
        Dinh[i].SetTungDo(newY);
    }
    cout << "Da giac sau khi quay:\n";
    Xuat();
}