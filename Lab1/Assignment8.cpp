#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// Mảng lưu số ngày trong tháng, với hai trường hợp năm thường và năm nhuận
int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// Hàm kiểm tra năm nhuận
// Đầu vào: năm
// Đầu ra: trả về true nếu là năm nhuận, false nếu không phải
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Cấu trúc lưu thông tin về ngày
struct Date {
    int date, month, year;
};

// Cấu trúc lưu thông tin sổ tiết kiệm
struct savingsBook {
    string ID;           // Mã sổ
    string type;         // Loại tiết kiệm (ShortTerm hoặc LongTerm)
    string custmName;    // Tên khách hàng
    int idenityNumber;   // Số CCCD của khách hàng
    Date openingDate;    // Ngày mở sổ
    int moneyAmount;     // Số tiền gửi ban đầu
    double interestRate; // Lãi suất (%)
};

// Hàm kiểm tra mã sổ có hợp lệ không
// Đầu vào: chuỗi mã sổ tiết kiệm
// Đầu ra: true nếu mã hợp lệ, false nếu không
bool isValidId(string &id) {
    // Mã sổ phải là 5 kí tự và chỉ được chứa chữ cái và số
    if (id.size() != 5) return false; 
    for (char c : id) {
        if (!(isalpha(c)) && !(isalnum(c))) return false;
    }
    return true;
}

// Hàm kiểm tra loại tiết kiệm có hợp lệ không
// Đầu vào: chuỗi loại tiết kiệm (ShortTerm hoặc LongTerm)
// Đầu ra: true nếu hợp lệ, false nếu không
bool isValidSavingType(string &type) {
    return (type == "ShortTerm" || type == "LongTerm");
}

// Hàm kiểm tra tên khách hàng
// Đầu vào: chuỗi tên khách hàng
// Đầu ra: true nếu hợp lệ, false nếu không
bool isValidCustomerName(string &name) {
    for (char c : name) {
        if (!(isalpha(c)) && c != ' ') return false;
    }
    return true;
}

// Hàm kiểm tra số CCCD có hợp lệ hay không
// Đầu vào: số CCCD (số nguyên)
// Đầu ra: true nếu có 9 hoặc 12 chữ số, false nếu không
bool isValidIdenityNumber(const int &number) {
    string numberStr = to_string(number);
    if (numberStr.size() != 9 && numberStr.size() != 12) return false;
    return true;
}

// Hàm kiểm tra ngày mở sổ có hợp lệ hay không
// Đầu vào: ngày, tháng, năm (struct Date)
// Đầu ra: true nếu hợp lệ, false nếu không
bool isValidOpenDate(Date &day) {
    // Kiểm tra ngày, tháng, năm hợp lệ
    if (day.date < 1 || day.date > days[isLeapYear(day.year) ? 1 : 0][day.month - 1]) return false;
    if (day.month < 1 || day.month > 12) return false;
    if (day.year < 1) return false;
    return true;
}

// Hàm kiểm tra số tiền có hợp lệ hay không
// Đầu vào: số tiền 
// Đầu ra: true nếu lớn hơn 0, false nếu không hợp lệ
bool isValidMoneyAmount(int &money) {
    return money > 0;
}

// Hàm nhập thông tin sổ tiết kiệm từ người dùng
void inputSavingsBookInfor(savingsBook &sample) {
    cout << "Enter savings book's information: \n";

    // Nhập mã sổ, yêu cầu phải hợp lệ
    do {
        cout << "Enter savings book's ID: ";
        cin >> sample.ID;
        if (!isValidId(sample.ID))
            cout << "Invalid ID!\n";
    } while (!isValidId(sample.ID));

    // Nhập loại tiết kiệm, chỉ nhận "ShortTerm" hoặc "LongTerm"
    do {
        cout << "Choose savings book's saving type (ShortTerm/LongTerm): ";
        cin >> sample.type;
        if (!isValidSavingType(sample.type))
            cout << "Invalid saving type!\n";
    } while (!isValidSavingType(sample.type));

    cin.ignore();  // Bỏ qua ký tự thừa sau khi nhập dữ liệu

    // Nhập tên khách hàng, yêu cầu chỉ gồm chữ cái và dấu cách
    do {
        cout << "Enter customer's full name: ";
        getline(cin, sample.custmName);
        if (!isValidCustomerName(sample.custmName))
            cout << "Invalid name!";
    } while (!isValidCustomerName(sample.custmName));

    // Nhập số CCCD, yêu cầu phải có 9 hoặc 12 chữ số
    do {
        cout << "Enter customer's identity number (9 or 12 digits): ";
        cin >> sample.idenityNumber;
        if (!isValidIdenityNumber(sample.idenityNumber))
            cout << "Invalid identity number!\n";
    } while (!isValidIdenityNumber(sample.idenityNumber));

    // Nhập ngày mở sổ, kiểm tra ngày hợp lệ
    do {
        cout << "Enter the opening date (DD MM YYYY): ";
        cin >> sample.openingDate.date >> sample.openingDate.month >> sample.openingDate.year;
        if (!isValidOpenDate(sample.openingDate))
            cout << "Invalid date!\n";
    } while (!isValidOpenDate(sample.openingDate));

    // Nhập số tiền gửi, yêu cầu số tiền phải lớn hơn 0
    do {
        cout << "Enter the amount of money deposited: ";
        cin >> sample.moneyAmount;
        if (!isValidMoneyAmount(sample.moneyAmount))
            cout << "Invalid amount!\n";
    } while (!isValidMoneyAmount(sample.moneyAmount));

    // Nhập lãi suất, yêu cầu lớn hơn 0%
    do {
        cout << "Enter the interest rate (%): ";
        cin >> sample.interestRate;
        if (sample.interestRate <= 0)
            cout << "Interest rate must be positive!\n";
    } while (sample.interestRate <= 0);
    cout << endl;
}

