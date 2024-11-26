#pragma once
#include "GiaSuc.h"
class Cuu : public GiaSuc
{
public:
	Cuu(int soLuong = 0);
	int sinhCon() override;
	int choSua() override;
	string getLoai() override;
};