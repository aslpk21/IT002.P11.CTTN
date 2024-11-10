#include "ThoiGian.h"
#include<iostream>

// Constructor mặc định, khởi tạo thời gian với giá trị 0 giờ, 0 phút, 0 giây.
ThoiGian::ThoiGian(){
    iGio = 0;
    iPhut = 0;
    iGiay = 0;
}

// Constructor với tham số, khởi tạo thời gian với giá trị giờ, phút và giây bằng tham số truyền vào
ThoiGian::ThoiGian(int Gio, int Phut, int Giay){
    iGio = Gio;
    iGiay = Giay;
    iPhut = Phut;
    TinhLaiGio(TinhGiay());
}

// Tính tổng số giây từ thời gian hiện tại.
// Output: Trả về tổng số giây.
int ThoiGian::TinhGiay(){
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Chuyển đổi một giá trị giây sang giờ, phút và giây.
// Input: Số giây cần chuyển đổi.
// Output: Cập nhật lại các thuộc tính iGio, iPhut, iGiay được chuyển đổi từ giây.
void ThoiGian::TinhLaiGio(int Giay) {
    // Giới hạn thời gian trong khoảng từ 0 đến 24 giờ
    Giay = ((Giay % (24 * 3600)) + (24 * 3600)) % (24 * 3600);

    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;
}

// Toán tử cộng một số giây vào thời gian hiện tại.
// Input: Số giây cộng thêm.
// Output: Trả về một đối tượng ThoiGian mới sau khi được cộng thêm giây.
ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

// Toán tử trừ một số giây từ thời gian hiện tại.
// Input: Số giây cần trừ đi.
// Output: Trả về một đối tượng ThoiGian mới sau khi trừ đi giây.
ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

// Toán tử cộng hai đối tượng ThoiGian.
// Input: a (đối tượng ThoiGian để cộng).
// Output: Trả về một đối tượng ThoiGian mới với tổng thời gian của hai đối tượng.
ThoiGian ThoiGian::operator+(ThoiGian a) {
    int totalSeconds = TinhGiay() + a.TinhGiay();
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

// Toán từ trừ hai đối tượng ThoiGian.
// Input: a (đối tượng ThoiGian để trừ).
// Output: Trả về một đối tượng ThoiGian mới với hiệu thời gian của hai đối tượng.
ThoiGian ThoiGian::operator-(ThoiGian a) {
    int totalSeconds = TinhGiay() - a.TinhGiay();
    ThoiGian result;
    result.TinhLaiGio(totalSeconds);
    return result;
}

// Tăng thời gian hiện tại lên 1 giây (toán tử tiền tố).
// Output: Trả về đối tượng ThoiGian sau khi tăng lên 1 giây.
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

// Tăng thời gian hiện tại lên 1 giây (toán tử hậu tố).
// Output: Trả về đối tượng ThoiGian trước khi tăng lên 1 giây.
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

// Giảm thời gian hiện tại đi 1 giây (toán tử tiền tố).
// Output: Trả về đối tượng ThoiGian sau khi giảm đi 1 giây.
ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

// Giảm thời gian hiện tại đi 1 giây (toán tử hậu tố).
// Output: Trả về đối tượng ThoiGian trước khi giảm đi 1 giây.
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

// Kiểm tra hai đối tượng ThoiGian có bằng nhau không.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu hai đối tượng có cùng số thời gian, ngược lại trả về false.
bool ThoiGian::operator==(ThoiGian a){
    return TinhGiay() == a.TinhGiay();
}

// Kiểm tra hai đối tượng ThoiGian có khác nhau không.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu hai đối tượng có số thời gian khác nhau, ngược lại trả về false.
bool ThoiGian::operator!=(ThoiGian a){
    return TinhGiay() != a.TinhGiay();
}

// Kiểm tra đối tượng ThoiGian hiện tại lớn hơn hoặc bằng đối tượng khác.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu thời gian hiện tại lớn hơn hoặc bằng a.
bool ThoiGian::operator>=(ThoiGian a){
    return TinhGiay() >= a.TinhGiay();
}

// Kiểm tra đối tượng ThoiGian hiện tại nhỏ hơn hoặc bằng đối tượng khác.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu thời gian hiện tại nhỏ hơn hoặc bằng a.
bool ThoiGian::operator<=(ThoiGian a){
    return TinhGiay() <= a.TinhGiay();
}

// Kiểm tra đối tượng ThoiGian hiện tại lớn hơn đối tượng khác.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu thời gian hiện tại lớn hơn a.
bool ThoiGian::operator>(ThoiGian a){
    return TinhGiay() > a.TinhGiay();
}

// Kiểm tra đối tượng ThoiGian hiện tại nhỏ hơn đối tượng khác.
// Input: a (đối tượng ThoiGian để so sánh).
// Output: Trả về true nếu thời gian hiện tại nhỏ hơn a.
bool ThoiGian::operator<(ThoiGian a){
    return TinhGiay() < a.TinhGiay();
}

// Toán tử nhập từ istream, nhận giá trị giờ, phút, giây từ người dùng.
// Input: in (đối tượng istream để nhập), tg (đối tượng ThoiGian để lưu giá trị).
// Output: Trả về đối tượng istream sau khi nhập xong.
istream& operator>>(istream &in, ThoiGian &tg) {
    in >> tg.iGio >> tg.iPhut >> tg.iGiay;
    return in;
}

// Toán tử xuất ra ostream, in ra giờ, phút, giây của đối tượng.
// Input: out (đối tượng ostream để xuất), tg (đối tượng ThoiGian chứa giá trị cần in).
// Output: Trả về đối tượng ostream sau khi xuất xong.
ostream& operator<<(ostream &out, const ThoiGian &tg) {
    out << tg.iGio << " gio " << tg.iPhut << " phut " << tg.iGiay << " giay";
    return out;
}