// Hàm nhập ngày từ người dùng
void inputDate(Date &dateInput) {
    do {
        cout << "Enter date (DD MM YYYY): ";
        cin >> dateInput.date >> dateInput.month >> dateInput.year;
        if (!isValidOpenDate(dateInput)) {
            cout << "Invalid date! Please enter a valid date.\n";
        }
    } while (!isValidOpenDate(dateInput));
}

// Hàm hiển thị thông tin chi tiết sổ tiết kiệm
void displayInfor(savingsBook &sample) {
    cout << "Savings Book ID: " << sample.ID << "\n"
         << "Type of Saving: " << sample.type << "\n"
         << "Customer Name: " << sample.custmName << "\n"
         << "Identity Number: " << to_string(sample.idenityNumber) << "\n"
         << "Open Date: " << sample.openingDate.date << "/" << sample.openingDate.month << "/" << sample.openingDate.year << "\n"
         << "Amount of Money: " << sample.moneyAmount << "\n"
         << "\n";
}

// Hàm chuyển chuỗi sang dạng chữ thường để tìm kiếm dễ dàng
string toLowerCase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Hàm tìm kiếm sổ tiết kiệm theo mã sổ hoặc CCCD
// Đầu vào: danh sách sổ tiết kiệm, chuỗi tìm kiếm (mã sổ hoặc CCCD)
// Đầu ra: hiển thị danh sách các sổ tiết kiệm có mã sổ hoặc CCCD khớp với chuỗi tìm kiếm
void findBooksById(vector<savingsBook> &Books, string searchString) {
    searchString = toLowerCase(searchString); // Đưa chuỗi tìm kiếm về chữ thường
    vector<savingsBook> result;

    // Duyệt qua tất cả các sổ tiết kiệm trong danh sách
    for (auto &book : Books) {
        // So sánh mã sổ và CCCD đã chuyển thành chuỗi với chuỗi tìm kiếm
        if (toLowerCase(book.ID) == searchString || to_string(book.idenityNumber) == searchString)
            result.push_back(book); // Nếu tìm thấy khớp, thêm sổ vào danh sách kết quả
    }

    // Kiểm tra nếu không tìm thấy sổ tiết kiệm nào
    if (result.empty()) {
        cout << "Cannot find any savings book by that ID/Identity Number!\n";
        return;
    }

    // Hiển thị danh sách các sổ tiết kiệm đã tìm được
    cout << "List of possible savings books found: \n";
    for (auto &book : result) {
        displayInfor(book); // Hiển thị thông tin chi tiết của từng sổ
    }
    cout << "\n";
}


// Comparator so sánh ngày theo thời gian từ sớm đến muộn
bool isEarlierOrEqual(Date date1, Date date2) {
    if (date1.year < date2.year) return true;
    if (date1.year == date2.year && date1.month < date2.month) return true;
    if (date1.year == date2.year && date1.month == date2.month && date1.date <= date2.date) return true;
    return false;
}

