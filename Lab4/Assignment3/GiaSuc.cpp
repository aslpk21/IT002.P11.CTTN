#include "GiaSuc.h"

GiaSuc::GiaSuc(int soCon, string tiengKeu) {
	soLuong = soCon;
	this->tiengKeu = tiengKeu;
}

GiaSuc::~GiaSuc(){}

void GiaSuc::phatTiengKeu() {
	for (int i = 0; i < soLuong; i++) {
		cout << tiengKeu << " ";
	}
	cout << endl;
}

void GiaSuc::themSoLuong(int SL) {
	soLuong += SL;
}

int GiaSuc::getSoLuong() {
	return soLuong;
}