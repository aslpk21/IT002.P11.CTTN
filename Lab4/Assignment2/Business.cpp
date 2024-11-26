#include "Business.h"

Business::Business(int soDem) : SOFITEL(soDem) {
	doanhThu = 0;
}

double Business::getDoanhThu() {
	doanhThu = soDem * 300000;
	return doanhThu;
}

void Business::Nhap() {
	cout << "Nhap thong tin phong Business: \n";
	SOFITEL::Nhap();
}

void Business::Xuat() {
	cout << "Thong tin phong Business: \n";
	cout << "So dem: " << soDem << "\n";
	cout << "Doanh thu: " << fixed << setprecision(0) << getDoanhThu() << " VND\n";
}
