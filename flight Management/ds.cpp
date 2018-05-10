#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
using namespace std;
int main()
{
    int ch;
    cout<<"1.User Module"<<endl;
    cout<<"2.Admin Module"<<endl;
    cout<<"Enter Your choice:"<<endl;
    cin>>ch;
   // Line();
    switch(ch)
    {
    case 1:
        {
            system("cls");
            system("ars.exe");
            break;
        }
    case 2:
        {
            system("cls");
            system("admin.exe");
            break;
        }
    default:
        {
            cout<<"Wrong choice.........";
            getch();
            system("cls");
            system("ds.exe");
            break;
        }

    }
    return 0;
}
