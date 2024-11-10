#include "SoPhuc.cpp"

void menu(){
    cout << "\n--------Menu--------\n"
         << "1. Cong hai so phuc\n"
         << "2. Tru hai so phuc\n"
         << "3. Nhan hai so phuc\n"
         << "4. Chia hai so phuc\n"
         << "5. So sanh hai so phuc\n"
         << "0. Thoat\n"
         << "Nhap lua chon: ";
}

int main() {
    SoPhuc sp1, sp2, result;

    int choice;
    while (1) {
        menu();
        cin >> choice;

        cout << "Nhap so phuc thu nhat: ";
        cin >> sp1;
        cout << "Nhap so phuc thu hai: ";
        cin >> sp2;

        switch (choice) {
            case 1:
                result = sp1 + sp2;
                cout << "Ket qua phep cong: " << result << endl;
                break;

            case 2:
                result = sp1 - sp2;
                cout << "Ket qua phep tru: " << result << endl;
                break;

            case 3:
                result = sp1 * sp2;
                cout << "Ket qua phep nhan: " << result << endl;
                break;

            case 4:
                result = sp1 / sp2;
                cout << "Ket qua phep chia: " << result << endl;
                break;

            case 5:
                if (sp1 == sp2) cout << "Hai so phuc bang nhau\n";
                else cout << "Hai so phuc khong bang nhau\n";
                break;

            case 0:
                return 0;

            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    }

    return 0;
}
