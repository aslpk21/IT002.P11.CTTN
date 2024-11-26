#include "SOFITEL.h"

SOFITEL::SOFITEL(int soDem) {
	this->soDem = soDem;
}

void SOFITEL::Nhap() {
	cout << "Nhap so dem: ";
	cin >> soDem;
}
