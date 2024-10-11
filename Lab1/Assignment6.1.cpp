#include<bits/stdc++.h>

using namespace std;

/**
  Hàm computeZarray: Tính toán mảng Z cho chuỗi đầu vào.
  
  Đầu vào:
  - const vector<int>& str: Một vector các số nguyên đại diện cho chuỗi ký tự đầu vào (có thể là mảng A + B).
  
  Đầu ra:
  - vector<int>: Mảng Z, mỗi phần tử Z[i] cho biết đoạn tiền tố dài nhất của chuỗi (bắt đầu từ vị trí i) trùng với đoạn đầu tiên của chuỗi.
  
 Giải thích:
  - Mảng Z giúp tính toán các đoạn trùng lặp của mảng con trong chuỗi kết hợp A + B.
 */
vector<int> computeZarray(const vector<int>& str) {
    int n = str.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R] == str[R - L]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && str[R] == str[R - L]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

/**
 * Hàm Solve: Tìm số lần mảng A xuất hiện trong mảng B và in ra vị trí xuất hiện.
 * 
 * Đầu vào:
 * - const vector<int>& A: Mảng A (chuỗi mẫu).
 * - const vector<int>& B: Mảng B (chuỗi gốc).
 * 
 * Đầu ra:
 * - Không có giá trị trả về, nhưng in ra số lần A xuất hiện trong B và vị trí của chúng.
 * 
 * Giải thích:
 * - Kết hợp A và B lại thành một chuỗi (A + -1 + B) để tính mảng Z.
 * - Sau khi có mảng Z, kiểm tra xem tại các vị trí sau khi ghép, đoạn dài bằng mảng A có khớp với A không, nếu có thì lưu lại vị trí.
 */
void Solve(const vector<int>& A, const vector<int>& B) {
    // Ghép mảng A và B bằng cách thêm -1 (ký tự phân cách không thể có trong A hoặc B)
    vector<int> concat = A;
    concat.push_back(-1);  // Dùng -1 để đảm bảo không có sự trùng lặp giữa A và B
    concat.insert(concat.end(), B.begin(), B.end());

    // Tính toán mảng Z cho chuỗi kết hợp
    vector<int> Z = computeZarray(concat);
    int m = A.size();  // Độ dài mảng A
    vector<int> positions;  // Vị trí tìm thấy A trong B

    // Duyệt qua phần sau của mảng Z để tìm mảng con khớp với A
    for (int i = m + 1; i < Z.size(); i++) {
        if (Z[i] == m) {
            positions.push_back(i - m - 1);  // Lưu lại vị trí khớp
        }
    }

    // In ra kết quả
    cout << "Number of times array A appears in array B: " << positions.size() << endl;
    cout << "Positions: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    // Nhập kích thước mảng A và B
    cout << "Enter size of array A: ";
    cin >> n;
    cout << "Enter size of array B: ";
    cin >> m;

    vector<int> arrA(n);
    vector<int> arrB(m);

    // Nhập các phần tử của mảng A
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
    }

    // Nhập các phần tử của mảng B
    cout << "Enter elements of array B: ";
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];
    }

    // Gọi hàm Solve để tính toán và in ra kết quả
    Solve(arrA, arrB);

    return 0;
}
