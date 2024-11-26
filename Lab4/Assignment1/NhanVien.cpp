#include"NhanVien.h"

NhanVien::NhanVien(){
    MaSo = "";
    Ten = "";
    LuongCoBan = 0;
}

void NhanVien::Nhap(){
    cout << "Nhap ma so nhan vien: ";
    cin >> MaSo;
    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "Nhap luong co ban cua nhan vien: ";
    cin >> LuongCoBan;
}

void NhanVien::Xuat(){
    cout << "Ma so: " << MaSo << "\n"
         << "Ho ten: " << Ten << "\n"
         << "Luong co ban: " << fixed << setprecision(0) << LuongCoBan << " VND\n";
}
