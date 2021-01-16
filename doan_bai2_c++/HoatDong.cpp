#include "HoatDong.h"

void HoatDong::KhamSucKhoeToanDoi(vector<CauThu*>* list, BacSi* bacsi)
{
    for (int i = 0; i < list->size(); i++)
    {
        CauThu* temp = list->at(i);
        KhamSucKhoeCauThu(temp, bacsi);
        list->at(i) = temp;
    }
}

void HoatDong::KhamSucKhoeCauThu(CauThu*& ct, BacSi* bs)
{
    int a = 0;
    cout << "Cau thu: " << ct->sHoTen;
    bs->Kham(a);
    ct->setiTinhTrangSucKhoe(a);
}

bool compare(CauThu* a, CauThu* b)
{
    return a->getiTinhTrangTheLuc() > b->getiTinhTrangTheLuc();
}

vector<CauThu*>* HoatDong::TuyenChon11CT(vector<CauThu*>* list)
{
    vector<CauThu*>* temp = new vector<CauThu*>();
    cout << "=============================\n";
    cout << " 1: Chon 11 Cau thu co TL tot nhat\n";
    cout << " 2: Tu ban chon\n";
    cout << "Ban muon chon theo cai gi: ";
    int choose; cin >> choose;
    if (list->size() <= 11)
    {
        cout << "Doi <=11 nguoi => Khong the chon Doi !!";
        return list;
    }
    switch (choose)
    {
    case 1:
    {
        sort(list->begin(), list->end(), compare);
        for (int i = 0; i < 11; i++)
            temp->push_back(list->at(i));
        return temp;
    }
    case 2:
    {
        cout << "Day la DS cau thu\n";
        for (auto item : *list)
        {
            cout << " " + item->sHoTen << endl;;
        }
        for (int i = 0; i < 11; i++)
        {
            cout << "Moi chon cau thu thu " << (i + 1) << ": ";
            int x; cin >> x;
            temp->push_back(list->at(x));
        }
        return temp;
    }
    default:
    {
        return temp;
    }
    }
}

void HoatDong::HuanLuyenTLCaDoi(vector<CauThu*>* list, HLVTheLuc* HLV)
{
    for (int i = 0; i < list->size(); i++)
    {
        list->at(i)->setiTinhTrangTheLuc(list->at(i)->getiTinhTrangTheLuc() + HLV->getiChiSoNangCaoTL());
    }
}

void HoatDong::HuanLuyenTL(CauThu*& ct, HLVTheLuc* hlv)
{
    ct->setiTinhTrangTheLuc(ct->getiTinhTrangTheLuc() + hlv->getiChiSoNangCaoTL());
}

void HoatDong::DaGiaoLuu(vector<CauThu*>* listCT, HLVChienThuat* HLV)
{
    cout << "Chon cau thu tham gia thi dau\n";
    vector<CauThu*>* listCT2 = TuyenChon11CT(listCT);
    cout << "Chon chien thuat: ";
    string chienthuat = HLV->ChonChienThuat();
    cout << "Nhap doi thu: ";
    string dt; cin.ignore(); cin >> dt;
    cout << "\t\t\t************************************************\t\t\t" << endl;
    cout << "Doi nha VS " << dt << endl;
    cout << "Danh sach cau thu tham du!\n";
    for (auto item : *listCT2)
    {
        cout << "Cau thu " << item->sHoTen << " so ao: " << item->getiSoAo();
    }
    cout << "Huan luyen vien: " << HLV->sHoTen << " ___ Chien Thuat: " << chienthuat << endl;
    cout << "\t\t\t************************************************\t\t\t" << endl;

}

void HoatDong::createCauThu(vector<CauThu*>*& chuyennhuong)
{
    CauThu* a = new CauThu("nguyen van a", 30000000, "56893457", 1998, 1, 56, 72, "trai", "tienve");
    CauThu* b = new CauThu("nguyen van b", 20000000, "56630787", 2000, 90, 88, 12, "phai", "hauve");
    CauThu* c = new CauThu("nguyen van c", 67000000, "99637457", 1995, 57, 26, 82, "trai", "tiendao");
    CauThu* d = new CauThu("nguyen van d", 100000000, "63019457", 1998, 420, 100, 100, "phai", "tiendao");
    CauThu* e = new CauThu("nguyen van e", 12000000, "56891234", 2005, 1, 36, 22, "phai", "tiendao");
    CauThu* f = new CauThu("nguyen van f", 10000000, "12343457", 2004, 1, 46, 52, "phai", "tienve");
    chuyennhuong->push_back(a); chuyennhuong->push_back(b); chuyennhuong->push_back(c); chuyennhuong->push_back(d); chuyennhuong->push_back(e); chuyennhuong->push_back(f);
}

void HoatDong::ChuyenNhuong(QuanLyCauThu* &ct, vector<CauThu*>*& temp)
{
    cout << "Da den ki chuyen nhuong mua Dong, ban co muon mua them hay ban di cau thu ko? 1_Yes || 2_No" << endl;
    cout << "=> Your choice: "; int choice; cin >> choice;
    if (choice == 1)
    {
        int flag = 1;
        while (flag == 1)
        {
            cout << "\t\t\t************************MENU************************\t\t\t" << endl;
            cout << "\t\t\t***            1. Mua                            ***\t\t\t" << endl;
            cout << "\t\t\t***            2. Ban                            ***\t\t\t" << endl;
            cout << "\t\t\t***            3. Thoat                          ***\t\t\t" << endl;
            cout << "\t\t\t****************************************************\t\t\t" << endl;
            cout << "Moi nhap lua chon cua ban => Your choice: ";
            int choice1; cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                int i = 0;
                for (auto item : *temp)
                {
                    cout << "STT: " << i++ << " Ho ten: " << item->sHoTen << " Luong: " << item->TinhLuong() << endl;
                }
                cout << "Moi nhap STT cau thu muon mua: ";
                int n; cin >> n;
                temp->at(n)->iNgayGiaNhap = 15;
                temp->at(n)->iThangGiaNgap = 1;
                temp->at(n)->iNamGiaNhap = 2021;
                cout << "Ban muon ki hop dong thoi han bao lau: ";  int thoihan; cin >> thoihan;
                temp->at(n)->iThoiGianHopDong = thoihan;
                temp->at(n)->sNghe = "CauThu";
                ct->getvectorCauThu()->push_back(temp->at(n));
                temp->erase(temp->begin() + n);
                cout << "Successfully ~~ " << endl;
                break;
            }
            case 2:
            {
                int i = 0;
                for (auto item : *ct->getvectorCauThu())
                {
                    cout << "STT: " << i++ << " Ho ten: " << item->sHoTen << " Luong: " << item->TinhLuong() << endl;
                }
                cout << "Ban muon ban cau thu so may: "; int stt; cin >> stt;
                ct->xoa1CT(stt);
                cout << "Successfully ~~ " << endl;
                break;
            }
            case 3:
            {
                flag = 0;
                break;
            }
            default:
            {
                cout << "Nhap sai, moi nhap lai!! " << endl;
                break;
            }
            }
        }
    }
}
