#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// Mảng chứa số ngày trong các tháng cho năm nhuận và năm không nhuận
int days[2][12] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

// Cấu trúc dữ liệu lưu trữ thông tin chuyến bay
struct Flight{
    string flightID; // Mã chuyến bay
    int date, month, year; // Ngày, tháng, năm bay
    string flightTime; // Thời gian bay
    string origin; // Nơi khởi hành
    string destination; // Điểm đến
};

// Hàm kiểm tra năm nhuận
bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Hàm kiểm tra mã chuyến bay hợp lệ
bool isValidFlightID(const string &flightID){
    // Mã phải có độ dài từ 1 đến 5 và chỉ chứa ký tự chữ cái hoặc số
    if(flightID.size() == 0 || flightID.size() > 5) return false;
    for(char c : flightID){
        if(!isalpha(c) && !isalnum(c)) return false;
    }
    return true;
}

// Hàm kiểm tra ngày tháng năm hợp lệ
bool isValidDate(int day, int month, int year){
    if (day < 1 || day > days[isLeapYear(year) ? 1 : 0][month - 1]) return false; // Kiểm tra ngày
    if (month < 1 || month > 12) return false; // Kiểm tra tháng 
    if (year < 1) return false; // Kiểm tra năm
    return true;
}

// Hàm kiểm tra thời gian chuyến bay hợp lệ
bool isValidFlightTime(const string &time){
    // Kiểm tra thời gian phải đúng định dạng HH:MM
    return regex_match(time, regex("^(?:[01][0-9]|2[0-3]):[0-5][0-9]$"));
}

