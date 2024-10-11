#include<iostream>

using namespace std;

// Hàm gcd tính ước chung lớn nhất (GCD) của hai số nguyên a và b.
// Đầu vào: hai số nguyên a và b.
// Đầu ra: ước chung lớn nhất của a và b.
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// Cấu trúc dữ liệu Fraction biểu diễn một phân số với tử số (numerator) và mẫu số (denominator).
struct Fraction{
    int numerator, denomirator;

    // Hàm simplifyFrac đơn giản hóa phân số bằng cách chia tử số và mẫu số cho GCD của chúng.
    // Đồng thời đảm bảo mẫu số luôn dương.
    // Đầu vào: không có, hoạt động trên chính đối tượng phân số hiện tại.
    // Đầu ra: phân số được đơn giản hóa.
    void simplifyFrac(){
        int gcddd = gcd(abs(numerator), abs(denomirator));
        numerator /= gcddd;
        denomirator /= gcddd;
      
        // Nếu mẫu số âm, đổi dấu cả tử số và mẫu số để mẫu số luôn dương
        if(denomirator < 0){
            numerator = -numerator;
            denomirator = -denomirator;
        }
    }
};

// Hàm printFraction in ra phân số dưới dạng tử số/mẫu số.
// Đầu vào: một phân số dưới dạng tham chiếu (Fraction &x).
// Đầu ra: phân số được in ra màn hình.
void printFraction(Fraction &x){
    cout << x.numerator << "/" << x.denomirator << "\n";
}

// Toán tử + thực hiện phép cộng hai phân số.
// Đầu vào: hai phân số a và b.
// Đầu ra: phân số là kết quả của phép cộng (đã được tối giản).
Fraction operator + (const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denomirator + b.numerator * a.denomirator;
    result.denomirator = a.denomirator * b.denomirator;
    result.simplifyFrac(); 
    return result;
}

// Toán tử - thực hiện phép trừ hai phân số.
// Đầu vào: hai phân số a và b.
// Đầu ra: phân số là kết quả của phép trừ (đã được tối giản).
Fraction operator - (const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.denomirator - b.numerator * a.denomirator;
    result.denomirator = a.denomirator * b.denomirator;
    result.simplifyFrac(); 
    return result;
}

// Toán tử * thực hiện phép nhân hai phân số.
// Đầu vào: hai phân số a và b.
// Đầu ra: phân số là kết quả của phép nhân (đã được tối giản).
Fraction operator * (const Fraction& a, const Fraction& b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denomirator = a.denomirator * b.denomirator;
    result.simplifyFrac(); 
    return result;
}

// Toán tử / thực hiện phép chia hai phân số.
// Đầu vào: hai phân số a và b.
// Đầu ra: phân số là kết quả của phép chia (đã được tối giản).
// Nếu phân số b có tử số bằng 0, sẽ báo lỗi ngoại lệ (exception).
Fraction operator / (const Fraction& a, const Fraction& b) {
    if(b.numerator == 0) throw invalid_argument("Cannot divide by zero");
    Fraction result;
    result.numerator = a.numerator * b.denomirator;
    result.denomirator = a.denomirator * b.numerator;
    result.simplifyFrac();
    return result;
}

int main(){
    Fraction firstOne;   // Phân số thứ nhất
    Fraction secondOne;  // Phân số thứ hai

    // Nhập phân số thứ nhất từ người dùng
    cout << "Enter first fraction's numerator: ";
    cin >> firstOne.numerator;
    do{
        cout << "Enter first fraction's denominator: ";
        cin >> firstOne.denomirator;
        if(firstOne.denomirator == 0)
           cout << "Invalid denominator! Denominator cannot be zero.\n";
    } while (firstOne.denomirator == 0);

    // Nhập phân số thứ hai từ người dùng
    cout << "Enter second fraction's numerator: ";
    cin >> secondOne.numerator;
    do{
        cout << "Enter second fraction's denominator: ";
        cin >> secondOne.denomirator;
        if(secondOne.denomirator == 0)
           cout << "Invalid denominator! Denominator cannot be zero.\n";
    } while (secondOne.denomirator == 0);

    // Tính tổng, hiệu, tích và thương của hai phân số
    Fraction Add = firstOne + secondOne;
    Fraction Subtract = firstOne - secondOne;
    Fraction Mult = firstOne * secondOne;
    Fraction Div = firstOne / secondOne;

    // In kết quả của các phép cộng, trừ, nhân và chia hai phân số
    cout << "Sum: ";
    printFraction(Add);
    cout << "Difference: ";
    printFraction(Subtract);
    cout << "Product: ";
    printFraction(Mult);
    cout << "Quotient: ";
    printFraction(Div);

    return 0;
}
