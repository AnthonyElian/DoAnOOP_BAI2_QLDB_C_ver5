#include "DoiBong.h"

string DoiBong::getsTenDoiBong()
{
    return this->sTenDoiBong;
}

void DoiBong::setsTenDoiBong(string ten)
{
    this->sTenDoiBong = ten;
}

string DoiBong::getsTenNhaTaiTro()
{
    return this->sTenNhaTaiTro;
}

void DoiBong::setsTenNhaTaiTro(string ten)
{
    this->sTenNhaTaiTro = ten;
}

QuanLyCauThu* DoiBong::getQuanLyCauThu()
{
    return this->lCauThu;
}

void DoiBong::setQuanLyCauThu(QuanLyCauThu* a)
{
    this->lCauThu = a;
}

QuanLyNhanVien* DoiBong::getQuanLyNhanVien()
{
    return this->lNhanVien;
}

void DoiBong::setQuanLyNhanVien(QuanLyNhanVien* a)
{
    this->lNhanVien = a;
}

DoiBong::DoiBong()
{
    this->lCauThu = new QuanLyCauThu();
    this->lNhanVien = new QuanLyNhanVien();
}

DoiBong::DoiBong(string tendoi, string tennhataitro)
{
    this->sTenDoiBong = tendoi;
    this->sTenNhaTaiTro = tennhataitro;
}

DoiBong::~DoiBong()
{
    delete this->lCauThu;
    delete this->lNhanVien;
}

void DoiBong::Nhap()
{
    cout << "Moi nhap ten Doi Bong: ";
    cin.ignore();
    getline(cin, this->sTenDoiBong);

    cout << "Moi nhap ten Nha Tai Tro: ";
    cin.ignore();
    getline(cin, this->sTenNhaTaiTro);
}

void DoiBong::Xuat()
{
    cout << "Ten Doi Bong la: " << this->sTenDoiBong << endl;
    cout << "Nha Tai Tro la: " << this->sTenNhaTaiTro << endl;
}

void DoiBong::MenuQLCT()
{
    int flag = 1;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***      0. Nhap cau thu                         ***\t\t\t" << endl;
        cout << "\t\t\t***      1. Sap xep Cau Thu                      ***\t\t\t" << endl;
        cout << "\t\t\t***      2. Loc Cau Thu                          ***\t\t\t" << endl;
        cout << "\t\t\t***      3. Tim Kiem Cau Thu                     ***\t\t\t" << endl;
        cout << "\t\t\t***      4. Xem Tinh Trang The Luc cua Cau Thu   ***\t\t\t" << endl;
        cout << "\t\t\t***      5. Xem Tinh Trang Suc Khoe cua Cau Thu  ***\t\t\t" << endl;
        cout << "\t\t\t***      6. Cau Thu co The Luc Tot Nhat          ***\t\t\t" << endl;
        cout << "\t\t\t***      7. Cau Thu co Suc Khoe Yeu Nhat         ***\t\t\t" << endl;
        cout << "\t\t\t***      8. Tong Luong Cau Thu                   ***\t\t\t" << endl;
        cout << "\t\t\t***      9. Thoat                                ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************\t\t\t" << endl;
        cout << "Moi nhap lua chon cua ban => Your choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 0:
        {
            this->lCauThu->Nhap();
            break;
        }
        case 1:
        {
            this->lCauThu->Sort();
            this->lCauThu->Xuat();
            break;
        }
        case 2:
        {
            vector<CauThu*>* temp = this->lCauThu->Loc();
            if (temp->size() == 0)
                cout << "Khong tim thay cau thu" << endl;
            else
            {
                for (auto item : *temp)
                {
                    item->Xuat();
                }
            }
            break;
        }
        case 3:
        {
            vector<CauThu*>* temp = this->lCauThu->Search();
            if (temp->size() == 0)
                cout << "Khong tim thay cau thu" << endl;
            else
            {
                for (auto item : *temp)
                {
                    item->Xuat();
                }
            }
            break;
        }
        case 4:
        {
            this->lCauThu->XemTinhTrangTheLuc();
            break;
        }
        case 5:
        {
            this->lCauThu->XemTinhTrangSucKhoe();
            break;
        }
        case 6:
        {
            CauThu* temp = this->lCauThu->CauThuCoTheLucTotNhat();
            if (temp == nullptr)
                cout << "Khong tim thay cau thu" << endl;
            else
                temp->Xuat();
            break;
        }
        case 7:
        {
            CauThu* temp = this->lCauThu->CauThuCoSucKhoeYeuNhat();
            if (temp == nullptr)
                cout << "Khong tim thay cau thu" << endl;
            else
                temp->Xuat();
            break;
        }
        case 8:
        {
            cout << "Tong luong phai tra cho cac Cau  Thu la: " << this->lCauThu->TongLuongToanCauThu() << endl;
            break;
        }
        case 9:
        {
            this->lCauThu->~QuanLyCauThu();
            flag = 0;
            break;
        }
        default:
        {
            cout << "Nhap sai, moi nhap lai!!  " << endl;
            break;
        }
        }
    }
}

