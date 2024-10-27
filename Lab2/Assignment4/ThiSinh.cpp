#include "ThiSinh.h"
#include<iostream>
#include<string>
#include<vector>

bool isValidDate(int ngay, int thang, int nam) {
    if (thang < 1 || thang > 12 || ngay < 1 || ngay > 31) 
        return false;

    if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay > 30)
        return false;

    bool isLeapYear = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    if (thang == 2) {
        if (isLeapYear && ngay > 29) return false;
        if (!isLeapYear && ngay > 28) return false;
    }
    
    return true;
}

bool isValidScore(float score){
    return score >= 0 && score <= 10;
}

void ThiSinh::Nhap(){
    cout << "Nhap ten thi sinh: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    cin >> MSSV;
    
    do {
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> iNgay >> iThang >> iNam;
        if (!isValidDate(iNgay, iThang, iNam))
            cout << "Ngay sinh khong hop le. Vui long nhap lai.\n";
    } while (!isValidDate(iNgay, iThang, iNam));

    do {
        cout << "Nhap diem Toan: ";
        cin >> fToan;
        cout << "Nhap diem Van: ";
        cin >> fVan;
        cout << "Nhap diem Anh: ";
        cin >> fAnh;
        if (!isValidScore(fVan) || !isValidScore(fToan) || !isValidScore(fAnh)) 
            cout << "Diem phai trong khoang [0, 10]. Vui long nhap lai.\n";
    } while (!isValidScore(fVan) || !isValidScore(fToan) || !isValidScore(fAnh));
}

void ThiSinh::Xuat(){
    cout << "\n--- Thong tin thi sinh ---\n";
    cout << "Ten: " << Ten << "\n";
    cout << "MSSV: " << MSSV << "\n";
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << "\n";
    cout << "Diem Toan: " << fToan << "\n";
    cout << "Diem Van: " << fVan << "\n";
    cout << "Diem Anh: " << fAnh << "\n";
}

float ThiSinh::Tong(){
    return (fToan + fVan + fAnh);
}