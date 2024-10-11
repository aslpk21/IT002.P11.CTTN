#include<iostream>

using namespace std;

// Cấu trúc dữ liệu Fraction biểu diễn một phân số với tử số (numerator) và mẫu số (denominator).
struct Fraction{
    int numerator, denomirator;
};

// Hàm printFraction in ra phân số dưới dạng tử số/mẫu số.
// Đầu vào: một phân số dưới dạng tham chiếu (Fraction &x).
// Đầu ra: phân số được in ra màn hình.
void printFraction(Fraction &x){
    cout << x.numerator << "/" << x.denomirator << "\n";
}

// Hàm getFracValue trả về giá trị thực (double) của một phân số.
// Đầu vào: một phân số (Fraction x).
// Đầu ra: giá trị thực của phân số.
double getFracValue(Fraction x){
    return (double)x.numerator / x.denomirator;
}

// Hàm findMax so sánh hai phân số và trả về phân số lớn hơn.
// Đầu vào: hai phân số (Fraction a, Fraction b).
// Đầu ra: phân số lớn hơn giữa a và b.
Fraction findMax(Fraction a, Fraction b){
    if(getFracValue(a) > getFracValue(b)) return a;
    return b;
}

int main(){
    Fraction firstOne;   // Phân số thứ nhất
    Fraction secondOne;  // Phân số thứ hai

    // Nhập phân số thứ nhất từ người dùng, đảm bảo mẫu số khác 0
    cout << "Enter first fraction's numerator: ";
    cin >> firstOne.numerator;
    do{
        cout << "Enter first fraction's denominator: ";
        cin >> firstOne.denomirator;
        if(firstOne.denomirator == 0)
           cout << "Invalid denominator! Denominator cannot be zero.\n";
    } while (firstOne.denomirator == 0);

    // Nhập phân số thứ hai từ người dùng, đảm bảo mẫu số khác 0
    cout << "Enter second fraction's numerator: ";
    cin >> secondOne.numerator;
    do{
        cout << "Enter second fraction's denominator: ";
        cin >> secondOne.denomirator;
        if(secondOne.denomirator == 0)
           cout << "Invalid denominator! Denominator cannot be zero.\n";
    } while (secondOne.denomirator == 0);

    // Tìm phân số lớn hơn giữa hai phân số
    Fraction result = findMax(firstOne, secondOne);
    
    // In ra phân số lớn nhất
    cout << "The largest Fraction is: ";
    printFraction(result);

    return 0;
}
 