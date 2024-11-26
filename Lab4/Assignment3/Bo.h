#pragma once
#include "GiaSuc.h"
class Bo : public GiaSuc
{
	public:
		Bo(int soLuong = 0);
		int sinhCon() override;
		int choSua() override;
		string getLoai() override;
};