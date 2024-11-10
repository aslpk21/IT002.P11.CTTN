#include "ThoiGian.cpp"

int main() {
    ThoiGian a, b, result;

    cout << "Nhap vao moc thoi gian dau tien (gio:phut:giay): ";
    cin >> a;
    cout << "Nhap vao moc thoi gian thu hai (gio:phut:giay): ";
    cin >> b;

    result = a + b;
    cout << "Tong thoi gian giua a va b: " << result << "\n";

    result = a - b;
    cout << "Hieu thoi gian giua a va b: " << result << '\n';

    int seconds;
    cout << "Nhap so giay de cong them vao thoi gian a: ";
    cin >> seconds;
    result = a + seconds;
    cout << "Thoi gian a sau khi cong " << seconds << " giay: " << result << "\n";

    cout << "Nhap so giay de tru vao thoi gian a: ";
    cin >> seconds;
    result = a - seconds;
    cout << "Thoi gian a sau khi tru " << seconds << " giay: " << result << "\n";

    cout << "So sanh thoi gian a va b:\n";
    cout << "a == b: " << (a == b ? "True" : "False") << "\n";
    cout << "a != b: " << (a != b ? "True" : "False") << "\n";
    cout << "a > b: " << (a > b ? "True" : "False") << "\n";
    cout << "a < b: " << (a < b ? "True" : "False") << "\n";
    cout << "a >= b: " << (a >= b ? "True" : "False") << "\n";
    cout << "a <= b: " << (a <= b ? "True" : "False") << "\n";

    return 0;
}
