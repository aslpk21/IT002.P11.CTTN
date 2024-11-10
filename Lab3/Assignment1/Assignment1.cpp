#include "PhanSo.cpp"

using namespace std;

void menu(){
    cout << "\n--------Menu--------\n"
         << "1. Cong hai phan so\n"
         << "2. Tru hai phan so\n"
         << "3. Nhan hai phan so\n"
         << "4. Chia hai phan so\n"
         << "5. So sanh hai phan so\n"
         << "0. Thoat\n"
         << "Nhap lua chon: ";
}

int main() {
    int choice;
    PhanSo ps1, ps2, result;

    while (1) {
        menu();
        cin >> choice;

        if (choice == 0) {
            cout << "Thoat chuong trinh.\n";
            break;
        }

        cout << "Nhap phan so thu nhat: ";
        cin >> ps1;
        cout << "Nhap phan so thu hai: ";
        cin >> ps2;

        switch (choice) {
            case 1:
                result = ps1 + ps2;
                cout << "Ket qua phep cong: " << result << endl;
                break;
            case 2:
                result = ps1 - ps2;
                cout << "Ket qua phep tru: " << result << endl;
                break;
            case 3:
                result = ps1 * ps2;
                cout << "Ket qua phep nhan: " << result << endl;
                break;
            case 4:
                result = ps1 / ps2;
                if (result.getTu() != 0 || result.getMau() != 1) {
                    cout << "Ket qua: " << result << endl;
                } else {
                    cout << "Khong the chia cho phan so co tu = 0.\n";
                }
                break;
            case 5:
                if (ps1 == ps2) cout << "Hai phan so bang nhau.\n";
                else if (ps1 > ps2) cout << "Phan so thu nhat lon hon phan so thu hai.\n";
                else cout << "Phan so thu nhat nho hon phan so thu hai.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }

    return 0;
}
