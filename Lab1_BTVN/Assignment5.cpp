#include <bits/stdc++.h>

using namespace std;

// Hàm kiểm tra xem vùng (i, j, w, h) có phải là một hình chữ nhật hợp lệ hay không
// Đầu vào:
// - matrix: ma trận nhị phân
// - i, j: tọa độ gốc (trên cùng bên trái) của hình chữ nhật
// - width: chiều rộng của hình chữ nhật
// - height: chiều cao của hình chữ nhật
// Đầu ra: true nếu hình chữ nhật hợp lệ, false nếu không
bool isValid(const vector<vector<int>>& matrix, int i, int j, int width, int height) {
    // Kiểm tra tất cả các ô bên trong hình chữ nhật
    // Nếu có phần tử nào là 0 thì hình chữ nhật không hợp lệ
    for (int y = j; y < j + height; y++) {
        for (int x = i; x < i + width; x++) {
            if (!matrix[y][x]) return false;
        }
    }

    // Kiểm tra các ô bao quanh hình chữ nhật
    for (int y = j - 1; y <= j + height; y++) {
        for (int x = i - 1; x <= i + width; x++) {
            // Nếu ô nằm ngoài giới hạn ma trận thì bỏ qua
            // Nếu hình chữ nhật có ô xung quanh là 1 nằm liền kề thì hình chữ nhật không hợp lệ
            if (y >= 0 && y < matrix.size() && x >= 0 && x < matrix[0].size() && matrix[y][x]) {
                if (!(y >= j && y < j + height && x >= i && x < i + width)) {
                // - (y >= j && y < j + height && x >= i && x < i + width)) là phạm vi hình chữ nhật đang xét
                // - !(y >= j && y < j + height && x >= i && x < i + width)) là những ô nằm bao quanh hình chữ nhật
                    return false;
                }
            }
        }
    }
    return true; // Hình chữ nhật hợp lệ
}

// Hàm tìm các hình chữ nhật trong ma trận
// Đầu vào:
// - matrix: ma trận nhị phân
// - n: số hàng của ma trận
// - m: số cột của ma trận
// Đầu ra: danh sách các hình chữ nhật dưới dạng tuple (x, y, width, height)
vector<tuple<int, int, int, int>> Solve(vector<vector<int>> matrix, int n, int m) {
    vector<tuple<int, int, int, int>> result; // Danh sách kết quả chứa các hình chữ nhật
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // Mảng đánh dấu các ô đã xét qua

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            // Nếu ô tại (i, j) là 1 và chưa được đánh dấu
            if (matrix[j][i] && !visited[j][i]) {
                int width = 0;
                int height = 0;

                // Tìm chiều rộng của hình chữ nhật từ (i, j)
                // Nếu chiều rộng vẫn nằm trong phạm vi ma trận và phần từ kế tiếp là 1 thì kéo dài chiều rộng
                while (i + width < m && matrix[j][i + width]) {
                    ++width;
                }

                // Tìm chiều cao của hình chữ nhật từ (i, j)
                // Nếu chiều cao vẫn nằm trong phạm vi ma trận và phần từ kế tiếp là 1 thì kéo dài chiều cao
                while (j + height < n && matrix[j + height][i]) {
                    ++height;
                }

                // Kiểm tra nếu đây là hình chữ nhật hợp lệ
                if (width >= 2 && height >= 2 && isValid(matrix, i, j, width, height)) {
                    result.push_back({i, j, width, height}); // Lưu lại hình chữ nhật
                    
                    // Đánh dấu tất cả các ô trong hình chữ nhật này là đã được xét qua
                    for (int y = j; y < j + height; y++) {
                        for (int x = i; x < i + width; x++) {
                            visited[y][x] = true;
                        }
                    }
                }
            }
        }
    }

    // Sắp xếp hình chữ nhật từ trái sang phải và từ trên xuống dưới
    sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    return result; // Trả về danh sách các hình chữ nhật tìm thấy
}

int main() {
    int n, m;
    cout << "Enter matrix size (n x m): ";
    cin >> n >> m; // Nhập kích thước ma trận n x m

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter binary matrix elements:\n";
    // Nhập các phần tử của ma trận nhị phân
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tìm các hình chữ nhật trong ma trận
    vector<tuple<int, int, int, int>> rectangles = Solve(matrix, n, m);

    // Nếu không có hình chữ nhật nào tồn tại trong ma trận
    // In ra thông báo không tìm thấy và thoát
    if(rectangles.empty()){
        cout << "Can't find any rectangles!\n";
        return 0;
    }

    // Xuất danh sách các hình chữ nhật tìm được
    cout << "\nRectangles found:\n";
    for (const auto& rect : rectangles) {
        cout << "[" << get<0>(rect) << ", " << get<1>(rect)
             << ", " << get<2>(rect) << ", " << get<3>(rect) << "]\n";
    }
    return 0;
}
