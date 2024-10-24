#include<bits/stdc++.h>

using namespace std;
#define numerator first 
#define denominator second

// Comparator so sánh 2 phân số theo thứ tự tăng dần
// Đầu vào: hai phân số a và b dưới dạng cặp (tử số, mẫu số)
// Đầu ra: true nếu phân số a nhỏ hơn phân số b, ngược lại là false
bool cmp(pair<int, int> a, pair<int, int> b){
    // So sánh hai phân số bằng cách so sánh giá trị thực của chúng
    return (double)a.numerator / a.denominator < (double)b.numerator / b.denominator;
}

// Hàm in phân số
// Đầu vào: một phân số dưới dạng cặp (tử số, mẫu số)
// Đầu ra: in phân số dưới dạng tử/mẫu
void printFraction(pair<int,int> a){
    cout << a.numerator << "/" << a.denominator << "\n";
}

int main(){
    int n, k;
    // Nhập số lượng phân số
    do{
        cout << "Enter the number of fractions: ";
        cin >> n;
        if(n <= 0) cout << "The number of fractions must be greater than 0!\n";
    } while (n <= 0);

    // Nhập giá trị k
    cout << "Enter k: ";
    cin >> k;

    vector<pair<int, int>> arr(n);
    // Nhập từng phân số
    for(int i = 0; i < n; i++){
        do{
            cout << "Enter the values of fraction " << i + 1 << " (numerator and denominator): ";
            cin >> arr[i].numerator >> arr[i].denominator;
            if(arr[i].denominator == 0) cout << "Denominator must be non-zero! Re-enter fraction.\n";
        } while (arr[i].denominator == 0);  // Kiểm tra mẫu số phải khác 0
    }

    // Sắp xếp các phân số theo thứ tự tăng dần
    sort(arr.begin(), arr.end(), cmp);

    // Kiểm tra nếu k hợp lệ
    if(k > 0 && k <= n){
        // In ra phân số nhỏ thứ k
        cout << "The " << k << "th smallest fraction: ";
        printFraction(arr[k-1]);

        // In ra phân số lớn thứ k
        cout << "The " << k << "th largest fraction: ";
        printFraction(arr[n-k]);
    } else {
        // Thông báo nếu k không hợp lệ
        cout << "k is out of range!";
    }
    return 0;
}
