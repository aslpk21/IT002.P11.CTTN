#include "Bo.h"

Bo::Bo(int soLuong) : GiaSuc(soLuong) {
	tiengKeu = "Moo";
}

int Bo::sinhCon() {
	int tongSoCon = 0;
	for (int i = 0; i < soLuong; i++) {
		int soConMoiSinh = rand() % 2 + 1;
		tongSoCon += soConMoiSinh;
	}
	themSoLuong(tongSoCon);
	return tongSoCon;
}


int Bo::choSua() {
	int tongSua = 0;
	for (int i = 0; i < soLuong; i++) {
		tongSua += rand() % 21;
	}
	return tongSua;
}

string Bo::getLoai() {
	return "Bo";
}