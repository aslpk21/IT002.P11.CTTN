#pragma once
class Dinh{
    private:
      float iHoanh, iTung;
    public:
      Dinh();
      Dinh(float Hoanh, float Tung);
      Dinh(const Dinh &x);
      void Xuat();
      float GetTungDo();
      float GetHoanhDo();
      void SetTungDo(float Tung);
      void SetHoanhDo(float Hoanh);
      void TinhTien(float X, float Y);
};