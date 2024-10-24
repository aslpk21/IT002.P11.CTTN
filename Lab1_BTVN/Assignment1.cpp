#include<bits/stdc++.h>

using namespace std;
#define numerator first 
#define denominator second

// Comparator so sánh 2 phân số từ bé đến lớn
// Đầu vào: hai phân số a và b dưới dạng cặp (tử số, mẫu số)
// Đầu ra: true nếu phân số a nhỏ hơn phân số b, ngược lại là false
bool cmp(pair<int, int> a, pair<int, int> b){
    return (double)a.numerator / a.denominator < (double)b.numerator / b.denominator;
}

// Hàm in phân số dưới dạng tử số/mẫu số
// Đầu vào: hai số nguyên a và b, tương ứng là tử số và mẫu số của phân số
// Đầu ra: in ra phân số theo định dạng a/b
void printFraction(int a, int b){
    cout << a << "/" << b << "\n";
}

int main(){
    int n; // Số lượng phân số
    
    // Nhập số lượng phân số từ người dùng
    do{
        cout << "Enter the number of fractions: ";
        cin >> n;
        // Kiểm tra số lượng phân số phải lớn hơn 0
        if(n <= 0) cout << "The number of fractions must be greater than 0!\n";
    } while (n <= 0);

    vector<pair<int, int>> arr(n);
    // Nhập giá trị cho các phân số trong danh sách
    for(int i = 0; i < n; i++){
        cout << "Enter the values for fraction " << i + 1 << ": \n";
        cout << "Enter numerator: ";
        cin >> arr[i].numerator; // Nhập tử số
        
        // Nhập mẫu số và kiểm tra không được bằng 0
        do{
            cout << "Enter denominator: ";
            cin >> arr[i].denominator;
            if(arr[i].denominator == 0) 
                cout << "Denominator must be non-zero.\n"; // Báo lỗi nếu mẫu số không hợp lệ
        } while(arr[i].denominator == 0);
    }

    // Sắp xếp các phân số theo thứ tự từ bé đến lớn
    sort(arr.begin(), arr.end(), cmp);
    
    // In ra phân số nhỏ nhất
    cout << "Smallest fraction: ";
    printFraction(arr[0].numerator, arr[0].denominator);
    
    // In ra phân số lớn nhất
    cout << "Largest fraction: ";
    printFraction(arr[n-1].numerator, arr[n-1].denominator);

    return 0;
}
