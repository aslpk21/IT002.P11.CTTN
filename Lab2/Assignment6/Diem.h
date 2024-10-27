#pragma once
class Diem{
    private:
      float iHoanh, iTung;
    public:
      Diem();
      Diem(float Hoanh, float Tung);
      Diem(const Diem &x);
      void Xuat();
      void TinhTien(float X, float Y);
};
