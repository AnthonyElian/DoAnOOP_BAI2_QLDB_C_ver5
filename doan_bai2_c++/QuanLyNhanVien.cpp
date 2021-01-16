#include "QuanLyNhanVien.h"
vector<CaNhan*>* QuanLyNhanVien::getlCaNhan()
{
    return this->lCaNhan;
}

void QuanLyNhanVien::setlCaNhan(vector<CaNhan*>* lcanhan)
{
    this->lCaNhan = lcanhan;
}

vector<BacSi*>* QuanLyNhanVien::getlBacSi()
{
    return this->lBacSi;
}

void QuanLyNhanVien::setlBacSi(vector<BacSi*>* lbacsi)
{
    this->lBacSi = lbacsi;
}

vector<HLVChienThuat*>* QuanLyNhanVien::getlHLVCT()
{
    return this->lHLVCT;
}

void QuanLyNhanVien::setlHlVCT(vector<HLVChienThuat*>* lhlvct)
{
    this->lHLVCT = lhlvct;
}

vector<HLVTheLuc*>* QuanLyNhanVien::getlHLVTL()
{
    return this->lHLVTL;
}

void QuanLyNhanVien::setlHLVTL(vector<HLVTheLuc*>* lhlvtl)
{
    this->lHLVTL = lhlvtl;
}

vector<NVBaoVe*>* QuanLyNhanVien::getlNVBV()
{
    return this->lNVBV;
}

void QuanLyNhanVien::setlNVBV(vector<NVBaoVe*>* lnvbv)
{
    this->lNVBV = lnvbv;
}

vector<NVVeSinh*>* QuanLyNhanVien::getlNVVS()
{
    return this->lNVVS;
}

void QuanLyNhanVien::setlNVVS(vector<NVVeSinh*>* lnvvs)
{
    this->lNVVS = lnvvs;
}

QuanLyNhanVien::QuanLyNhanVien()
{
    this->lCaNhan = new vector<CaNhan*>();
    this->lBacSi = new vector<BacSi*>();
    this->lHLVCT = new vector<HLVChienThuat*>();
    this->lHLVTL = new vector<HLVTheLuc*>();
    this->lNVBV = new vector<NVBaoVe*>();
    this->lNVVS = new vector<NVVeSinh*>();
}

QuanLyNhanVien::QuanLyNhanVien(vector<CaNhan*>* lcanhan, vector<BacSi*>* lbacsi, vector<HLVChienThuat*>* lhlvct, vector<HLVTheLuc*>* lhlvtl, vector<NVBaoVe*>* lnvbv, vector<NVVeSinh*>* lnvvs)
{
    this->lCaNhan = lcanhan;
    this->lBacSi = lbacsi;
    this->lHLVCT = lhlvct;
    this->lHLVTL = lhlvtl;
    this->lNVBV = lnvbv;
    this->lNVVS = lnvvs;
}

QuanLyNhanVien::~QuanLyNhanVien()
{
    delete this->lCaNhan;
    delete this->lBacSi;
    delete this->lHLVCT;
    delete this->lHLVTL;
    delete this->lNVBV;
    delete this->lNVVS;
}

void QuanLyNhanVien::Nhap()
{
    cout << "Moi nhap so luong Bac Si: ";
    int bs; cin >> bs;
    for (int i = 0; i < bs; i++)
    {
        BacSi *a = new BacSi();
        a->Nhap();
        lCaNhan->push_back(a);
        lBacSi->push_back(a);
    }

    cout << "Moi nhap so luong HLV Chien Thuat: ";
    int hlvct; cin >> hlvct;
    for (int i = 0; i < hlvct; i++)
    {
        HLVChienThuat* a = new HLVChienThuat();
        a->Nhap();
        this->lCaNhan->push_back(a);
        this->lHLVCT->push_back(a);
    }

    cout << "Moi nhap so luong HLV The Luc: ";
    int hlvtl; cin >> hlvtl;
    for (int i = 0; i < hlvtl; i++)
    {
        HLVTheLuc* a = new HLVTheLuc();
        a->Nhap();
        this->lCaNhan->push_back(a);
        this->lHLVTL->push_back(a);
    }

    cout << "Moi nhap so luong NV Bao Ve: ";
    int nvbv; cin >> nvbv;
    for (int i = 0; i < nvbv; i++)
    {
        NVBaoVe* a = new NVBaoVe();
        a->Nhap();
        this->lCaNhan->push_back(a);
        this->lNVBV->push_back(a);
    }

    cout << "Moi nhap so luong NV Ve Sinh: ";
    int nvvs; cin >> nvvs;
    for (int i = 0; i < nvvs; i++)
    {
        NVVeSinh* a = new NVVeSinh();
        a->Nhap();
        this->lCaNhan->push_back(a);
        this->lNVVS->push_back(a);
    }
}

