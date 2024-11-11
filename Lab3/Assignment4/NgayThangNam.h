#pragma once
#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);
    int TinhNgay();
    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(NgayThangNam a);
    bool operator==(NgayThangNam a);
    bool operator!=(NgayThangNam a);
    bool operator>=(NgayThangNam a);
    bool operator<=(NgayThangNam a);
    bool operator>(NgayThangNam a);
    bool operator<(NgayThangNam a);
    NgayThangNam operator++();
    NgayThangNam operator++(int);
    NgayThangNam operator--();
    NgayThangNam operator--(int);
    friend istream& operator>>(istream& in, NgayThangNam& nt);
    friend ostream& operator<<(ostream& out, NgayThangNam& nt);
};
