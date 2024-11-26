#pragma once
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;

class GiaSuc
{
	protected:
		int soLuong;
		string tiengKeu;
	public:
		GiaSuc(int soLuong = 0, string tiengKeu = "");
		virtual int sinhCon() = 0;
		virtual int choSua() = 0;
		void phatTiengKeu();
		void themSoLuong(int SL = 0);
		int getSoLuong();
		virtual string getLoai() = 0;
		virtual ~GiaSuc();
};