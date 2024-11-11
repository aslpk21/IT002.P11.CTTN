#include "NgayThangNam.cpp"

int main() {
    NgayThangNam a, b, result;

    cout << "Nhap vao moc thoi gian dau tien (ngay thang nam): ";
    cin >> a;
    cout << "Nhap vao moc thoi gian thu hai (ngay thang nam): ";
    cin >> b;

    int daysDifference = a - b;
    cout << "Khoang cach giua a va b la: " << abs(daysDifference) << " ngay\n";

    int daysToAdd;
    cout << "Nhap so ngay de cong them vao ngay a: ";
    cin >> daysToAdd;
    result = a + daysToAdd;
    cout << "Ngay a sau khi cong " << daysToAdd << " ngay: " << result << "\n";

    int daysToSubtract;
    cout << "Nhap so ngay de tru vao ngay a: ";
    cin >> daysToSubtract;
    result = a - daysToSubtract;
    cout << "Ngay a sau khi tru " << daysToSubtract << " ngay: " << result << "\n";

    cout << "So sanh ngay thang nam a va b:\n";
    cout << "a == b: " << (a == b ? "True" : "False") << "\n";
    cout << "a != b: " << (a != b ? "True" : "False") << "\n";
    cout << "a > b: " << (a > b ? "True" : "False") << "\n";
    cout << "a < b: " << (a < b ? "True" : "False") << "\n";
    cout << "a >= b: " << (a >= b ? "True" : "False") << "\n";
    cout << "a <= b: " << (a <= b ? "True" : "False") << "\n";

    return 0;
}
