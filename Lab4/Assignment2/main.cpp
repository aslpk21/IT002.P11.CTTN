#include "Business.h"
#include "Premium.h"
#include "Deluxe.h"

int main() {
    Deluxe a(0, 0, 0);
    Deluxe b(0, 0, 0);
    Premium c(0, 0);
    Premium d(0, 0);
    Business e(0);

    cout << "Nhap thong tin cho phong Deluxe a:\n";
    a.Nhap();
    cout << "\nNhap thong tin cho phong Deluxe b:\n";
    b.Nhap();
    cout << "\nNhap thong tin cho phong Premium c:\n";
    c.Nhap();
    cout << "\nNhap thong tin cho phong Premium d:\n";
    d.Nhap();
    cout << "\nNhap thong tin cho phong Business e:\n";
    e.Nhap();

    double doanhThuDeluxe = a.getDoanhThu() + b.getDoanhThu();
    double doanhThuPremium = c.getDoanhThu() + d.getDoanhThu();
    double doanhThuBusiness = e.getDoanhThu();

    cout << "\nTong doanh thu theo tung loai phong:\n";
    cout << "Doanh thu Deluxe: " << fixed << setprecision(0) << doanhThuDeluxe << " VND\n";
    cout << "Doanh thu Premium: " << fixed << setprecision(0) << doanhThuPremium << " VND\n";
    cout << "Doanh thu Business: " << fixed << setprecision(0) <<  doanhThuBusiness << " VND\n";

    if (doanhThuDeluxe > doanhThuPremium && doanhThuDeluxe > doanhThuBusiness) {
        cout << "Loai phong co doanh thu cao nhat la: Deluxe\n";
    }
    else if (doanhThuPremium > doanhThuDeluxe && doanhThuPremium > doanhThuBusiness) {
        cout << "Loai phong co doanh thu cao nhat la: Premium\n";
    }
    else {
        cout << "Loai phong co doanh thu cao nhat la: Business\n";
    }

    return 0;
}
