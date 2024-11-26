#include "Deluxe.h"

Deluxe::Deluxe(int soDem, double phiDV, double phiPV) : SOFITEL(soDem) {
	phiDichVu = phiDV;
	phiPhucVu = phiPV;
	doanhThu = 0;
}

double Deluxe::getDoanhThu() {
	doanhThu = soDem * 750000 + phiDichVu + phiPhucVu;
	return doanhThu;
}

void Deluxe::Nhap() {
	cout << "Nhap thong tin phong Deluxe: \n";
	SOFITEL::Nhap();
	cout << "Nhap phi dich vu: ";
	cin >> phiDichVu;
	cout << "Nhap phi phuc vu: ";
	cin >> phiPhucVu;
}

void Deluxe::Xuat() {
	cout << "Thong tin phong Deluxe: \n";
	cout << "So dem: " << soDem << "\n";
	cout << "Phi dich vu: " << fixed << setprecision(0) << phiDichVu << " VND\n";
	cout << "Phi phuc vu: " << fixed << setprecision(0) << phiPhucVu << " VND\n";
	cout << "Doanh thu: " << fixed << setprecision(0) << getDoanhThu() << " VND\n";
}
