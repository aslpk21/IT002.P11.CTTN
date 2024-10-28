#include "List.cpp"

void menu(){
    cout << "\n-----Menu-----\n"
         << "0. Push back x to list\n"
         << "1. Delete first element's value == x\n"
         << "2. Delete all element's value == x\n"
         << "3. Replace arr[x] by y\n"
         << "-1. Display current list and exit\n";
}

int main(){
    List lst;
    while(1){
        int n;
        menu();
        cout << "Enter option: ";
        cin >> n;
        if (n == -1) {
            cout << "Current list: ";
            lst.printL();
            break;
        }

        double x, y;
        switch (n) {
            case 0:
                cout << "Enter value to push back: ";
                cin >> x;
                lst.push_back(x);
                break;
            case 1:
                cout << "Enter value to delete first occurrence: ";
                cin >> x;
                lst.pop_first(x);
                break;
            case 2:
                cout << "Enter value to delete all occurrences: ";
                cin >> x;
                lst.pop_all(x);
                break;
            case 3:
                cout << "Enter position to replace: ";
                cin >> x;
                cout << "Enter new value: ";
                cin >> y;
                lst.replace(x, y);
                break;
            default:
                cout << "Invalid option. Try again.\n";
                break;
        }
    }

    return 0;
}
