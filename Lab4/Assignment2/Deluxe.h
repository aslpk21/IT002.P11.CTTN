#pragma once
#include "SOFITEL.h"

class Deluxe : public SOFITEL {
	private:
		double doanhThu, phiDichVu, phiPhucVu;
	public:
		Deluxe(int soDem = 0, double phiDV = 0, double phiPV = 0);
		double getDoanhThu();
		void Nhap() override;
		void Xuat() override;
};
