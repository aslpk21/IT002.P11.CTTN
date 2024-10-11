#include<iostream>

using namespace std;

// Khai báo biến toàn cục cho ngày, tháng, năm
int day, month, year;

// Mảng chứa số ngày của mỗi tháng cho năm thường (hàng 0) và năm nhuận (hàng 1)
int days[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
                   { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

// Hàm kiểm tra năm nhuận
// Đầu vào: năm
// Đầu ra: true nếu là năm nhuận, false nếu không phải năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Hàm kiểm tra tính hợp lệ của ngày, tháng, năm
// Đầu vào: ngày, tháng, năm
// Đầu ra: true nếu ngày hợp lệ, false nếu không hợp lệ
// Kiểm tra ngày có nằm trong khoảng cho phép của tháng đó và tháng có hợp lệ hay không
bool isValidDate(int day, int month, int year) {
    // Kiểm tra tính hợp lệ của ngày, tháng, năm
    if (day < 1 || day > days[isLeapYear(year) ? 1 : 0][month - 1]) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1) return false;
    return true;
}

// Hàm tính ngày kế tiếp dựa trên ngày, tháng, năm hiện tại
// Đầu vào: ngày, tháng, năm hiện tại
// Đầu ra: giá trị của ngày kế tiếp
void calcNextDay(int &day, int &month, int &year) {
    // Nếu ngày nhỏ hơn số ngày của tháng hiện tại, tăng ngày lên 1
    if(day > 0 && day < days[isLeapYear(year) ? 1 : 0][month - 1]) {
        day++;
    }
    else { // Nếu hết tháng, chuyển sang tháng tiếp theo
        day = 1;
        if(month == 12) { // Nếu hết năm, tăng năm lên 1
            month = 1;
            year++;
        }
        else { // Nếu chưa hết năm, chỉ tăng tháng
            month++;
        }
    }
}

// Hàm tính ngày trước đó dựa trên ngày, tháng, năm hiện tại
// Đầu vào: ngày, tháng, năm của ngày hiện tại
// Đầu ra: giá trị của ngày trước ngày hiện tại
void calcPreviousDay(int &day, int &month, int &year) {
    // Nếu ngày lớn hơn 1, giảm ngày đi 1
    if(day > 1) {
        day--;
    }
    else { // Nếu ngày là 1, cần chuyển sang tháng trước
        if(month == 1) { // Nếu đang là tháng 1, lùi lại tháng 12 của năm trước
            day = 31;
            month = 12;
            year--;
        }
        else { // Lùi về tháng trước và đặt ngày bằng số ngày cuối của tháng đó
            month--;
            day = days[isLeapYear(year) ? 1 : 0][month-1];
        }
    }
}

// Hàm tính số ngày đã trôi qua trong năm dựa trên ngày, tháng, năm hiện tại
// Đầu vào: ngày, tháng, năm hiện tại
// Đầu ra: trả về tổng số ngày đã trôi qua trong năm
int dateOfYear(int &day, int &month, int &year) {
    int res = 0;
    // Cộng dồn số ngày của các tháng trước tháng hiện tại
    for(int i = 1; i < month; i++) {
        res += days[isLeapYear(year) ? 1 : 0][i-1];
    }
    // Cộng thêm số ngày của tháng hiện tại
    res += day;
    return res;
}

// Hàm nhập ngày, tháng, năm từ người dùng
// Giá trị của các biến toàn cục day, month, year sẽ được gán bởi dữ liệu nhập từ người dùng
void InputDate() {
    cout << "Enter date: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}

int main() {
    // Nhập ngày, tháng, năm từ người dùng
    InputDate();

    // Kiểm tra tính hợp lệ của ngày, tháng, năm nhập vào
    while(!isValidDate(day, month, year)) {
        cout << "Invalid date! Try again\n";
        InputDate(); // Nếu không hợp lệ, yêu cầu nhập lại
    }
    
    // Tính toán ngày kế tiếp
    int nextDay = day, nextMonth = month, nextYear = year;
    calcNextDay(nextDay, nextMonth, nextYear);
    cout << "The next day is: " << nextDay << "/" << nextMonth << "/" << nextYear << "\n";

    // Tính toán ngày trước đó
    int prevDay = day, prevMonth = month, prevYear = year;
    calcPreviousDay(day, month, year);
    cout << "The previous day is: " << day << "/" << month << "/" << year << "\n";

    // Tính toán số ngày đã trôi qua trong năm
    int date = dateOfYear(day, month, year);
    cout << "The number of days in year is: " << date << "\n";

    return 0;
}
