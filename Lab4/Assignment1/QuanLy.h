#pragma once
#include"NhanVien.h"

class QuanLy : public NhanVien{
    private:
        double tyLeThuong;
    public:
        QuanLy();
        double TienThuong() override;
        void Nhap() override;
        void Xuat() override;
};