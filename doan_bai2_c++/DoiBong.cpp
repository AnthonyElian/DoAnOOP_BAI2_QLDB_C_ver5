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
    this->expired = new vector<CaNhan*>();
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

void DoiBong::DanhSachHetHanHopDong()
{
    for (int i = 0; i < this->lCauThu->getvectorCauThu()->size(); i++)
    {
        if (this->lCauThu->getvectorCauThu()->at(i)->ThoiGianHopDongConLai() <= 0)
        {
            CauThu* temp = this->lCauThu->getvectorCauThu()->at(i);
            this->expired->push_back(temp);
        }
    }
    for (int i = 0; i < this->lNhanVien->getlCaNhan()->size(); i++)
    {
        if (this->lNhanVien->getlCaNhan()->at(i)->ThoiGianHopDongConLai() <= 0)
        {
            CaNhan* temp = this->lNhanVien->getlCaNhan()->at(i);
            this->expired->push_back(temp);
        }
    }
}

void DoiBong::ThaoTacHopDong()
{
    this->DanhSachHetHanHopDong();
    if (this->expired->size() <= 0)
    {
        cout << "Khong co nhan vien nao het han hop dong !!" << endl;
    }
    else
    {
        int flag = 1;
        while (flag == 1)
        {
            if (this->expired->size() == 0)
            {
                flag = 0;
            }
            else
            {
                int dem = 0;
                cout << "Danh sach het han hop dong la: " << endl;
                for (auto item : *this->expired)
                {
                    cout << "STT: " << dem++ << " Ho ten: " << item->sHoTen << " Luong: " << item->TinhLuong() << endl;
                }
                cout << "1_Gia Han || 2_Kick => Your choice: ";
                int n; cin >> n;
                switch (n)
                {
                case 1:
                {
                    cout << "Ban muon gia han nhan vien thu may: ";
                    int x; cin >> x;
                    if (this->expired->at(x)->sNghe == "CauThu")
                    {
                        for (int i = 0; i < this->lCauThu->getvectorCauThu()->size(); i++)
                        {
                            if (this->lCauThu->getvectorCauThu()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                            {
                                cout << "Gia han hop dong bao nhieu nam: ";
                                cin >> this->lCauThu->getvectorCauThu()->at(i)->iThoiGianHopDong;
                                this->lCauThu->getvectorCauThu()->at(i)->iNgayGiaNhap = 15;
                                this->lCauThu->getvectorCauThu()->at(i)->iThangGiaNgap = 1;
                                this->lCauThu->getvectorCauThu()->at(i)->iNamGiaNhap = 2021;
                                this->expired->erase(this->expired->begin() + x);
                                break;
                            }
                        }
                    }
                    else
                    {
                        int temp;
                        for (int i = 0; i < this->lNhanVien->getlCaNhan()->size(); i++)
                        {
                            if (this->lNhanVien->getlCaNhan()->at(i)->sHoTen == this->expired->at(i)->sHoTen)
                            {
                                cout << "Gia han hop dong bao nhieu nam?: ";
                                cin >> temp;
                                this->lNhanVien->getlCaNhan()->at(i)->iThoiGianHopDong = temp;
                                this->lNhanVien->getlCaNhan()->at(i)->iNgayGiaNhap = 15;
                                this->lNhanVien->getlCaNhan()->at(i)->iThangGiaNgap = 1;
                                this->lNhanVien->getlCaNhan()->at(i)->iNamGiaNhap = 2021;
                                if (this->expired->at(x)->sNghe == "bacsi")
                                {
                                    for (int i = 0; i < this->lNhanVien->getlBacSi()->size(); i++)
                                    {
                                        if (this->lNhanVien->getlBacSi()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                                        {
                                            this->lNhanVien->getlBacSi()->at(i)->iThoiGianHopDong = temp;
                                            this->lNhanVien->getlBacSi()->at(i)->iNgayGiaNhap = 15;
                                            this->lNhanVien->getlBacSi()->at(i)->iThangGiaNgap = 1;
                                            this->lNhanVien->getlBacSi()->at(i)->iNamGiaNhap = 2021;
                                            break;
                                        }
                                    }
                                }
                                else if (this->expired->at(x)->sNghe == "HLVCT")
                                {
                                    for (int i = 0; i < this->lNhanVien->getlHLVCT()->size(); i++)
                                    {
                                        if (this->lNhanVien->getlHLVCT()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                                        {
                                            this->lNhanVien->getlHLVCT()->at(i)->iThoiGianHopDong = temp;
                                            this->lNhanVien->getlHLVCT()->at(i)->iNgayGiaNhap = 15;
                                            this->lNhanVien->getlHLVCT()->at(i)->iThangGiaNgap = 1;
                                            this->lNhanVien->getlHLVCT()->at(i)->iNamGiaNhap = 2021;
                                        }
                                    }
                                }
                                else if (this->expired->at(x)->sNghe == "HLVTL")
                                {
                                    for (int i = 0; i < this->lNhanVien->getlHLVTL()->size(); i++)
                                    {
                                        if (this->lNhanVien->getlHLVTL()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                                        {
                                            this->lNhanVien->getlHLVTL()->at(i)->iThoiGianHopDong = temp;
                                            this->lNhanVien->getlHLVTL()->at(i)->iNgayGiaNhap = 15;
                                            this->lNhanVien->getlHLVTL()->at(i)->iThangGiaNgap = 1;
                                            this->lNhanVien->getlHLVTL()->at(i)->iNamGiaNhap = 2021;
                                        }
                                    }
                                }
                                else if (this->expired->at(x)->sNghe == "NVVeSinh")
                                {
                                    for (int i = 0; i < this->lNhanVien->getlNVVS()->size(); i++)
                                    {
                                        if (this->lNhanVien->getlNVVS()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                                        {
                                            this->lNhanVien->getlNVVS()->at(i)->iThoiGianHopDong = temp;
                                            this->lNhanVien->getlNVVS()->at(i)->iNgayGiaNhap = 15;
                                            this->lNhanVien->getlNVVS()->at(i)->iThangGiaNgap = 1;
                                            this->lNhanVien->getlNVVS()->at(i)->iNamGiaNhap = 2021;
                                        }
                                    }
                                }
                                else if (this->expired->at(x)->sNghe == "NVBaoVe")
                                {
                                    for (int i = 0; i < this->lNhanVien->getlNVBV()->size(); i++)
                                    {
                                        if (this->lNhanVien->getlNVBV()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                                        {
                                            this->lNhanVien->getlNVBV()->at(i)->iThoiGianHopDong = temp;
                                            this->lNhanVien->getlNVBV()->at(i)->iNgayGiaNhap = 15;
                                            this->lNhanVien->getlNVBV()->at(i)->iThangGiaNgap = 1;
                                            this->lNhanVien->getlNVBV()->at(i)->iNamGiaNhap = 2021;
                                        }
                                    }
                                }
                                this->expired->erase(this->expired->begin() + x);
                                break;
                            }
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout << "Ban muon kick nhan vien thu may: ";
                    int x; cin >> x;
                    if (this->expired->at(x)->sNghe != "CauThu")
                    {
                        int temp = 0;
                        for (int i = 0; i < this->lNhanVien->getlCaNhan()->size(); i++)
                        {
                            if (this->lNhanVien->getlCaNhan()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                            {
                                temp = i;
                                break;
                            }
                        }
                        this->lNhanVien->xoa1NV(temp);
                        this->expired->erase(this->expired->begin() + x);
                    }
                    else
                    {
                        int temp = 0;
                        for (int i = 0; i < this->lCauThu->getvectorCauThu()->size(); i++)
                        {
                            if (this->lCauThu->getvectorCauThu()->at(i)->sHoTen == this->expired->at(x)->sHoTen)
                            {
                                temp = i;
                                break;
                            }
                        }
                        this->lCauThu->xoa1CT(temp);
                        this->expired->erase(this->expired->begin() + x);
                    }
                    break;
                }
                }
                cout << "1_De tiep tuc !! => Your choice: ";
                cin >> flag;
            }
        }
    }
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
        cout << "\t\t\t***      9. Xoa Cau Thu                          ***\t\t\t" << endl;
        cout << "\t\t\t***     10. Thoat                                ***\t\t\t" << endl;
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
            if (this->lCauThu->getvectorCauThu()->size() <= 0)
            {
                cout << "Vui long nhap it nhat mot cau thu !! " << endl;
            }
            else
            {
                this->lCauThu->xoaCT();
                cout << "Danh sach cau thu sau khi xoa: " << endl;
                for (auto item : *this->lCauThu->getvectorCauThu())
                {
                    cout << "Ten cau thu: " << item->sHoTen << endl;
                }
            }
            break;
        }
        case 10:
        {
            //this->lCauThu->~QuanLyCauThu();
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
        cout << "\t\t\t***     11. Xoa Nhan Vien                        ***\t\t\t" << endl;
        cout << "\t\t\t***     12. Thoat                                ***\t\t\t" << endl;
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
            if (this->lNhanVien->getlCaNhan()->size() != 0)
            {
                this->lNhanVien->XemCaNhan();
                cout << endl;
            }
            else
            {
                cout << "Vui long nhap it nhat mot nhan vien !!" << endl;
            }
            break;
        }
        case 11:
        {
            if (this->lNhanVien->getlCaNhan()->size() <= 0)
            {
                cout << "Vui long nhap it nhat mot nhan vien !!" << endl;
            }
            else
            {
                this->lNhanVien->xoaNV();
                for (auto item : *this->lNhanVien->getlCaNhan())
                {
                    cout << "Ho ten: " << item->sHoTen << " Chuc vu: " << item->sNghe << endl;
                }
            }
            break;
        }
        case 12:
        {
            //this->lNhanVien->~QuanLyNhanVien();
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

void DoiBong::MenuHoatDong(San* san)
{
    HoatDong HoatDong;
    vector<CauThu*>* tmp = new vector<CauThu*>();
    HoatDong.createCauThu(tmp);
    int flag = 1;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***      1. Kham Suc Khoe Toan Doi               ***\t\t\t" << endl;
        cout << "\t\t\t***      2. Kham Suc Khoe Cau Thu                ***\t\t\t" << endl;
        cout << "\t\t\t***      3. Chon Doi 11 Nguoi                    ***\t\t\t" << endl;
        cout << "\t\t\t***      4. Huan Luyen The Luc Ca Doi            ***\t\t\t" << endl;
        cout << "\t\t\t***      5. Huan Luyen The Luc Cau Thu           ***\t\t\t" << endl;
        cout << "\t\t\t***      6. Da thu                               ***\t\t\t" << endl;
        cout << "\t\t\t***      7. Thao tac hop dong                    ***\t\t\t" << endl;
        cout << "\t\t\t***      8. Chuyen nhuong                        ***\t\t\t" << endl;
        cout << "\t\t\t***      9. Thoat                                ***\t\t\t" << endl;
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
            HoatDong.DaGiaoLuu(this->lCauThu->getvectorCauThu(), hlv, san);
            break;
        }
        case 7:
        {
            this->ThaoTacHopDong();
            this->expired->clear();
            break;
        }
        case 8:
        {
            HoatDong.ChuyenNhuong(this->lCauThu, tmp);
        }
        case 9:
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
