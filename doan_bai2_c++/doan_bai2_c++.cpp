
#include <iostream>

#include"DoiBong.h"
#include "San.h"

using namespace std;


int main()
{
    int flag = 1;
    DoiBong* a = new DoiBong();
    a->Nhap();
    San* san = new San();
    int co = 1, co2 = 1, co3 = 0, co4 = 0;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***            1. Quan Ly Cau Thu                ***\t\t\t" << endl;
        cout << "\t\t\t***            2. Quan Ly Nhan Vien              ***\t\t\t" << endl;
        cout << "\t\t\t***            3. Quan Ly San                    ***\t\t\t" << endl;
        cout << "\t\t\t***            4. Hoat Dong                      ***\t\t\t" << endl;
        cout << "\t\t\t***            5. Thoat                          ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************\t\t\t" << endl;
        cout << "Moi nhap lua chon cua ba => Your choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            a->MenuQLCT();
            co3 = 1;
            break;
        }
        case 2:
        {
            a->MenuQLNV();
            co4 = 1;
            break;
        }
        case 3:
        {
            if (co == 1)
            {
                cout << "Doi Bong co san co khong? 1_Co || 2_Khong : ";
                int temp; cin >> temp;
                if (temp == 1)
                {
                    san->Nhap();
                    cout << "//////////////////////////////////////////////////////////////////////" << endl;
                    san->Xuat();
                }
                else
                {
                    co2 = 0;
                    san = nullptr;
                    cout << "Doi bong khong co San!! " << endl;
                }
                co = 0;
            }
            else
            {
                if (co2 == 1)
                    san->Xuat();
                else
                    cout << "Doi bong khong co San!! " << endl;
            }
            break;
        }
        case 4:
        {
            a->MenuHoatDong();
            break;
        }
        case 5:
        {
            a->~DoiBong();
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
