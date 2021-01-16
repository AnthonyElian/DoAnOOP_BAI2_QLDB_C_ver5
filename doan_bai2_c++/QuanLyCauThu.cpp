#include "QuanLyCauThu.h"

QuanLyCauThu::QuanLyCauThu()
{
    this->vectorCauThu = new vector<CauThu*>();
}

QuanLyCauThu::QuanLyCauThu(vector<CauThu*>* lcauthu)
{
    this->vectorCauThu = lcauthu;
}

QuanLyCauThu::~QuanLyCauThu()
{
    delete this->vectorCauThu;
}

vector<CauThu*> *QuanLyCauThu::getvectorCauThu()
{
    return this->vectorCauThu;
}

void QuanLyCauThu::setvectorCauThu(vector<CauThu*> *vectorCauThu)
{
    this->vectorCauThu = vectorCauThu;
}

void QuanLyCauThu::Nhap()
{
    cout << "Moi nhap so luong cau thu trong doi bong: ";
    int cauthu;
    cin >> cauthu;
    for (int i = 0; i < cauthu; i++)
    {
        CauThu *a = new CauThu();
        a->Nhap();
        vectorCauThu->push_back(a);
    }
}

void QuanLyCauThu::Xuat()
{
    //this->sort();
    for (auto item : *vectorCauThu)
    {
        item->Xuat();
    }
}

bool compare1( CauThu* a,  CauThu* b)
{
    return a->sHoTen < b->sHoTen;
}

bool compare2(CauThu* a, CauThu* b)
{
    return a->TinhTuoi() < b->TinhTuoi();
}

bool compare3(CauThu* a, CauThu* b)
{
    return a->iThoiGianHopDong < b->iThoiGianHopDong;
}

bool compare4(CauThu* a, CauThu* b)
{
    return a->ThoiGianHopDongConLai() < b->ThoiGianHopDongConLai();
}

bool compare5(CauThu* a, CauThu* b)
{
    return a->getiSoAo() < b->getiSoAo();
}

bool compare6(CauThu* a, CauThu* b)
{
    return a->getiTinhTrangTheLuc() < b->getiTinhTrangTheLuc();
}

bool compare7(CauThu* a, CauThu* b)
{
    return a->getiTinhTrangSucKhoe() < b->getiTinhTrangSucKhoe();
}

void QuanLyCauThu::Sort()
{
    cout << "\t\t\t************************MENU************************\t\t\t" << endl;
    cout << "\t\t\t***              1. Ho ten                       ***\t\t\t" << endl;
    cout << "\t\t\t***              2. Tuoi                         ***\t\t\t" << endl;
    cout << "\t\t\t***              3. Ngay gia nhap                ***\t\t\t" << endl;
    cout << "\t\t\t***              4. Thoi han hop dong con lai    ***\t\t\t" << endl;
    cout << "\t\t\t***              5. So ao                        ***\t\t\t" << endl;
    cout << "\t\t\t***              6. TT the luc                   ***\t\t\t" << endl;
    cout << "\t\t\t***              7. TT Suc Khoe                  ***\t\t\t" << endl;
    cout << "\t\t\t***              8. Thoat                        ***\t\t\t" << endl;
    cout << "\t\t\t****************************************************\t\t\t" << endl;
    cout << "Moi nhap lua chon cua ba => Your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare1);
        break;
    }
    case 2:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare2);
        break;
    }
    case 3:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare3);
        break;
    }
    case 4:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare4);
        break;
    }
    case 5:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare5);
        break;
    }
    case 6:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare6);
        break;
    }
    case 7:
    {
        sort(this->vectorCauThu->begin(), this->vectorCauThu->end(), compare6);
        break;
    }
    case 8:
        break;
    default:
        cout << "Nhap sai, moi nhap lai!!  \n";
        break;
    }
}

vector<CauThu*>* QuanLyCauThu::Loc()
{
    vector<CauThu*> *temp = new vector<CauThu*>();
    cout << "\t\t\t************************MENU************************\t\t\t" << endl;
    cout << "\t\t\t***       1. Danh sach cau thu thuan chan trai   ***\t\t\t" << endl;
    cout << "\t\t\t***       2. Danh sach cau thu thuan chan phai   ***\t\t\t" << endl;
    cout << "\t\t\t***       3. Danh sach cau thu co the da tien dao***\t\t\t" << endl;
    cout << "\t\t\t***       4. Danh sach cau thu co the da tien ve ***\t\t\t" << endl;
    cout << "\t\t\t***       5. Danh sach cau thu co the da hau ve  ***\t\t\t" << endl;
    cout << "\t\t\t***       6. Thoat                               ***\t\t\t" << endl;
    cout << "\t\t\t****************************************************\t\t\t" << endl;
    cout << "Moi nhap lua chon cua ba => Your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        for (auto item : *vectorCauThu)
            if (item->getsChanThuan() == "trai")
                temp->push_back(item);
        return temp;
    }
    case 2:
    {
        for (auto item : *vectorCauThu)
            if (item->getsChanThuan() == "phai")
                temp->push_back(item);
        return temp;
    }
    case 3:
    {
        for (auto item : *vectorCauThu)
            if (item->getsViTriDaChinh() == "tiendao")
                temp->push_back(item);
        return temp;
    }
    case 4:
    {
        for (auto item : *vectorCauThu)
            if (item->getsViTriDaChinh() == "tienve")
                temp->push_back(item);
        return temp;
    }
    case 5:
    {
        for (auto item : *vectorCauThu)
            if (item->getsViTriDaChinh() == "hauve")
                temp->push_back(item);
        return temp;
    }
    case 6:
    {
        return temp;
    }
    default:
    {
        cout << "Nhap sai, moi nhap lai!!  " << endl;
        return temp;
    }
    }
    return temp;
}

