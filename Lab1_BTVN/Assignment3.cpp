#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define numerator first 
#define denominator second

// Hàm kiểm tra hai phân số có bằng nhau hay không
// Đầu vào: hai phân số a và b dưới dạng cặp (tử số, mẫu số)
// Đầu ra: true nếu hai phân số bằng nhau, ngược lại là false
bool isEqual(pair<int, int> a, pair<int,int> b){
    // Kiểm tra điều kiện (a1/a2 == b1/b2) bằng cách so sánh chéo a1*b2 và b1*a2
    return (a.numerator * b.denominator) == (a.denominator * b.numerator); 
}

// Comparator so sánh hai phân số từ bé đến lớn
// Đầu vào: hai phân số a và b dưới dạng cặp (tử số, mẫu số)
// Đầu ra: true nếu phân số a nhỏ hơn phân số b, ngược lại là false
bool cmp(pair<int, int> a, pair<int, int> b){
    // So sánh hai phân số a1/a2 và b1/b2 bằng cách chuyển chúng về số thực
    return (double)a.numerator / a.denominator < (double)b.numerator / b.denominator;
}

// Hàm nhân tất cả phân số trong 1 danh sách
// Đầu vào: một vector chứa phân số
// Đầu ra: một phân số là tích của tất cả phân số trong danh sách
pair<int,int> multiply(vector<pair<int,int>> fractions){
    int newNum = 1;  // Tử số khởi tạo là 1
    int newDeno = 1; // Mẫu số khởi tạo là 1

    // Nhân tất cả các phân số trong vector
    for(auto x : fractions){
        newNum *= x.numerator;
        newDeno *= x.denominator;
    }
    return {newNum, newDeno}; // Trả về tích phân số
}

// Hàm in phân số
// Đầu vào: một phân số dưới dạng cặp (tử số, mẫu số)
// Đầu ra: in phân số dưới dạng tử/mẫu
void printFraction(pair<int,int> a){
    cout << a.numerator << "/" << a.denominator << "\n";
}

// Hàm giải bài toán tìm tập con các phân số có tích bằng một phân số đích
// Đầu vào: một vector các phân số và phân số đích
// Đầu ra: in ra tập con nhỏ nhất (nếu có) có tích bằng phân số đích
void Solve(vector<pair<int,int>> fractions, pair<int,int> target){
    vector<pair<int,int>> result;  // Tập con nhỏ nhất có tích bằng phân số đích
    // Duyệt qua tất cả các tập con của dãy phân số
    for(int i = 0; i < (1 << fractions.size()); i++){
        vector<pair<int,int>> subset;  // Tập con hiện tại
        // Lấy các phần tử thuộc tập con dựa trên bitmask
        for(int j = 0; j < fractions.size(); j++){
            if( i & (1 << j)){
                subset.push_back(fractions[j]);
            }
        }
        // Nhân các phân số trong tập con hiện tại
        pair<int,int> product = multiply(subset);
        // Nếu tích bằng phân số đích và là tập con nhỏ nhất, lưu lại
        if(isEqual(product, target)){
            if(result.empty() || subset.size() < result.size()){
                result = subset;
            }
        }
    }

    // Nếu không tìm thấy tập con nào thỏa mãn, in ra thông báo không tìm được
    if(result.empty()){
        cout << "Can't find any suitable subset";
        return;
    }

    // Sắp xếp các phân số trong tập con theo thứ tự tăng dần
    sort(result.begin(), result.end(), cmp);
    cout << "Subset found: \n";
    // In ra các phân số trong tập con
    for(auto x : result){
        printFraction(x);
    }
    return;
}

int main(){
    int n;
    // Nhập số lượng phân số cho đến khi hợp lệ (lớn hơn 0)
    do{
        cout << "Enter the number of fractions: ";
        cin >> n;
        if(n <= 0) cout << "The number of fractions must be greater than 0!\n";
    } while (n <= 0);

    vector<pair<int, int>> arr(n);
    // Nhập các phân số từ người dùng
    for(int i = 0; i < n; i++){
        do{
            cout << "Enter the values of fraction " << i + 1 << " (numerator and denominator): ";
            cin >> arr[i].numerator >> arr[i].denominator;
            if(arr[i].denominator == 0) cout << "Denominator must be non-zero! Re-enter fraction.\n";
        } while (arr[i].denominator == 0); // Kiểm tra mẫu số phải khác 0
    }

    pair<int, int> target;
    // Nhập phân số đích
    do{
        cout << "Enter the target fraction (numerator and denominator): ";
        cin >> target.numerator >> target.denominator;
        if(target.denominator == 0) cout << "Denominator must be non-zero! Re-enter fraction.\n";
    } while (target.denominator == 0); // Kiểm tra mẫu số phải khác 0
    
    // Gọi hàm Solve để tìm tập con các phân số
    Solve(arr, target);
    return 0;
}
