#include "De.h"

De::De(int soLuong) : GiaSuc(soLuong) {
	tiengKeu = "Meh";
}

int De::sinhCon() {
	int tongSoCon = 0;
	for (int i = 0; i < soLuong; i++) {
		int soConMoiSinh = rand() % 3 + 1;
		tongSoCon += soConMoiSinh;
	}
	themSoLuong(tongSoCon);
	return tongSoCon;
}

int De::choSua() {
	int tongSua = 0;
	for (int i = 0; i < soLuong; i++) {
		tongSua += rand() % 11;
	}
	return tongSua;
}

string De::getLoai() {
	return "De";
}