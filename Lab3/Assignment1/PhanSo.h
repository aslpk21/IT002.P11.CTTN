#pragma once
#include<iostream>
using namespace std;

class PhanSo{
    private:
        int iTu, iMau;
    public:
        PhanSo();
        PhanSo(int Tu, int Mau);
        int getMau();
        int getTu();
        PhanSo operator +(PhanSo);
        PhanSo operator -(PhanSo);
        PhanSo operator *(PhanSo);
        PhanSo operator /(PhanSo);
        bool operator ==(PhanSo);
        bool operator !=(PhanSo);
        bool operator >=(PhanSo);
        bool operator <=(PhanSo);
        bool operator >(PhanSo);
        bool operator <(PhanSo);
        friend istream& operator >> (istream &in, PhanSo &ps);
        friend ostream& operator << (ostream &out, PhanSo &ps);
};