double QuanLyNhanVien::TinhLuongToanBoNV()
{
    double temp = 0;
    for (auto item : *this->lBacSi)
    {
        temp=item->operator+(temp);
    }

    for (auto item : *lHLVCT)
    {
        temp=item->operator+(temp);
    }

    for (auto item : *lHLVTL)
    {
        temp=item->operator+(temp);
    }

    for (auto item : *lNVBV)
    {
        temp=item->operator+(temp);
    }

    for (auto item : *lNVVS)
    {
        temp=item->operator+(temp);
    }

    return temp;
}

bool compare(CaNhan *a, CaNhan *b)
{
    return a->TinhLuong() < b->TinhLuong();
}

void QuanLyNhanVien::Sort()
{
    std::sort(this->lCaNhan->begin(), this->lCaNhan->end(), compare);
}

void QuanLyNhanVien::XuatDSBacSi()
{
    if (this->lBacSi->size() == 0)
        cout << "Khong co Bac Si nao!\n";
    else
    {
        for (auto item : *this->lBacSi)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

BacSi* QuanLyNhanVien::ChonBacSi()
{
    this->XuatDSBacSi();
    if (this->lBacSi->size() != 0)
    {
        cout << "Ban muon chon bac si so may: ";
        int key; cin >> key;
        int dem = 0;
        for (auto item : *lBacSi)
        {
            dem++;
            if (dem == key)
            {
                return item;
            }
        }
    }
    return nullptr;
}

void QuanLyNhanVien::XuatDSHLVCT()
{
    if (this->lHLVCT->size() == 0)
        cout << "Khong co HLV Chien Thuat nao!\n";
    else
    {
        for (auto item : *this->lHLVCT)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

HLVChienThuat* QuanLyNhanVien::ChonHLVCT()
{
    this->XuatDSHLVCT();
    if (this->lHLVCT->size() != 0)
    {
        cout << "Ban muon chon hlv chien thuat so may: ";
        int key; cin >> key;
        int dem = 0;
        for (auto item : *this->lHLVCT)
        {
            dem++;
            if (dem == key)
            {
                return item;
            }
        }
    }
    return nullptr;
}

void QuanLyNhanVien::XuatDSHLVTL()
{
    if (this->lHLVTL->size() == 0)
        cout << "Khong Co HLV The Luc nao\n";
    else
    {
        for (auto item : *this->lHLVTL)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

HLVTheLuc* QuanLyNhanVien::ChonHLVTL()
{
    this->XuatDSHLVTL();
    if (this->lHLVTL->size() == 0)
    {
        cout << "Ban muon chon hlv the luc so may: ";
        int key; cin >> key;
        int dem = 0;
        for (auto item : *this->lHLVTL)
        {
            dem++;
            if (dem == key)
            {
                return item;
            }
        }
    }
    return nullptr;
}

void QuanLyNhanVien::XuatDSNVBV()
{
    if (this->lNVBV->size() == 0)
    {
        cout << "Khong co Nhan Vien Bao Ve nao!\n";
    }
    else
    {
        for (auto item : *this->lNVBV)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

void QuanLyNhanVien::XuatDSNVVS()
{
    if (this->lNVVS->size() == 0)
        cout << "Khong co Nhan Vien Ve Sinh nao!\n";
    else
    {
        for (auto item : *this->lNVVS)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

void QuanLyNhanVien::Xuat()
{
    if (this->lCaNhan->size() == 0)
        cout << "Khong co Nhan Vien nao!\n";
    else
    {
        for (auto item : *this->lCaNhan)
        {
            cout << "Ten: " << item->sHoTen << " ___ Chuc Vu: " << item->sNghe << endl;
        }
    }
}

CaNhan* QuanLyNhanVien::Search()
{
    cout << "Nhap ten Nhan Vien muon tim kiem: ";
    string key;
    cin.ignore();
    cin >> key;
    for (auto item : *this->lCaNhan)
    {
        if (item->sHoTen == key)
            return item;
    }
    return nullptr;
}

vector<CaNhan*>* QuanLyNhanVien::Loc()
{
    cout << "\t\t\t************************MENU************************\t\t\t" << endl;
    cout << "\t\t\t***            1. Loc theo Luong > x             ***\t\t\t" << endl;
    cout << "\t\t\t***            2. Loc theo Luong < x             ***\t\t\t" << endl;
    cout << "\t\t\t***            3. Thoat                          ***\t\t\t" << endl;
    cout << "\t\t\t****************************************************\t\t\t" << endl;
    cout << "Moi nhap lua chon cua ban => Your choice: ";
    int choice; cin >> choice;
    vector<CaNhan*>* temp = new vector<CaNhan*>();
    switch (choice)
    {
    case 1:
    {
        return LocTheoLuongLon();
    }
    case 2:
    {
        return LocTheoLuongBe();
    }
    case 3:
    {
        return temp;
    }
    default:
    {
        cout << "Nhap sai, moi nhap lai!!\n ";
        return temp;
    }
    }
}

vector<CaNhan*>* QuanLyNhanVien::LocTheoLuongLon()
{
    cout << "Nhap Luong (x) de co danh sach cau thu luong > x: ";
    double x; cin >> x;

    vector<CaNhan*> *temp = new vector<CaNhan*>();
    for (auto item : *this->lCaNhan)
        if (item->dLuongCoBan > x)
            temp->push_back(item);
    return temp;
}

vector<CaNhan*>* QuanLyNhanVien::LocTheoLuongBe()
{
    cout << "Nhap Luong (x) de co danh sach cau thu luong < x: ";
    double x; cin >> x;

    vector<CaNhan*>* temp = new vector<CaNhan*>();
    for (auto item : *this->lCaNhan)
        if (item->dLuongCoBan < x)
            temp->push_back(item);
    return temp;
}

void QuanLyNhanVien::XemCaNhan()
{
    this->Xuat();
    cout << "Ban muon xem thong tin Nhan Vien thu may: ";
    int key; cin >> key;
    //vector<CaNhan*>::iterator pos = this->lCaNhan->begin();
    if (key <= this->lCaNhan->size() - 1)
    {
        if (this->lCaNhan->at(key)->sNghe == "bacsi")
        {
            for (int i = 0; i < this->lBacSi->size(); i++)
            {
                if (this->lBacSi->at(i)->sHoTen == this->lCaNhan->at(key)->sHoTen)
                    this->lBacSi->at(i)->Xuat();
            }
        }
        else if (this->lCaNhan->at(key)->sNghe == "HLVCT")
        {
            for (int i = 0; i < this->lHLVCT->size(); i++)
            {
                if (this->lHLVCT->at(i)->sHoTen == this->lCaNhan->at(key)->sHoTen)
                    this->lHLVCT->at(i)->Xuat();
            }
        }
        else if (this->lCaNhan->at(key)->sNghe == "HLVTL")
        {
            for (int i = 0; i < this->lHLVTL->size(); i++)
            {
                if (this->lHLVTL->at(i)->sHoTen == this->lCaNhan->at(key)->sHoTen)
                    this->lHLVTL->at(i)->Xuat();
            }
        }
        else if (this->lCaNhan->at(key)->sNghe == "NVBaoVe")
        {
            for (int i = 0; i < this->lNVBV->size(); i++)
            {
                if (this->lNVBV->at(i)->sHoTen == this->lCaNhan->at(key)->sHoTen)
                    this->lNVBV->at(i)->Xuat();
            }
        }
        else if (this->lCaNhan->at(key)->sNghe == "NVVeSinh")
        {
            for (int i = 0; i < this->lNVVS->size(); i++)
            {
                if (this->lNVVS->at(i)->sHoTen == this->lCaNhan->at(key)->sHoTen)
                    this->lNVVS->at(i)->Xuat();
            }
        }
    }
    else
        cout << "Input sai vui long kiem tra lai!!" << endl;
}

void QuanLyNhanVien::xoaNV()
{
    cout << "So luong nhan vien hien tai la: " << this->lCaNhan->size() << endl;
    cout << "Ban muon xoa bao nhieu nhan vien: ";
    int n, dem = 0; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Danh sach nhan vien:" << endl;
        for (auto item : *this->lCaNhan)
        {
            cout << "STT: " << dem << " Ho ten: " << item->sHoTen << " Chuc Vu: " << item->sNghe << endl;
            dem++;
        }
        cout << "Nhap thu tu nhan vien muon xoa: ";
        int x; cin >> x;
        this->xoa1NV(x);
    }
}

void QuanLyNhanVien::xoa1NV(int x)
{
    CaNhan* temp = this->lCaNhan->at(x);
    if (temp->sNghe == "bacsi")
    {
        int i = 0;
        for (i; i < this->lBacSi->size(); i++)
        {
            if (this->lBacSi->at(i)->sHoTen == temp->sHoTen)
                break;
        }
        this->lBacSi->erase(this->lBacSi->begin() + i);
    }
    if (temp->sNghe == "HLVCT")
    {
        int i = 0;
        for (i; i < this->lHLVCT->size(); i++)
        {
            if (this->lHLVCT->at(i)->sHoTen == temp->sHoTen)
                break;
        }
        this->lHLVCT->erase(this->lHLVCT->begin() + i);
    }
    if (temp->sNghe == "HLVTL")
    {
        int i = 0;
        for (i; i < this->lHLVTL->size(); i++)
        {
            if (this->lHLVTL->at(i)->sHoTen == temp->sHoTen)
                break;
        }
        this->lHLVTL->erase(this->lHLVTL->begin() + i);
    }
    if (temp->sNghe == "NVBaoVe")
    {
        int i = 0;
        for (i; i < this->lNVBV->size(); i++)
        {
            if (this->lNVBV->at(i)->sHoTen == temp->sHoTen)
                break;
        }
        this->lNVBV->erase(this->lNVBV->begin() + i);
    }
    if (temp->sNghe == "NVVeSinh")
    {
        int i = 0;
        for (i; i < this->lNVVS->size(); i++)
        {
            if (this->lNVVS->at(i)->sHoTen == temp->sHoTen)
                break;
        }
        this->lNVVS->erase(this->lNVVS->begin() + i);
    }
    this->lCaNhan->erase(this->lCaNhan->begin() + x);
}


