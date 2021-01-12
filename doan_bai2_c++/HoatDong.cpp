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
    cout << "Doi nha VS" << dt << endl;
    cout << "Danh sach cau thu tham du!\n";
    for (auto item : *listCT2)
    {
        cout << "Cau thu " << item->sHoTen << " so ao: " << item->getiSoAo();
    }
    cout << "Huan luyen vien: " << HLV->sHoTen << " ___ Chien Thuat: " << chienthuat << endl;
    cout << "\t\t\t************************************************\t\t\t" << endl;

}
