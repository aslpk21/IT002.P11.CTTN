#pragma once
#include<iostream>
#include<string>
using namespace std;

class NhanVien{
    protected:
        string MaSo, Ten;
        double LuongCoBan;
    public:
        NhanVien();
        virtual ~NhanVien() = default;
        virtual double TienThuong() = 0;
        virtual void Nhap();
        virtual void Xuat();
};