// Hàm kiểm tra địa điểm hợp lệ
bool isValidPlace(const string &place){
    // Địa điểm phải từ 1 đến 20 ký tự và chỉ chứa chữ cái hoặc khoảng trắng
    if(place.size() == 0 || place.size() > 20) return false;
    for(char c : place){
        if(!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Hàm nhập thông tin chuyến bay
void inputFlightInfor(Flight &flight){
    // Nhập mã chuyến bay
    do {
        cout << "Enter the flightID: ";
        cin >> flight.flightID;
        if(!isValidFlightID(flight.flightID))
           cout << "Invalid flightID!\n";
    } while(!isValidFlightID(flight.flightID));

    // Nhập ngày tháng năm chuyến bay
    do {
        cout << "Enter the flight date (format DD MM YYYY): ";
        cin >> flight.date >> flight.month >> flight.year;
        if(!isValidDate(flight.date, flight.month, flight.year))
           cout << "Invalid date!\n";
    } while (!isValidDate(flight.date, flight.month, flight.year));

    cin.ignore();

    // Nhập thời gian chuyến bay
    do {
        cout << "Enter the flight time (format HH:MM): ";
        getline(cin, flight.flightTime);
        if(!isValidFlightTime(flight.flightTime))
           cout << "Invalid flight time!\n";
    } while(!isValidFlightTime(flight.flightTime));

    // Nhập địa điểm khởi hành
    do {
        cout << "Enter the flight's origin: ";
        getline(cin, flight.origin);
        if(!isValidPlace(flight.origin))
           cout << "Invalid origin!\n";
    } while (!isValidPlace(flight.origin));

    // Nhập địa điểm đến
    do {
        cout << "Enter the flight's destination: ";
        getline(cin, flight.destination);
        if(!isValidPlace(flight.destination))
           cout << "Invalid destination!\n";
    } while (!isValidPlace(flight.destination));

    cout << endl;
}

// Hàm hiển thị thông tin chuyến bay
void displayFlightInfor(const Flight &flight){
    cout << "--------------------------------\n";
    cout << "Flight ID: " << flight.flightID << endl;
    cout << "Date: " << flight.date << "/" << flight.month << "/" << flight.year << endl;
    cout << "Time: " << flight.flightTime << endl;
    cout << "Origin: " << flight.origin << endl;
    cout << "Destination: " << flight.destination << endl;
}

// Hàm tìm chuyến bay theo mã chuyến bay, nơi khởi hành hoặc nơi đến
vector<Flight> findFlights(const vector<Flight> &flights, const string &searchStr) {
    vector<Flight> results;
    for (const auto &flight : flights) {
        if (flight.flightID == searchStr || flight.origin == searchStr || flight.destination == searchStr) {
            results.push_back(flight);
        }
    }
    return results;
}

// Comparator để so sánh chuyến bay theo thứ tự thời gian từ sớm đến muộn
bool comparator(const Flight &a, const Flight &b) {
    // So sánh năm, tháng, ngày và thời gian
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    if (a.date != b.date) return a.date < b.date;

    int hourA, minuteA, hourB, minuteB;
    sscanf(a.flightTime.c_str(), "%d:%d", &hourA, &minuteA);
    sscanf(b.flightTime.c_str(), "%d:%d", &hourB, &minuteB);

    // So sánh thời gian giờ và phút của chuyến bay
    if (hourA != hourB) return hourA < hourB;
    return minuteA < minuteB;
}

// Hàm sắp xếp danh sách chuyến bay theo thời gian từ sớm đến muộn
void sortFlight(vector<Flight> &flights){
    sort(flights.begin(), flights.end(), comparator);
}

// Hàm hiển thị chuyến bay từ một địa điểm cụ thể vào ngày chỉ định
void displayFlightFromSpecificOrigin(const vector<Flight> &flights, const string &origin, int date, int month, int year){
    vector<Flight> results;
    for (const auto &flight : flights) {
        if (flight.origin == origin && flight.date == date && flight.month == month && flight.year == year) {
            results.push_back(flight);
        }
    }
    if (results.empty()) {
        // Nếu không tìm thấy chuyến bay trùng khớp, in ra thông báo không tìm được chuyến bay
        cout << "No flights found from " << origin << " on " << date << "/" << month << "/" << year << endl;
    } else {
        // Hiển thị danh sách từng chuyến bay tìm được
        cout << "Flights from " << origin << " on " << date << "/" << month << "/" << year << ":\n";
        for (const auto &flight : results) {
            displayFlightInfor(flight);
        }
    }
}

// Hàm đếm số chuyến bay từ một điểm xuât phát tới một điểm đến nhất định
int countFlightFromAtoB(const vector<Flight> &flights, const string &origin, const string &dest) {
    int result = 0;
    for (const auto &flight : flights) {
        if (flight.origin == origin && flight.destination == dest) {
            result++;
        }
    }
    return result;
}

// Hàm hiển thị menu lựa chọn
void showMenu(){
    cout << "Menu: \n"
         << "1. Display flight list \n"
         << "2. Find flight by flight ID or origin/destination \n"
         << "3. Sort flight by time \n"
         << "4. Display all flight from specific origin \n"
         << "5. Count flights from A to B \n"
         << "0. Exit";
}

// Hàm main
int main() {
    int n;
    cout << "Enter the number of flights: ";
    cin >> n;
    vector<Flight> flights(n);
    for(auto &flight : flights) {
        inputFlightInfor(flight); // Nhập thông tin cho từng chuyến bay
    }

    int option;
    while(true) {
        showMenu(); // Hiển thị menu
        cout << "\nChoose an option: ";
        cin >> option;

        switch(option) {
            case 1: 
                // Hiển thị ra danh sách tất cả chuyến bay
                cout << "\nFlight List: \n";
                for (const auto &flight : flights) {
                    displayFlightInfor(flight); // Hiển thị thông tin của từng chuyến bay
                    cout << endl;
                }
                break;

            case 2: { 
                // Tìm chuyến bay theo mã, nơi khởi hành hoặc nơi đến
                string searchStr;
                cout << "Enter flight ID, origin, or destination to search: ";
                // Nhập vào chuỗi tìm kiếm
                cin >> searchStr;
                vector<Flight> foundFlights = findFlights(flights, searchStr);
                if (foundFlights.empty()) {
                    // Nếu không tìm thấy chuyến bay nào trùng khớp thì in ra không tìm được
                    cout << "No flights found for the search term: " << searchStr << endl;
                } else {
                    // Hiển thị danh sách những chuyến bay tìm được
                    cout << "Flights found: \n";
                    for (const auto &flight : foundFlights) {
                        displayFlightInfor(flight); // Hiển thị thông tin từng chuyến bay tìm được
                        cout << endl;
                    }
                }
                break;
            }

            case 3: {
                sortFlight(flights); // Sắp xếp danh sách chuyến bay
                cout << "\nFlights sorted by time: \n";
                for (const auto &flight : flights) {
                    displayFlightInfor(flight); // Hiển thị thông tin của từng chuyến bay đã được sắp xếp
                    cout << endl;
                }
                break;
            }

            case 4: {
                // Hiển thị danh sách những chuyến bay từ 1 nơi khởi hành vào ngày cụ thể
                string origin;
                int date, month, year;
                cout << "Enter origin and date (format DD MM YYYY): ";
                // Nhập vào nơi khởi hành và ngày tháng năm 
                cin >> origin >> date >> month >> year;
                displayFlightFromSpecificOrigin(flights, origin, date, month, year);
                break;
            }

            case 5: {
                // Đếm chuyến bay từ 1 nơi khởi hành tới 1 địa điểm nhất định
                string origin, destination;
                cout << "Enter origin and destination: ";
                // Nhập vào điểm khởi hành và điểm đến
                cin.ignore();
                getline(cin, origin);
                getline(cin, destination);

                // Đếm số chuyến bay từ 1 điểm khởi hành tới 1 điểm dến
                int flightCount = countFlightFromAtoB(flights, origin, destination);
                cout << "Number of flights from " << origin << " to " << destination << ": " << flightCount << endl;
                break;
            }

            case 0:
                break; // Thoát chương trình

            default:
                cout << "Invalid option! Try again\n"; // Lựa chọn không hợp lệ, chọn lại
                break;
        }
        cout << endl;
    }
    return 0;
}
