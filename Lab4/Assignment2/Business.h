#pragma once
#include "SOFITEL.h"

class Business : public SOFITEL {
	private:
		double doanhThu;
	public:
		Business(int soDem = 0);
		double getDoanhThu();
		void Nhap() override;
		void Xuat() override;
};
