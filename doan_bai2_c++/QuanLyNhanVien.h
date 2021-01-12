#pragma once
#ifndef QuanLyNhanVien_h
#define QuanLyNhanVien_h

#include<vector>
#include<algorithm>
#include"BacSi.h"
#include"HLVChienThuat.h"
#include"HLVTheLuc.h"
#include"NVBaoVe.h"
#include"NVVeSinh.h"
using namespace std;

class QuanLyNhanVien
{
private:
	vector<CaNhan*>* lCaNhan;
	vector<BacSi*>* lBacSi;
	vector<HLVChienThuat*>* lHLVCT;
	vector<HLVTheLuc*>* lHLVTL;
	vector<NVBaoVe*>* lNVBV;
	vector<NVVeSinh*>*lNVVS;
public:
	vector<CaNhan*>* getlCaNhan();
	void setlCaNhan(vector<CaNhan*>* lcanhan);
	vector<BacSi*>* getlBacSi();
	void setlBacSi(vector<BacSi*>* lbacsi);
	vector<HLVChienThuat*>* getlHLVCT();
	void setlHlVCT(vector<HLVChienThuat*>* lhlvct);
	vector<HLVTheLuc*>* getlHLVTL();
	void setlHLVTL(vector<HLVTheLuc*>* lhlvtl);
	vector<NVBaoVe*>* getlNVBV();
	void setlNVBV(vector<NVBaoVe*>* lnvbv);
	vector<NVVeSinh*>* getlNVVS();
	void setlNVVS(vector<NVVeSinh*>* lnvvs);
	QuanLyNhanVien();
	QuanLyNhanVien(vector<CaNhan*>* lcanhan, vector<BacSi*>* lbacsi, vector<HLVChienThuat*>* lhlvct, vector<HLVTheLuc*>* lhlvtl, vector<NVBaoVe*>* lnvbv, vector<NVVeSinh*>* lnvs);
	~QuanLyNhanVien();
	void Nhap();
	double TinhLuongToanBoNV();
	void Sort();
	void XuatDSBacSi();
	BacSi* ChonBacSi();
	void XuatDSHLVCT();
	HLVChienThuat* ChonHLVCT();
	void XuatDSHLVTL();
	HLVTheLuc* ChonHLVTL();
	void XuatDSNVBV();
	void XuatDSNVVS();
	void Xuat();
	CaNhan* Search();
	vector<CaNhan*>* Loc();
	vector<CaNhan*>* LocTheoLuongLon();
	vector<CaNhan*>* LocTheoLuongBe	();
	void XemCaNhan();
};
#endif // !QuanLyNhanVien_h