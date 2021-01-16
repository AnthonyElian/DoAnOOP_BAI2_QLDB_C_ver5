#pragma once
#include"CauThu.h"
#include<vector>
#include<algorithm>

class QuanLyCauThu
{
private:
	vector<CauThu*> *vectorCauThu;
public:
	QuanLyCauThu();
	QuanLyCauThu(vector<CauThu*>* lcauthu);
	~QuanLyCauThu();
	vector<CauThu*> *getvectorCauThu();
	void setvectorCauThu(vector<CauThu*>* vectorCauThu);
	void Nhap();
	void Xuat();
	void Sort();
	vector<CauThu*>* Loc();
	vector<CauThu*>* Search();
	void XemTinhTrangTheLuc();
	void XemTinhTrangSucKhoe();
	CauThu* CauThuCoTheLucTotNhat();
	CauThu* CauThuCoSucKhoeYeuNhat();
	double TongLuongToanCauThu();
	void xoaCT();
	void xoa1CT(int x);
};

