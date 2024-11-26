#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class SOFITEL {
	protected:
		int soDem;
	public:
		SOFITEL(int soDem = 0);
		virtual void Nhap()= 0;
		virtual void Xuat() = 0;
};
