#include "DaGiac.h"
#include<cmath>

void DaGiac::Nhap(){
    do{
        cout << "Nhap so dinh cua da giac: ";
        cin >> n;
        if(n <= 2) cout << "So dinh phai lon hon 2!\n";
    } while(n <= 2);
    
    Dinh = new Diem[n];

    cout << "Nhap toa do cua cac dinh da giac: \n";
    for(int i=0 ;i<n; i++){
        float x, y;
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

void DaGiac::Xuat() {
    cout << "\nToa do cac dinh cua da giac:\n";
    for (int i = 0; i < n; ++i) {
        Dinh[i].Xuat();
    }
}

float DaGiac::DienTich(){
    float area = 0;
    for (int i = 0; i < n - 1; i++) {
        area += Dinh[i].GetHoanhDo() * Dinh[i + 1].GetTungDo() - Dinh[i].GetTungDo() * Dinh[i + 1].GetHoanhDo();
    }

    area += Dinh[n - 1].GetHoanhDo() * Dinh[0].GetTungDo() 
          - Dinh[n - 1].GetTungDo() * Dinh[0].GetHoanhDo();

    return fabs(area) / 2.0;
}
