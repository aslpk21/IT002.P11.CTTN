#include <bits/stdc++.h>

using namespace std;

// Cấu trúc dữ liệu để lưu trữ thông tin học sinh
struct Student {
    string Name;        // Tên học sinh
    float mathScore;    // Điểm môn Toán
    float literScore;   // Điểm môn Ngữ Văn
    float englishScore; // Điểm môn Tiếng Anh
    float Gpa;          // Điểm trung bình (GPA)
    string classification; // Phân loại học sinh dựa trên GPA
};

// Hàm kiểm tra tên hợp lệ
// Đầu vào: tên học sinh
// Đầu ra: true nếu tên hợp lệ, false nếu không hợp lệ
bool isValidName(const string &name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;  // Tên chỉ được chứa chữ cái và khoảng trắng
        }
    }
    return true;
}

// Hàm kiểm tra điểm hợp lệ
// Đầu vào: điểm của học sinh
// Đầu ra: true nếu điểm hợp lệ (trong khoảng 0-10), false nếu không hợp lệ
bool isValidScore(const float &score) {
    return (score >= 0 && score <= 10);
}

// Hàm nhập điểm cho một môn học
// Đầu vào: tên môn học
// Đầu ra: điểm số hợp lệ được gán cho điểm số môn học tương ứng của học sinh
float inputScore(const string &subject) {
    float score;
    do {
        cout << "Enter score for " << subject << " (0 - 10): ";
        cin >> score;
        if (!isValidScore(score)) {
            cout << "Score must be between 0 and 10. Please try again.\n";
        }
    } while (!isValidScore(score)); // Lặp lại cho đến khi nhập điểm hợp lệ
    return score;
}

// Hàm tính GPA dựa trên điểm số các môn
// Đầu vào: điểm môn Toán, Ngữ Văn, và Tiếng Anh
// Đầu ra: Điểm trung bình GPA của học sinh
float calcGpa(float mathScore, float literatureScore, float englishScore) {
    return (2 * mathScore + literatureScore + englishScore) / 4; // Công thức tính GPA
}

// Hàm phân loại học sinh dựa trên điểm trung bình
// Đầu vào: điểm trung bình của học sinh
// Đầu ra: phân loại được gán vào thông tin học sinh
string classifyStudent(float averageScore) {
    if (averageScore >= 9) return "Excellent";
    if (averageScore >= 8) return "Very Good";
    if (averageScore >= 6.5) return "Good";
    if (averageScore >= 5) return "Average";
    return "Weak";
}

// Hàm nhập thông tin của một học sinh
// Đầu ra: học sinh với đầy đủ thông tin hợp lệ
Student inputStudent() {
    Student student;
    cout << "\n";
    do {
        cout << "Enter student's fullname: ";
        cin.ignore();
        getline(cin, student.Name); // Nhập tên học sinh
        if (!isValidName(student.Name)) {
            cout << "Invalid name! Try again.\n"; // Kiểm tra tính hợp lệ
        }
    } while (!isValidName(student.Name));

    // Nhập điểm cho từng môn học
    student.mathScore = inputScore("Math");
    student.literScore = inputScore("Literature");
    student.englishScore = inputScore("English");
    cout << "\n";

    // Tính GPA và phân loại học sinh
    student.Gpa = calcGpa(student.mathScore, student.literScore, student.englishScore);
    student.classification = classifyStudent(student.Gpa);

    return student; // Trả về thông tin học sinh
}   

// Hàm hiển thị thông tin của một học sinh
// Đầu vào: thông tin học sinh và số thứ tự học sinh
// Đầu ra: In ra màn hình thông tin đầy đủ của học sinh
void displayStudent(const Student &student, int index) {
    cout << index + 1 << ".\n"; // In số thứ tự
    cout << "Full name: " << student.Name << "\n";
    cout << "Math score: " << student.mathScore << "\n";
    cout << "Literature score: " << student.literScore << "\n";
    cout << "English score: " << student.englishScore << "\n";
    cout << "GPA: " << fixed << setprecision(2) << student.Gpa << "\n";
    cout << "Classification: " << student.classification << "\n";
    cout << "----------------------------------------------------\n";
}

// Hàm tìm học sinh có GPA cao nhất
// Đầu vào: danh sách học sinh
// Đầu ra: học sinh có GPA cao nhất
Student findHighestScore(const vector<Student> &students) {
    Student highestStudent = students[0]; // Giả định học sinh đầu tiên có GPA cao nhất
    for (const auto student : students) {
        if (student.Gpa > highestStudent.Gpa) {
            highestStudent = student; // Cập nhật nếu tìm thấy học sinh có GPA cao hơn
        }
    }
    return highestStudent; // Trả về học sinh có GPA cao nhất
}

