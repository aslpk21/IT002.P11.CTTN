#include <iostream>
#include<iomanip>
#include "Diem.h"
using namespace std;

Diem::Diem(float Hoanh, float Tung){
    iHoanh = Hoanh;
    iTung = Tung;
}

void Diem::Xuat(){
    cout << "(" << fixed << setprecision(2) << iHoanh << ", " 
                << fixed << setprecision(2) << iTung << ")\n";
}

float Diem::GetHoanhDo(){
    return iHoanh;
}

float Diem::GetTungDo(){
    return iTung;
}