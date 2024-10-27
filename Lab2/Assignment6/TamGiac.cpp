#include<bits/stdc++.h>
#include "TamGiac.h"
#define PI 3.14159265358979323846

TamGiac::TamGiac(float x1, float y1, float x2, float y2, float x3, float y3){
    A = Diem(x1, y1);
    B = Diem(x2, y2);
    C = Diem(x3, y3);
}

void TamGiac::Xuat(){
    cout << "Toa do Dinh A cua tam giac: ";
    A.Xuat();
    cout << "Toa do Dinh B cua tam giac: ";
    B.Xuat();
    cout << "Toa do Dinh C cua tam giac: ";
    C.Xuat();
}

void TamGiac::TinhTien(float angle, float distance){
    
    float radian = angle * PI / 180.0;

    float dx = cos(radian) * distance;
    float dy = sin(radian) * distance;

    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

