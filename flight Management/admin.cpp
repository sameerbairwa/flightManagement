#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main()
{
    cout<<"1.Find Routes between two airports"<<endl;
    cout<<"2.Shortest Path"<<endl;
    int ch;
    cout<<"Enter Choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            system("cls");
            system("apaths.exe");
            break;
        }
    case 2:
        {
            system("cls");
            system("shortestpath.exe");
            break;
        }
    default :
    {
            system("cls");
            cout<<"Wrong input";
            getch();
            system("cls");
            system("admin.exe");
            break;
        }
    }
    return 0;

}