void DoiBong::MenuQLNV()
{
    int flag = 1;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***      0. Nhap NV                              ***\t\t\t" << endl;
        cout << "\t\t\t***      1. Sap xep Nhan Vien theo Luong         ***\t\t\t" << endl;
        cout << "\t\t\t***      2. Loc Nhan Vien                        ***\t\t\t" << endl;
        cout << "\t\t\t***      3. Xem Danh Sach Bac Si                 ***\t\t\t" << endl;
        cout << "\t\t\t***      4. Xem Danh Sach HLV Chien Thuat        ***\t\t\t" << endl;
        cout << "\t\t\t***      5. Xem Danh Sach HLV The Luc            ***\t\t\t" << endl;
        cout << "\t\t\t***      6. Xem Danh Sach Nhan Vien Bao Ve       ***\t\t\t" << endl;
        cout << "\t\t\t***      7. Xem Danh Sach Nhan Vien Ve Sinh      ***\t\t\t" << endl;
        cout << "\t\t\t***      8. Tong Luong Nhan Vien                 ***\t\t\t" << endl;
        cout << "\t\t\t***      9. Tim kiem nhan vien theo ten          ***\t\t\t" << endl;
        cout << "\t\t\t***     10. Xem Ca Nhan                          ***\t\t\t" << endl;
        cout << "\t\t\t***     11. Thoat                                ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************\t\t\t" << endl;
        cout << "Moi nhap lua chon cua ban => Your choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 0:
        {
            this->lNhanVien->Nhap();
            break;
        }
        case 1:
        {
            this->lNhanVien->Sort();
            this->lNhanVien->Xuat();
            break;
        }
        case 2:
        {
            vector<CaNhan*>* temp = this->lNhanVien->Loc();
            if (temp->size() == 0)
            {
                cout << "Khong co nhan vien thoa dieu kien loc!!" << endl;
            }
            else
            {
                for (auto item : *temp)
                {
                    item->Xuat();
                    cout << endl;
                }
            }
            break;
        }
        case 3:
        {
            this->lNhanVien->XuatDSBacSi();
            break;
        }
        case 4:
        {
            this->lNhanVien->XuatDSHLVCT();
            break;
        }
        case 5:
        {
            this->lNhanVien->XuatDSHLVTL();
            break;
        }
        case 6:
        {
            this->lNhanVien->XuatDSNVBV();
            break;
        }
        case 7:
        {
            this->lNhanVien->XuatDSNVVS();
            break;
        }
        case 8:
        {
            cout << "Tong luong toan nhan vien la: " << this->lNhanVien->TinhLuongToanBoNV() << endl;
            break;
        }
        case 9:
        {
            CaNhan* temp = this->lNhanVien->Search();
            if (temp == nullptr)
            {
                cout << "Khong ton tai nhan vien nay!!" << endl;
            }
            else
            {
                temp->Xuat();
                cout << endl;
            }
            break;
        }
        case 10:
        {
            this->lNhanVien->XemCaNhan();
            cout << endl;
            break;
        }
        case 11:
        {
            this->lNhanVien->~QuanLyNhanVien();
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

void DoiBong::MenuHoatDong()
{
    int flag = 1;
    HoatDong HoatDong;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***      1. Kham Suc Khoe Toan Doi               ***\t\t\t" << endl;
        cout << "\t\t\t***      2. Kham Suc Khoe Cau Thu                ***\t\t\t" << endl;
        cout << "\t\t\t***      3. Chon Doi 11 Nguoi                    ***\t\t\t" << endl;
        cout << "\t\t\t***      4. Huan Luyen The Luc Ca Doi            ***\t\t\t" << endl;
        cout << "\t\t\t***      5. Huan Luyen The Luc Cau Thu           ***\t\t\t" << endl;
        cout << "\t\t\t***      6. Da thu                               ***\t\t\t" << endl;
        cout << "\t\t\t***      7. Thoat                                ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************\t\t\t" << endl;
        cout << "Moi nhap lua chon cua ban => Your choice: " ;
        int choice; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            BacSi* BsKham = this->lNhanVien->ChonBacSi();
            if (BsKham != nullptr)
            {
                HoatDong.KhamSucKhoeToanDoi(this->lCauThu->getvectorCauThu(), BsKham);
                this->lCauThu->XemTinhTrangSucKhoe();
            }
            break;
        }
        case 2:
        {
            BacSi* BsKham = this->lNhanVien->ChonBacSi();
            if (BsKham != nullptr)
            {
                for(auto item : *this->lCauThu->getvectorCauThu())
                {
                    cout << "Ten: " << item->sHoTen << " So Ao: " << item->getiSoAo() << endl;
                }
                cout << "Muon Kham Suc Khoe Cau Thu thu: ";
                int i; cin >> i;
                CauThu* temp = this->lCauThu->getvectorCauThu()->at(i);

                HoatDong.KhamSucKhoeCauThu(temp, BsKham);
                this->lCauThu->getvectorCauThu()->at(i) = temp;
                this->lCauThu->XemTinhTrangSucKhoe();
            }
            break;
        }
        case 3:
        {
            vector<CauThu*>* temp = HoatDong.TuyenChon11CT(this->lCauThu->getvectorCauThu());
            if (temp->size() != 0)
            {
                cout << "Doi Hinh da lua chon: " << endl;
                for (auto item : *temp)
                {
                    cout << "Ten: " << item->sHoTen << " Vi Tri: " << item->getsViTriDaChinh() << endl;
                }
            }
            break;
        }
        case 4:
        {
            HLVTheLuc* HLV = this->lNhanVien->ChonHLVTL();
            if (HLV != nullptr)
            {
                HoatDong.HuanLuyenTLCaDoi(this->lCauThu->getvectorCauThu(), HLV);
                this->lCauThu->XemTinhTrangTheLuc();
            }
            break;
        }
        case 5:
        {
            HLVTheLuc* HLV = this->lNhanVien->ChonHLVTL();
            if (HLV != nullptr)
            {
                for (auto item : *this->lCauThu->getvectorCauThu())
                {
                    cout << "Ten: " << item->sHoTen << " CMND: " << item->sCMND << endl;
                }
                cout << "Muon Cai Thien The Luc Cau Thu thu: ";
                int i; cin >> i;
                CauThu* temp = this->lCauThu->getvectorCauThu()->at(i);
                HoatDong.HuanLuyenTL(temp, HLV);
                this->lCauThu->getvectorCauThu()->at(i) = temp;
                this->lCauThu->XemTinhTrangTheLuc();
            }
            break;
        }
        case 6:
        {
            if (this->lCauThu->getvectorCauThu()->size() < 11)
            {
                cout << "Khong du cau thu de tham gia thi dau" << endl;
                break;
            }
            if (this->lNhanVien->getlHLVCT()->size() == 0)
            {
                cout << "Khong co HLV" << endl;
                break;
            }
            HLVChienThuat* hlv = this->lNhanVien->ChonHLVCT();
            HoatDong.DaGiaoLuu(this->lCauThu->getvectorCauThu(), hlv);
            break;
        }
        case 7:
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
