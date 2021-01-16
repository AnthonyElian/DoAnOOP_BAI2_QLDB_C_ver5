#pragma once
#ifndef HoatDong_h
#define HoatDong_h
#include<vector>
#include"CauThu.h"
#include"BacSi.h"
#include"HLVChienThuat.h"
#include"HLVTheLuc.h"
#include"NVBaoVe.h"
#include"NVVeSinh.h"
#include<algorithm>
#include "QuanLyCauThu.h"

class HoatDong
{
public :
	static void KhamSucKhoeToanDoi(vector<CauThu*>* list, BacSi* bacsi);
	static void KhamSucKhoeCauThu(CauThu* &ct, BacSi* bs);
	static vector<CauThu*>* TuyenChon11CT(vector<CauThu*>* list);
	static void HuanLuyenTLCaDoi(vector<CauThu*>* list, HLVTheLuc* HLV);
	static void HuanLuyenTL(CauThu* &ct, HLVTheLuc* hlv);
	static void DaGiaoLuu(vector<CauThu*>* listCT, HLVChienThuat* HLV);
	static void createCauThu(vector<CauThu*>* &chuyennhuong);
	static void ChuyenNhuong(QuanLyCauThu* &ct, vector<CauThu*>*& temp);
};
#endif // !HoatDong_h
