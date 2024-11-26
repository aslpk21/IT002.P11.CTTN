#include"De.h"
#include"Bo.h"
#include"Cuu.h"

void thongKe(vector<GiaSuc*> &nongTrai) {
    int soBo = 0;
    int soCuu = 0;
    int soDe = 0;
    int soSua = 0;

    for (GiaSuc* giaSuc : nongTrai) {
        if (Bo* bo = dynamic_cast<Bo*>(giaSuc)) {
            soBo += bo->getSoLuong();
        }
        else if (Cuu* cuu = dynamic_cast<Cuu*>(giaSuc)) {
            soCuu += cuu->getSoLuong();
        }
        else if (De* de = dynamic_cast<De*>(giaSuc)) {
            soDe += de->getSoLuong();
        }
        soSua += giaSuc->choSua();
    }

    cout << "Tong so luong gia suc: \n";
    cout << "- Bo: " << soBo << " con.\n";
    cout << "- Cuu: " << soCuu << " con.\n";
    cout << "- De: " << soDe << " con.\n";
    cout << "Tong so luong sua thu duoc: " << soSua << " lit.\n";

}

int main() {
	srand(static_cast<unsigned>(time(0)));

	int soBo, soCuu, soDe;
    cout << "Nhap so luong bo: ";
    cin >> soBo;
    cout << "Nhap so luong cuu: ";
    cin >> soCuu;
    cout << "Nhap so luong de: ";
    cin >> soDe;

    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    vector<GiaSuc*> nongTrai = { &bo, &cuu, &de };

    cout << "\nTieng keu cua cac gia suc dang doi: \n";
    for (GiaSuc* giaSuc : nongTrai) {
        giaSuc->phatTiengKeu();
    }

    cout << "\nThong ke sau mot luot sinh con va cho sua:\n\n";
    for (GiaSuc* giaSuc : nongTrai) {
        int soCon = giaSuc->sinhCon();
        cout << "- Loai " << giaSuc->getLoai() << " sinh duoc " << soCon << " con.\n";
    }
    thongKe(nongTrai);

    return 0;
}