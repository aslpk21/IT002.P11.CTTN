#include "NgayThangNam.h"

// Constructor mặc định, thiết lập ngày 01/01/0001
NgayThangNam::NgayThangNam() {
    iNgay = 1;
    iThang = 1;
    iNam = 1;
}

// Constructor khởi tạo với tham số được truyền vào 
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {
    iNam = Nam;
    iThang = Thang;
    iNgay = Ngay;
}

// Hàm tính số ngày của một mốc thời gian
// Output: Số ngày tính từ 01/01/0001 đến ngày hiện tại
// Tính tổng số ngày dựa trên số ngày của các năm trước đó, các tháng trước đó trong năm hiện tại,
// và nếu là năm nhuận, cộng thêm 1 ngày cho tháng 2 nếu đã qua tháng 2.
int NgayThangNam::TinhNgay() {
    static int soNgayThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int soNgay = iNgay;

    // Cộng ngày của các năm trước đó
    for (int nam = 1; nam < iNam; nam++) {
        soNgay += (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0)) ? 366 : 365;
    }
    // Cộng ngày của các tháng trước đó trong năm hiện tại
    for (int thang = 1; thang < iThang; thang++) {
        soNgay += soNgayThang[thang - 1];
    }
    // Nếu là năm nhuận và đã trôi qua tháng 2 thì cộng thêm 1 ngày
    if ((iNam % 4 == 0 && (iNam % 100 != 0 || iNam % 400 == 0)) && iThang > 2) {
        soNgay++;
    }

    return soNgay;
}

// Toán tử cộng để cộng thêm một số ngày vào đối tượng NgayThangNam hiện tại
// Input: Số ngày cần cộng thêm
// Output: Trả về đối tượng NgayThangNam với giá trị ngày, tháng, năm đã được cộng thêm
// Giải thuật:
// 1. Tính tổng số ngày hiện tại từ ngày khởi đầu (1/1/0001) bằng hàm TinhNgay(), rồi cộng thêm số ngày (ngay).
// 2. Xác định năm mới bằng cách trừ số ngày trong mỗi năm khỏi totalDays đến khi số ngày còn lại nhỏ hơn hoặc bằng số ngày của năm hiện tại.
// 3. Xác định tháng mới trong năm bằng cách trừ số ngày của từng tháng khỏi totalDays đến khi số ngày còn lại nhỏ hơn hoặc bằng số ngày của tháng hiện tại.
// 4. Trả về đối tượng NgayThangNam với ngày, tháng, và năm mới.

NgayThangNam NgayThangNam::operator+(int ngay) {
    int totalDays = TinhNgay() + ngay;
    int newYear = 1;
    static int soNgayThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Xác định năm mới bằng cách trừ số ngày trong mỗi năm
    while (totalDays > 365) {
        bool isLeapYear = (newYear % 4 == 0 && (newYear % 100 != 0 || newYear % 400 == 0));
        int daysInYear = isLeapYear ? 366 : 365;
        
        if (totalDays > daysInYear) {
            totalDays -= daysInYear;
            newYear++;
        } else {
            break;
        }
    }

    // Xác định tháng mới trong năm bằng cách trừ số ngày của từng tháng
    int newMonth = 1;
    for (int i = 0; i < 12; i++) {
        int daysInMonth = soNgayThang[i];
        // Xét trường hợp năm nhuận cho tháng 2
        if (i == 1 && (newYear % 4 == 0 && (newYear % 100 != 0 || newYear % 400 == 0))) {
            daysInMonth = 29;
        }

        if (totalDays > daysInMonth) {
            totalDays -= daysInMonth;
            newMonth++;
        } else {
            break;
        }
    }

    // Trả về đối tượng NgayThangNam với năm, tháng, ngày đã tính toán
    return NgayThangNam(newYear, newMonth, totalDays);
}


// Toán tử - để trừ số ngày từ ngày hiện tại
// Input: Số ngày cần trừ
// Output: NgayThangNam mới sau khi trừ ngày từ ngày hiện tại
// Sử dụng toán tử + với số âm để trừ ngày.
NgayThangNam NgayThangNam::operator-(int ngay) {
    return *this + (-ngay);
}