// Hàm tìm học sinh theo tên
// Đầu vào: danh sách học sinh và tên cần tìm
// Đầu ra: In ra màn hình các kết quả tìm kiếm khả thi
void searchStudentByName(const vector<Student> &students, const string &searchName) {
    bool found = false;
    string lowerSearchName = searchName;  
    transform(lowerSearchName.begin(), lowerSearchName.end(), lowerSearchName.begin(), ::tolower); // Chuyển tên tìm kiếm thành chữ thường

    cout << "----------------------------------------------------\n";
    cout << "Search results for \"" << searchName << "\":\n";
    
    for (size_t i = 0; i < students.size(); ++i) {
        const Student &student = students[i];
        string studentName = student.Name;
        string lowerStudentName = studentName; 
        transform(lowerStudentName.begin(), lowerStudentName.end(), lowerStudentName.begin(), ::tolower); // Chuyển tên học sinh thành chữ thường
        
        if (lowerStudentName.find(lowerSearchName) != string::npos) {
            displayStudent(student, i); // Hiển thị thông tin học sinh tìm được
            found = true;
        }
    }
    
    if (!found) {
        cout << "Can't find any student by that name!\n"; // Thông báo không tìm thấy
    }
}

// Hàm tìm học sinh có điểm Toán thấp nhất
// Đầu vào: danh sách học sinh
// Đầu ra: In ra màn hình danh sách học sinh với điểm toán thấp nhất
void findLowestMathScoreStudents(const vector<Student> &students) {
    float lowestMathScore = students[0].mathScore; // Giả định điểm Toán của học sinh đầu tiên là thấp nhất
    vector<Student> resultList;

    for (const auto &student : students) {
        if (student.mathScore < lowestMathScore) {
            lowestMathScore = student.mathScore; // Cập nhật nếu tìm thấy điểm Toán thấp hơn
        }
    }

    for (const auto &student : students) {
        if (student.mathScore == lowestMathScore) {
            resultList.push_back(student); // Lưu học sinh có điểm Toán thấp nhất
        }
    }

    cout << "----------------------------------------------------\n";
    cout << "Students with the lowest Math score:\n";
    for (int i = 0; i < resultList.size(); ++i) {
        displayStudent(resultList[i], i); // Hiển thị thông tin của học sinh có điểm Toán thấp nhất
    }
}

// Hàm hiển thị tất cả học sinh
// In ra thông tin của tất cả học sinh hiện có trong danh sách
void displayAllStudents(const vector<Student> &students) {
    cout << "----------------------------------------------------\n";
    cout << "List of all Students: \n";
    for (size_t i = 0; i < students.size(); ++i) {
        displayStudent(students[i], i); // Hiển thị thông tin của tất cả học sinh
    }
}

// Hàm hiển thị menu
// In ra màn hình menu để người dùng lựa chọn
void displayMenu() {
    cout << "----------------------------------------------------\n";
    cout << "Menu:\n";
    cout << "1. Display student with highest GPA\n";
    cout << "2. Search for a student by name\n";
    cout << "3. Display students with the lowest math score\n";
    cout << "4. Display all students\n";
    cout << "5. Exit\n";
    cout << "----------------------------------------------------\n";
    cout << "Choose an option: ";
}

// Hàm main
int main() {
    vector<Student> students; // Danh sách học sinh
    
    int n;
    do {
        cout << "Enter the number of Students: ";
        cin >> n; // Nhập số lượng học sinh
        if(n <= 0) cout << "Invalid number of Students!";
    } while (n <= 0); 
    // Báo lỗi nếu nhập vào số lượng học sinh không hợp lệ và nhập lại 
    
    students.resize(n);
    for (auto &student : students) {
        student = inputStudent(); // Nhập thông tin cho từng học sinh
    }

    int choice;
    do {
        displayMenu(); // Hiển thị menu
        cin >> choice; // Nhập lựa chọn của người dùng
        cout << "\n\n";
        switch (choice) {
            case 1: {
                Student highestStudent = findHighestScore(students); // Tìm học sinh có GPA cao nhất
                cout << "----------------------------------------------------\n";
                cout << "Student with highest GPA:\n";
                displayStudent(highestStudent, 1); // Hiển thị GPA của học sinh đó
                break;
            }
            case 2: {
                string searchName;
                cout << "----------------------------------------------------\n";
                cout << "Enter the name of the student to search: ";
                cin.ignore();
                getline(cin, searchName); // Nhập tên cần tìm
                searchStudentByName(students, searchName); // Hiển thị thông tin học sinh tìm được
                break;
            }
            case 3: {
                findLowestMathScoreStudents(students); // Hiển thị danh sách học sinh có điểm Toán thấp nhất
                break;
            }
            case 4: {
                displayAllStudents(students); // Hiển thị thông tin tất cả học sinh 
                break;
            }
            case 5:
                break; // Kết thúc chương trình
            default:
                cout << "Invalid choice! Please try again.\n"; // Thông báo lựa chọn không hợp lệ
        }
    } while (choice != 5); // Tiếp tục cho đến khi người dùng chọn thoát

    return 0;
}