vector<CauThu*>* QuanLyCauThu::Search()
{
    cout << "\t\t\t************************MENU************************\t\t\t" << endl;
    cout << "\t\t\t***            1. Ho ten                         ***\t\t\t" << endl;
    cout << "\t\t\t***            2. So ao                          ***\t\t\t" << endl;
    cout << "\t\t\t***            3. Thoat                          ***\t\t\t" << endl;
    cout << "\t\t\t****************************************************\t\t\t" << endl;
    cout << ("Moi nhap lua chon cua ban => Your choice: ");
    int choice;
    cin >> choice;
    vector<CauThu*>* temp = new vector<CauThu*>();
    switch (choice)
    {
    case 1:
    {
        cout << "Moi nhap Ho Ten muon tim kiem: ";
        string key;
        cin >> key;
        for (auto object : *vectorCauThu)
        {
            if (object->sHoTen == key)
            {
                temp->push_back(object);
            }
        }
        return temp;
    }
    case 2:
    {
        int soao;
        cout << "Moi nhap So Ao muon tim kiem: ";
        cin >> soao;
        for (auto item : *vectorCauThu)
        {
            if (item->getiSoAo() == soao)
            {
                temp->push_back(item);
            }
        }
        return temp;
    }
    case 3:
    {
        //CauThu* temp = &vectorCauThu->front();
        return temp;
    }
    default:
    {
        //CauThu* temp = &vectorCauThu->front();
        cout << "Nhap sai, moi nhap lai!! ";
        //temp = nullptr;
        return temp;
    }
    }
}

void QuanLyCauThu::XemTinhTrangTheLuc()
{
    cout << "Xem tinh trang The Luc cac Cau Thu trong Doi Bong" << endl;
    for (auto a : *vectorCauThu)
    {
        cout << "Cau Thu: " << a->sHoTen << " chi so The Luc la: " << a->getiTinhTrangTheLuc() << endl;
    }
}

void QuanLyCauThu::XemTinhTrangSucKhoe()
{
    cout << "Xem tinh trang Suc Khoe cac Cau Thu trong Doi Bong" << endl;
    for (auto a : *vectorCauThu)
    {
        cout << "Cau Thu: " << a->sHoTen << " chi so Suc Khoe la: " << a->getiTinhTrangSucKhoe() << endl;
    }
}

CauThu* QuanLyCauThu::CauThuCoTheLucTotNhat()
{
    if (vectorCauThu->size() == 0)
        return nullptr;
    else
    {
        CauThu* temp = this->vectorCauThu->at(0);
        for (auto item : *vectorCauThu)
        {
            if (item->operator>(temp))
                temp = item;
        }
        return temp;
    }
}

CauThu* QuanLyCauThu::CauThuCoSucKhoeYeuNhat()
{
    if (vectorCauThu->size() == 0)
        return nullptr;
    else
    {
        CauThu* temp = vectorCauThu->at(0);
        for (auto item : *vectorCauThu)
        {
            if (item->operator<(temp))
                temp = item;
        }
        return temp;
    }
}

double QuanLyCauThu::TongLuongToanCauThu()
{
    double temp=0;
    for (auto object : *vectorCauThu)
    {
        temp = object->operator+(temp);
    }
    return temp;
}

void QuanLyCauThu::xoaCT()
{
    cout << "So luong cau thu hien tai la: " << this->vectorCauThu->size() << endl;
    cout << "Ban muon xoa bao nhieu cau thu: ";
    int n, dem = 0; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Danh sach cau thu: " << endl;
        for (auto item : *this->vectorCauThu)
        {
            cout << "STT: " << dem << " Ho ten: " << item->sHoTen << endl;
            dem++;
        }
        cout << "Nhap thu tu cau thu muon xoa: ";
        int x; cin >> x;
        this->xoa1CT(x);
    }
}

void QuanLyCauThu::xoa1CT(int x)
{
    this->vectorCauThu->erase(this->vectorCauThu->begin() + x);
}





