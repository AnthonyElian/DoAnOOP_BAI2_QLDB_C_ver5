#pragma once
#ifndef DoiBong_h
#define DoiBong_h
#include"QuanLyCauThu.h"
#include"QuanLyNhanVien.h"
#include"HoatDong.h"
#include<string>

class DoiBong
{
private:
	string sTenDoiBong;
	string sTenNhaTaiTro;
	QuanLyCauThu* lCauThu;
	QuanLyNhanVien* lNhanVien;
public:
	vector<CaNhan*>* expired;
	string getsTenDoiBong();
	void setsTenDoiBong(string ten);
	string getsTenNhaTaiTro();
	void setsTenNhaTaiTro(string ten);
	QuanLyCauThu* getQuanLyCauThu();
	void setQuanLyCauThu(QuanLyCauThu* a);
	QuanLyNhanVien* getQuanLyNhanVien();
	void setQuanLyNhanVien(QuanLyNhanVien* a);
	DoiBong();
	DoiBong(string tendoi, string tennhataitro);
	~DoiBong();
	void Nhap();
	void Xuat();
	void DanhSachHetHanHopDong();
	void ThaoTacHopDong();
	void MenuQLCT();
	void MenuQLNV();
	void MenuHoatDong();
};
#endif // !DoiBong_h
