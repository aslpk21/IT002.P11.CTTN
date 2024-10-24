#include <bits/stdc++.h>

using namespace std;

// Hàm biến đổi Arnold's Cat Map
// Đầu vào: ma trận và kích thước ma trận m
// Đầu ra: ma trận đã bị biến đổi theo công thức Arnold's Cat Map
void arnoldCatMap(vector<vector<int>>& matrix, int m) {
    vector<vector<int>> temp = matrix;  // Ma trận lưu kết quả biến đổi

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int newX = (2 * i + j) % m;  // Xác định vị trí hàng mới
            int newY = (i + j) % m;      // Xác định vị trí cột mới
            temp[newX][newY] = matrix[i][j];  // Gán giá trị từ ma trận cũ sang vị trí mới
        }
    }

    matrix = temp;  // Cập nhật ma trận đã biến đổi
}

// Hàm kiểm tra xem hai ma trận có giống nhau không
// Đầu vào: hai ma trận a, b và kích thước ma trận m
// Đầu ra: trả về true nếu hai ma trận giống nhau, ngược lại trả về false
bool isEqual(vector<vector<int>> a, vector<vector<int>> b, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                return false;  // Nếu có phần tử khác nhau, trả về false
            }
        }
    }
    return true;  // Sau khi kiểm tra tất cả phần tử đều giống nhau, trả về true
}

int main() {
    int m;
    cout << "Enter matrix size (m x m): ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    vector<vector<int>> original(m, vector<int>(m)); // Ma trận dùng để lưu lại dữ liệu ma trận gốc 

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            original[i][j] = matrix[i][j];  // Lưu ma trận ban đầu
        }
    }

    int k = 0;

    // Vòng lặp biến đổi ma trận cho đến khi nó quay về trạng thái ban đầu
    do {
        arnoldCatMap(matrix, m);  // Áp dụng phép biến đổi
        ++k;  // Tăng số lần biến đổi
    } while (!isEqual(matrix, original, m));  // Dừng vòng lặp khi ma trận trở về trạng thái ban đầu

    cout << "Transformations count: " << k << endl;

    return 0;
}
