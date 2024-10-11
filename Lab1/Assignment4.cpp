#include <iostream>
#include <cmath>

using namespace std;
#define ll long long 

// Định nghĩa giá trị của số Pi 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Hàm factorial tính giai thừa của một số nguyên n.
// Đầu vào: số nguyên n.
// Đầu ra: giá trị giai thừa của n (n!).
ll factorial(int n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(){
    double degree;  // Biến để lưu giá trị góc đầu vào (đơn vị độ)
    
    // Nhập giá trị góc từ người dùng (đơn vị độ)
    cout << "Enter x (in degree): "; 
    cin >> degree;

    // Chuyển đổi giá trị góc từ đơn vị độ sang radian
    double x = degree * M_PI / 180;

    // Đặt độ chính xác cần đạt của kết quả
    float accuracy = 0.00001;

    // Khởi tạo giá trị để tính chuỗi Taylor cho sin(x)
    int i = 1;
    double term = x; // Giá trị đầu tiên trong chuỗi là x
    double result = x; // Khởi tạo giá trị sin(x) bằng giá trị đầu tiên

    // Tính sin(x) bằng chuỗi Taylor cho đến khi điều kiện độ chính xác được thỏa mãn
    while(fabs(term) >= accuracy){
        // Tính toán từng phần tử của chuỗi Taylor và cộng vào kết quả của Sin(x)
        term = pow(-1, i) * pow(x, 2*i + 1) / factorial(2*i + 1);
        result += term;
        i++;
    }

    // In ra kết quả tính được của sin(x)
    cout << "The value of Sin(" << degree << ") is: " << result << '\n';
    
    return 0;
}
