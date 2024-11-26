#pragma once
#include "GiaSuc.h"
class De : public GiaSuc
{
public:
	De(int soLuong = 0);
	int sinhCon() override;
	int choSua() override;
	string getLoai() override;
};