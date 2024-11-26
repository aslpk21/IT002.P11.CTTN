#include "Premium.h"

Premium::Premium(int soDem, double phiDV) : SOFITEL(soDem), phiDichVu(phiDV) {
	doanhThu = 0;
}

double Premium::getDoanhThu() {
	doanhThu = soDem * 500000 + phiDichVu;
	return doanhThu;
}

void Premium::Nhap() {
	cout << "Nhap thong tin phong Premium: \n";
	SOFITEL::Nhap();
	cout << "Nhap phi dich vu: ";
	cin >> phiDichVu;
}

void Premium::Xuat() {
	cout << "Thong tin phong Premium: \n";
	cout << "So dem: " << soDem << "\n";
	cout << "Phi dich vu: " << fixed << setprecision(0) << phiDichVu << " VND\n";
	cout << "Doanh thu: " << fixed << setprecision(0) << getDoanhThu() << " VND\n";
}