// Toán tử - giữa hai đối tượng NgayThangNam để tính khoảng cách ngày
// Input: Ngày cần trừ
// Output: Khoảng cách giữa hai ngày
// Trả về chênh lệch giữa số ngày của hai đối tượng bằng hàm TinhNgay.
int NgayThangNam::operator-(NgayThangNam a) {
    return TinhNgay() - a.TinhNgay();
}

// Các toán tử so sánh: ==, !=, >=, <=, >, <
// Input: Một đối tượng NgayThangNam khác để so sánh
// Output: Trả về giá trị true hoặc false dựa trên kết quả của phép so sánh tương ứng
// So sánh năm (iNam), sau đó so sánh tháng (iThang) nếu năm bằng nhau,
// và cuối cùng so sánh ngày (iNgay) nếu cả năm và tháng đều bằng nhau

bool NgayThangNam::operator==(NgayThangNam a) {
    return iNam == a.iNam && iThang == a.iThang && iNgay == a.iNgay;
}

bool NgayThangNam::operator!=(NgayThangNam a) {
    return !(*this == a);
}

bool NgayThangNam::operator>=(NgayThangNam a) {
    return (iNam > a.iNam) || (iNam == a.iNam && (iThang > a.iThang || (iThang == a.iThang && iNgay >= a.iNgay)));
}

bool NgayThangNam::operator<=(NgayThangNam a) {
    return (iNam < a.iNam) || (iNam == a.iNam && (iThang < a.iThang || (iThang == a.iThang && iNgay <= a.iNgay)));
}

bool NgayThangNam::operator>(NgayThangNam a) {
    return (iNam > a.iNam) || (iNam == a.iNam && (iThang > a.iThang || (iThang == a.iThang && iNgay > a.iNgay)));
}

bool NgayThangNam::operator<(NgayThangNam a) {
    return (iNam < a.iNam) || (iNam == a.iNam && (iThang < a.iThang || (iThang == a.iThang && iNgay < a.iNgay)));
}

// Hàm nhập ngày tháng năm từ người dùng
// Input: Ngày, tháng, năm nhập vào từ người dùng theo dạng (dd mm yyyy)
// Dùng vòng lặp do-while để yêu cầu nhập cho đến khi ngày hợp lệ với điều kiện kiểm tra
// Điều kiện:
// - Năm phải lớn hơn 0 (sau công nguyên)
// - Tháng phải nằm trong khoảng từ 1 đến 12
// - Ngày phải nằm trong giới hạn số ngày của tháng đó
istream& operator>>(istream& in, NgayThangNam& nt) {
    bool valid;
    
    do {
        in >> nt.iNgay >> nt.iThang >> nt.iNam;

        valid = nt.iNam >= 1;
        if (!valid) {
            cout << "Năm phải lớn hơn 0!" << endl;
            continue;
        }

        valid = (nt.iThang >= 1 && nt.iThang <= 12);
        if (!valid) {
            cout << "Tháng phải nằm trong khoảng từ 1 đến 12!" << endl;
            continue;
        }

        static int soNgayThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxNgay = soNgayThang[nt.iThang - 1];

        if (nt.iThang == 2 && ((nt.iNam % 4 == 0 && nt.iNam % 100 != 0) || (nt.iNam % 400 == 0))) {
            maxNgay = 29;
        }

        valid = (nt.iNgay >= 1 && nt.iNgay <= maxNgay);
        if (!valid) {
            cout << "Ngày phải nằm trong khoảng từ 1 đến " << maxNgay << " của tháng " << nt.iThang << "!" << endl;
        }

    } while (!valid);

    return in;
}

// Hàm xuất ngày tháng năm
// Input: Đối tượng NgayThangNam cần xuất
// Output: Chuỗi ngày tháng năm theo định dạng dd/mm/yyyy
ostream& operator<<(ostream& out, NgayThangNam& nt) {
    out << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return out;
}
