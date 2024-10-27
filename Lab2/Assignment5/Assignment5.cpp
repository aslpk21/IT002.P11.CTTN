#include "Diem.cpp"
void showMenu(){
    cout << "\n-----Menu-----\n"
         << "1. Nhan doi tung do va hoanh do\n"
         << "2. Gan diem ve goc toa do\n"
         << "3. Tinh tien\n";
}

int main(){
    cout << "Nhap toa do (a, b) cua diem A: ";
    float a, b;
    cin >> a >> b;
    Diem A(a, b);

    int n;
    cout << "Nhap vao so luong chi thi: ";
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        showMenu();
        cout << "\nNhap vao chi thi: ";
        cin >> x;
        if( x == 1 ){
            A.SetHoanhDo(A.GetHoanhDo() * 2);
            A.SetTungDo(A.GetTungDo() * 2);
        }
        else if( x == 2){
            A.SetHoanhDo(0);
            A.SetTungDo(0);
        }
        else if( x == 3){
            cout << "- k khac 0: tinh tien theo truc y\n"
                 << "- k = 0: tinh tien theo truc x\n"
                 << "Nhap huong tinh tien k: ";
            int k;
            cin >> k;

            cout << "Nhap do tinh tien d: ";
            float d;
            cin >> d;

            if(k == 0){
                A.TinhTien(d, 0);
            }
            else{
                A.TinhTien(0, d);
            }
        }
        else 
            continue;
    }

    cout << "Toa do diem A: " << "(" << A.GetHoanhDo() << ", " << A.GetTungDo() << ")";

    return 0; 
}