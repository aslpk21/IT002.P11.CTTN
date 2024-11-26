#include "Cuu.h"

Cuu::Cuu(int soLuong) : GiaSuc(soLuong) {
	tiengKeu = "Baa";
}

int Cuu::sinhCon() {
	int tongSoCon = 0;
	for (int i = 0; i < soLuong; i++) {
		int soConMoiSinh = rand() % 3 + 1;
		tongSoCon += soConMoiSinh;
	}
	themSoLuong(tongSoCon);
	return tongSoCon;
}

int Cuu::choSua() {
	int tongSua = 0;
	for (int i = 0; i < soLuong; i++) {
		tongSua += rand() % 6;
	}
	return tongSua;
}

string Cuu::getLoai() {
	return "Cuu";
}