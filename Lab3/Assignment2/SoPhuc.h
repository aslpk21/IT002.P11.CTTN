#pragma once
#include<iostream>
using namespace std;

class SoPhuc{
    private:
        int dThuc, dAo;
    public:
        SoPhuc();
        SoPhuc(int thuc, int ao);
        SoPhuc operator +(SoPhuc);
        SoPhuc operator -(SoPhuc);
        SoPhuc operator *(SoPhuc);
        SoPhuc operator /(SoPhuc);
        bool operator ==(SoPhuc);
        bool operator !=(SoPhuc);
        friend istream& operator >>(istream &in, SoPhuc &sp);
        friend ostream& operator <<(ostream &out, SoPhuc &sp);
};