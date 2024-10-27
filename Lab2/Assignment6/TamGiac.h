#pragma once
#include "Diem.cpp"
class TamGiac{
    private:
      Diem A, B, C;
    public:
      TamGiac(float x1, float y1, float x2, float y2, float x3, float y3);
      void Xuat();
      void TinhTien(float alpha, float distance);
};