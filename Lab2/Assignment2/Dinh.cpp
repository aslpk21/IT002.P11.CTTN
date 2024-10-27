#include <iostream>
#include "Dinh.h"
using namespace std;

Dinh::Dinh(){
    iHoanh = 0;
    iTung = 0;
}

Dinh::Dinh(float Hoanh, float Tung){
    iHoanh = Hoanh;
    iTung = Tung;
}

Dinh::Dinh(const Dinh &x){
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

void Dinh::Xuat(){
    cout << "Hoanh do: " << iHoanh << "\n";
    cout << "Tung do: " << iTung << "\n";
}

float Dinh::GetTungDo() {
    return iTung;
}

float Dinh::GetHoanhDo() {
    return iHoanh;
}

void Dinh::SetTungDo(float Tung) {
    iTung = Tung;
}

void Dinh::SetHoanhDo(float Hoanh) {
    iHoanh = Hoanh;
}

void Dinh::TinhTien(float deltaX, float deltaY) {
    iHoanh += deltaX;
    iTung += deltaY;
}