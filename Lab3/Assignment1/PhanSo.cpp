#include "PhanSo.h"

// Constructor mặc định khởi tạo tử số bằng 0 và mẫu số bằng 1
PhanSo::PhanSo() {
    iTu = 0;
    iMau = 1;
}

// Constructor với tham số
PhanSo::PhanSo(int Tu, int Mau) {
    iTu = Tu;
    iMau = Mau;
}

// Lấy mẫu số
int PhanSo::getMau() {
    return iMau;
}

// Lấy tử số
int PhanSo::getTu() {
    return iTu;
}

// Phương thức cộng hai phân số
// Input: một phân số khác (ps)
// Output: phân số mới là tổng của hai phân số
PhanSo PhanSo::operator +(PhanSo ps) {
    int tuMoi = iTu * ps.iMau + ps.iTu * iMau;
    int mauMoi = iMau * ps.iMau;
    return PhanSo(tuMoi, mauMoi);
}

// Phương thức trừ hai phân số
// Input: một phân số khác (ps)
// Output: phân số mới là hiệu của hai phân số
PhanSo PhanSo::operator -(PhanSo ps) {
    int tuMoi = iTu * ps.iMau - ps.iTu * iMau;
    int mauMoi = iMau * ps.iMau;
    return PhanSo(tuMoi, mauMoi);
}

// Phương thức nhân hai phân số
// Input: một phân số khác (ps)
// Output: phân số mới là tích của hai phân số
PhanSo PhanSo::operator *(PhanSo ps) {
    return PhanSo(iTu * ps.iTu, iMau * ps.iMau);
}

// Phương thức chia hai phân số
// Input: một phân số khác (ps)
// Output: phân số mới là thương của hai phân số
// Nếu tử số của phân số thứ hai (ps) là 0, trả về phân số 0/1 (không thể chia cho 0)
PhanSo PhanSo::operator /(PhanSo ps) {
    if (ps.iTu == 0) {
        return PhanSo(0, 1); // Không thể chia cho phân số có tử số = 0
    }
    return PhanSo(iTu * ps.iMau, iMau * ps.iTu); // Trả về phân số mới
}

// Phương thức so sánh hai phân số bằng nhau
// Input: một phân số khác (ps)
// Output: true nếu hai phân số bằng nhau, false nếu không
bool PhanSo::operator ==(PhanSo ps) {
    return (iTu * ps.iMau) == (ps.iTu * iMau);
}

// Phương thức so sánh hai phân số khác nhau
// Input: một phân số khác (ps)
// Output: true nếu hai phân số khác nhau, false nếu không
bool PhanSo::operator !=(PhanSo ps) {
    return (iTu * ps.iMau) != (ps.iTu * iMau);
}

// Phương thức so sánh hai phân số lớn hơn hoặc bằng nhau
// Input: một phân số khác (ps)
// Output: true nếu phân số hiện tại lớn hơn hoặc bằng phân số ps, false nếu không
bool PhanSo::operator >=(PhanSo ps) {
    return (iTu * ps.iMau) >= (ps.iTu * iMau);
}

// Phương thức so sánh hai phân số nhỏ hơn hoặc bằng nhau
// Input: một phân số khác (ps)
// Output: true nếu phân số hiện tại nhỏ hơn hoặc bằng phân số ps, false nếu không
bool PhanSo::operator <=(PhanSo ps) {
    return (iTu * ps.iMau) <= (ps.iTu * iMau);
}

// Phương thức so sánh hai phân số lớn hơn
// Input: một phân số khác (ps)
// Output: true nếu phân số hiện tại lớn hơn phân số ps, false nếu không
bool PhanSo::operator >(PhanSo ps) {
    return (iTu * ps.iMau) > (ps.iTu * iMau);
}

// Phương thức so sánh hai phân số nhỏ hơn
// Input: một phân số khác (ps)
// Output: true nếu phân số hiện tại nhỏ hơn phân số ps, false nếu không
bool PhanSo::operator <(PhanSo ps) {
    return (iTu * ps.iMau) < (ps.iTu * iMau);
}

// Phương thức nhập phân số từ bàn phím
// Input: phân số cần nhập (ps)
// Output: phân số đã được nhập từ người dùng
// Nếu mẫu số bằng 0, yêu cầu người dùng nhập lại mẫu cho đến khi hợp lệ
istream& operator >>(istream &in, PhanSo &ps) {
    in >> ps.iTu >> ps.iMau;
    while (ps.iMau == 0) {
        cout << "Mau khong the bang 0! Hay nhap lai mau.\n";
        in >> ps.iMau;
    }
    return in;
}

// Phương thức xuất phân số ra màn hình
// Input: phân số cần xuất (ps)
// Output: phân số được in ra dưới dạng "tu/mau"
ostream& operator <<(ostream &out, PhanSo &ps) {
    out << ps.iTu << "/" << ps.iMau << "\n";
    return out;
}