// Hàm tìm các sổ tiết kiệm được mở trong khoảng thời gian nhất định
// Đầu vào: danh sách sổ tiết kiệm, ngày bắt đầu và ngày kết thúc
// Đầu ra: hiển thị danh sách các sổ tiết kiệm được mở trong khoảng thời gian này
void findBooksByDateRange(vector<savingsBook> &Books, Date startDate, Date endDate) {
    vector<savingsBook> result;

    // Duyệt qua tất cả các sổ tiết kiệm trong danh sách
    for (auto &book : Books) {
        // Kiểm tra xem ngày mở sổ có nằm trong khoảng thời gian từ startDate đến endDate hay không
        if (isEarlierOrEqual(startDate, book.openingDate) && isEarlierOrEqual(book.openingDate, endDate))
            result.push_back(book); // Nếu hợp lệ, thêm sổ tiết kiệm vào danh sách kết quả
    }

    // Kiểm tra nếu không có sổ tiết kiệm nào trong khoảng thời gian này
    if (result.empty()) {
        cout << "No savings books were opened in this period.\n";
        return;
    }

    // Hiển thị danh sách các sổ tiết kiệm đã tìm được
    cout << "List of savings books opened in the given period: \n";
    for (auto &book : result) {
        displayInfor(book); // Hiển thị thông tin chi tiết của từng sổ
    }
    cout << "\n";
}


// Comparator so sánh số tiền gửi theo thứ tự từ lớn đến bé
bool moneyComparator(savingsBook a, savingsBook b){
    return a.moneyAmount > b.moneyAmount;
}

// Hàm sắp xếp sổ tiết kiệm theo thứ tự số tiền gửi giảm dần
void sortByMoney(vector<savingsBook> &Books){
    sort(Books.begin(), Books.end(), moneyComparator);
}

// Comparator so sánh ngày mở sổ từ sớm đến muộn
bool openDateComparator(savingsBook a, savingsBook b){
    if(a.openingDate.year != b.openingDate.year) return a.openingDate.year < b.openingDate.year;
    if(a.openingDate.month != b.openingDate.month) return a.openingDate.month < b.openingDate.month;
    if(a.openingDate.date != b.openingDate.date) return a.openingDate.date < b.openingDate.date;
}

// Hàm sắp xếp sổ tiết kiệm theo ngày mở sổ từ sớm đến muộn
void sortByOpenDate(vector<savingsBook> &Books){
    sort(Books.begin(), Books.end(), openDateComparator);
}

// Hàm tính toán số ngày giữa 2 ngày chỉ định
// Đầu vào: ngày bắt đầu và ngày kết thúc
// Đầu ra: khoảng cách giũa 2 ngày
int calculateDaysBetween(Date startDate, Date endDate) {
    tm start = {0, 0, 0, startDate.date, startDate.month - 1, startDate.year - 1900};
    tm end = {0, 0, 0, endDate.date, endDate.month - 1, endDate.year - 1900};
    
    time_t startTime = mktime(&start);
    time_t endTime = mktime(&end);

    return difftime(endTime, startTime) / (60 * 60 * 24);
}

// Hàm tính toán số tiền lãi
// Đầu vào: sổ tiết kiệm cần tính và ngày hiện tại
// Đầu ra: số tiền lãi đã nhận được
double calculateInterest(savingsBook &book, Date currentDate) {
    // Tính số ngày từ ngày mở sổ đến ngày hiện tại
    int days = calculateDaysBetween(book.openingDate, currentDate);
    
    // Chuyển đổi số ngày sang số tháng
    int months = days / 30; 
    
    double actualInterestRate = 0;

    // Kiểm tra loại sổ tiết kiệm và điều chỉnh lãi suất tương ứng
    if (book.type == "ShortTerm") {
        // Nếu là sổ ngắn hạn, lãi suất gốc áp dụng cho số tháng <= 6
        if (months <= 6) {
            actualInterestRate = book.interestRate;
        } 
        // Nếu vượt quá 6 tháng, lãi suất giảm đi một nửa
        else {
            actualInterestRate = book.interestRate / 2;
        }
    } 
    else if (book.type == "LongTerm") {
        // Nếu là sổ dài hạn, lãi suất đầy đủ chỉ áp dụng khi vượt quá 6 tháng
        if (months > 6) {
            actualInterestRate = book.interestRate; 
        } 
        // Nếu chưa đến 6 tháng, lãi suất giảm đi một nửa
        else {
            actualInterestRate = book.interestRate / 2;
        }
    }

    // Tính toán và trả về số tiền lãi nhận được dựa trên số ngày và lãi suất
    return (book.moneyAmount * actualInterestRate * days) / (100 * 365);
}

// Hàm hiển thị tiền lãi của sổ tiết kiệm
void displayInterest(savingsBook &book) {
    Date currentDate;
    
    // Nhập ngày hiện tại
    inputDate(currentDate);

    // Tính toán tiền lãi dựa trên ngày hiện tại
    double interest = calculateInterest(book, currentDate);

    // Hiển thị tiền lãi cho sổ tiết kiệm
    cout << "The interest amount for savings book " << book.ID 
         << " is: " << interest << endl;
}

