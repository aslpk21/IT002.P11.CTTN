#include<iostream>

using namespace std;

// Hàm gcd tính ước chung lớn nhất (GCD) của hai số nguyên a và b.
// Đầu vào: hai số nguyên a và b.
// Đầu ra: ước chung lớn nhất của a và b.
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// Cấu trúc dữ liệu Fraction dùng để biểu diễn một phân số với tử số (numerator) và mẫu số (denominator).
struct Fraction{
    int numerator, denomirator;
};

// Hàm simplifyFrac đơn giản hóa phân số bằng cách chia cả tử số và mẫu số cho GCD của chúng.
// Đồng thời đảm bảo mẫu số luôn dương.
// Đầu vào: một phân số dưới dạng tham chiếu (Fraction &tmp).
// Đầu ra: phân số được đơn giản hóa và cập nhật lại tử và mẫu.
void simplifyFrac(Fraction &tmp){
    // Tìm ước chung lớn nhất giữa tử số và mẫu số
    int gcddd = gcd(abs(tmp.numerator), abs(tmp.denomirator));
    
    // Chia tử số và mẫu số cho GCD để đơn giản hóa phân số
    tmp.numerator /= gcddd;
    tmp.denomirator /= gcddd;

    // Nếu mẫu số âm, đổi dấu cả tử và mẫu để mẫu số dương
    if(tmp.denomirator < 0){
        tmp.numerator = -tmp.numerator;
        tmp.denomirator = -tmp.denomirator;
    }
}

// Hàm printFraction in ra phân số dưới dạng tử số/mẫu số.
// Đầu vào: một phân số dưới dạng tham chiếu (Fraction &x).
// Đầu ra: phân số được in ra màn hình.
void printFraction(Fraction &x){
    cout << x.numerator << "/" << x.denomirator << "\n";
}

int main(){
    Fraction x;
    
    // Nhập tử số của phân số từ người dùng
    cout << "Enter the fraction's numerator: ";
    cin >> x.numerator;

    // Nhập mẫu số, đảm bảo mẫu số khác 0
    do{
        cout << "Enter the fraction's denomirator: ";
        cin >> x.denomirator;
        if(x.denomirator == 0)
           cout << "Invalid denominator! Denominator cannot be zero.\n";
    } while(x.denomirator == 0);
    
    // Đơn giản hóa phân số và in ra kết quả
    simplifyFrac(x);
    printFraction(x);

    return 0;
}
