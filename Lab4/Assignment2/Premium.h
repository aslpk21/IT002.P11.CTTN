#pragma once
#include"SOFITEL.h"

class Premium : public SOFITEL {
	private:
		double doanhThu, phiDichVu;
	public:
		Premium(int soDem = 0, double PhiDV = 0);
		double getDoanhThu();
		void Nhap() override;
		void Xuat() override;
};