// Hàm rút tiền từ sổ tiết kiệm
// Đầu vào: sổ tiết kiệm muốn rút, số tiền rút
void withdrawMoney(savingsBook &book, int amount) {
    // Kiểm tra số tiền rút có hợp lệ (phải lớn hơn 0)
    if (amount <= 0) {
        cout << "Invalid amount to withdraw!" << endl;
        return;
    }

    // Kiểm tra số dư tài khoản có đủ để rút số tiền yêu cầu hay không
    if (book.moneyAmount < amount) {
        cout << "Insufficient balance!" << endl;
        return;
    }

    // Trừ số tiền rút từ số dư tài khoản
    book.moneyAmount -= amount;

    // Hiển thị thông báo rút tiền thành công và số dư còn lại
    cout << "Withdrawal successful! Amount withdrawn: " << amount << endl;
    cout << "Remaining balance: " << book.moneyAmount << endl;

    return;
}


// Hàm hiển thị menu lựa chọn
void showMenu(){
    cout << "Menu: \n"
         << "1. Display savings book list \n"
         << "2. Find savings book by ID or Identity Number \n"
         << "3. Calculate interest for a specific savings book \n"
         << "4. Withdraw money from a savings book \n"
         << "5. Find savings books by opening date range \n"
         << "6. Sort savings books by amount or opening date \n"
         << "0. Exit\n";
}

int main() {
    int n;
    cout << "Enter the number of savings books: ";
    cin >> n;
    vector<savingsBook> books(n);
    for(auto &book : books) {
        inputSavingsBookInfor(book); // Nhập thông tin cho từng sổ tiết kiệm
    }

    int option;
    while (true) {
        showMenu(); // Hiển thị menu
        cout << "\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                // Hiển thị danh sách tất cả sổ tiết kiệm
                cout << "\nSavings Book List: \n";
                for (auto &book : books) {
                    displayInfor(book); // Hiển thị thông tin từng sổ tiết kiệm
                    cout << endl;
                }
                break;

            case 2: {
                // Tìm kiếm sổ tiết kiệm theo mã sổ hoặc CCCD
                string searchStr;
                cout << "Enter savings book ID or Identity Number to search: ";
                cin >> searchStr;
                findBooksById(books, searchStr); // Tìm kiếm và hiển thị sổ tiết kiệm phù hợp
                break;
            }

            case 3: {
                // Tính tiền lãi cho một sổ tiết kiệm
                string searchStr;
                cout << "Enter savings book ID to calculate interest: ";
                cin >> searchStr;
                savingsBook bookToDisplay;
                for(auto book : books){
                    if(book.ID == searchStr){
                        bookToDisplay = book;
                        break;
                    }
                }
                displayInterest(bookToDisplay);
                break;
            }

            case 4: {
                // Rút tiền từ sổ tiết kiệm
                string searchStr;
                cout << "Enter savings book ID to withdraw money from: ";
                cin >> searchStr;
                savingsBook bookToDisplay;
                for(auto book : books){
                    if(book.ID == searchStr){
                        bookToDisplay = book;
                        break;
                    }
                }
                cout << "Enter the amount of money to withdraw: ";
                int amount;
                cin >> amount;
                withdrawMoney(bookToDisplay, amount);
                break;
            }

            case 5: {
                // Tìm các sổ tiết kiệm theo khoảng thời gian mở
                Date startDate, endDate;
                cout << "Enter start date (format DD MM YYYY): ";
                inputDate(startDate); // Nhập ngày bắt đầu
                cout << "Enter end date (format DD MM YYYY): ";
                inputDate(endDate);   // Nhập ngày kết thúc
                findBooksByDateRange(books, startDate, endDate); // Tìm và hiển thị sổ tiết kiệm trong khoảng thời gian
                break;
            }

            case 6: {
                // Sắp xếp danh sách sổ tiết kiệm
                int sortOption;
                cout << "Sort by: \n"
                     << "1. Amount \n"
                     << "2. Opening Date \n"
                     << "Choose an option: ";
                cin >> sortOption;

                if (sortOption == 1) {
                    sortByMoney(books);
                } else if (sortOption == 2) {
                    sortByOpenDate(books);
                } else {
                    cout << "Invalid sort option!\n";
                    break;
                }

                cout << "\nSavings books sorted successfully!\n"; // Thông báo sắp xếp thành công
                cout << "Savings Book List: \n";
                for (auto &book : books) {
                    displayInfor(book); // Hiển thị thông tin từng sổ tiết kiệm
                    cout << endl;
                }
                break;
            }

            case 0:
                return 0; // Thoát chương trình

            default:
                cout << "Invalid option! Try again.\n"; // Lựa chọn không hợp lệ
                break;
        }
        cout << endl;
    }
    return 0;
}