#include "SoPhuc.h"

// Constructor mặc định, khởi tạo phần thực và phần ảo là 0
SoPhuc::SoPhuc() {
    dThuc = 0;
    dAo = 0;
}

// Constructor với tham số
SoPhuc::SoPhuc(int thuc, int ao) {
    dThuc = thuc;
    dAo = ao;
}

// Phương thức cộng hai số phức
// Input: số phức thứ hai (sp)
// Output: số phức mới là tổng của hai số phức
SoPhuc SoPhuc::operator+(SoPhuc sp) {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo); // Cộng phần thực với phần thực, phần ảo với phần ảo
}

// Phương thức trừ hai số phức
// Input: số phức thứ hai (sp)
// Output: số phức mới là hiệu của hai số phức
SoPhuc SoPhuc::operator-(SoPhuc sp) {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo); // Trừ phần thực với phần thực, phần ảo với phần ảo
}

// Phương thức nhân hai số phức
// Input: số phức thứ hai (sp)
// Output: số phức mới là tích của hai số phức
SoPhuc SoPhuc::operator*(SoPhuc sp) {
    return SoPhuc(
            (dThuc * sp.dThuc) - (dAo * sp.dAo), // Tính phần thực của tích
            (dThuc * sp.dAo) + (dAo * sp.dThuc)  // Tính phần ảo của tích
    );
}

// Phương thức chia hai số phức
// Input: số phức thứ hai (sp)
// Output: số phức mới là thương của hai số phức
// Nếu mẫu số mới bằng 0, in ra thông báo không thể chia và trả về số phức 0
SoPhuc SoPhuc::operator/(SoPhuc sp) {
    // Tính mẫu số của phần thực và phần ảo của thương
    double iMau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    // Xử lí trường hợp mẫu số bằng 0
    if (iMau == 0) {
        cout << "Khong the chia cho 0!" << "\n"; 
        exit(1); // Báo lỗi và thoát chương trình
    }
    // Tính phần thực và phần ảo của thương
    return SoPhuc(
        ((dThuc * sp.dThuc) + (dAo * sp.dAo)) / iMau,   // Phần thực của thương
        ((dAo * sp.dThuc) - (dThuc * sp.dAo)) / iMau    // Phần ảo của thương
    );
}

// Phương thức so sánh hai số phức bằng nhau
// Input: số phức thứ hai (sp)
// Output: true nếu hai số phức bằng nhau, false nếu không
bool SoPhuc::operator==(SoPhuc sp) {
    return (dThuc == sp.dThuc) && (dAo == sp.dAo); // So sánh cả phần thực và phần ảo
}

// Phương thức so sánh hai số phức khác nhau
// Input: số phức thứ hai (sp)
// Output: true nếu hai số phức khác nhau, false nếu không
bool SoPhuc::operator!=(SoPhuc sp) {
    return !(*this == sp); // Dùng kết quả phủ định của operator == để kiểm tra
}

// Phương thức nhập một số phức từ người dùng
// Input: số phức cần nhập (sp)
istream& operator>>(istream& in, SoPhuc &sp) {
    in >> sp.dThuc >> sp.dAo; // Nhập phần thực và phần ảo
    return in;
}

// Phương thức xuất một số phức ra màn hình
// Input: số phức cần xuất (sp)
// Output: in ra màn hình dưới dạng "a +/- bi"
ostream& operator<<(ostream& out, SoPhuc &sp) {
    if (sp.dAo < 0) out << sp.dThuc << "-" << -sp.dAo << "i";  // Nếu phần ảo là âm
    else if (sp.dAo > 0) out << sp.dThuc << "+" << sp.dAo << "i"; // Nếu phần ảo là dương
    else out << sp.dThuc; // Nếu phần ảo bằng 0 thì chỉ in ra phần thực
    return out;
}
