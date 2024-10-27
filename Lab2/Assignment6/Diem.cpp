#include <iostream>
#include<iomanip>
#include "Diem.h"
using namespace std;

Diem::Diem(){
    iHoanh = 0;
    iTung = 0;
}

Diem::Diem(float Hoanh, float Tung){
    iHoanh = Hoanh;
    iTung = Tung;
}

Diem::Diem(const Diem &x){
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

void Diem::Xuat(){
    cout << "(" << fixed << setprecision(2) << iHoanh << ", " 
                << fixed << setprecision(2) << iTung << ")\n";
}

void Diem::TinhTien(float deltaX, float deltaY) {
    iHoanh += deltaX;
    iTung += deltaY;
}