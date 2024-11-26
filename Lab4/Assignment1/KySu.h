#pragma once
#include "NhanVien.h"

class KySu : public NhanVien{
    private:
        int soGioLamThem;
    public:
        KySu();
        double TienThuong() override;
        void Nhap() override;
        void Xuat() override;
};