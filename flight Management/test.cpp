#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,string> pair1(0,"Delhi");
     pair<int,string> pair2(1,"Mumbai");
      pair<int,string> pair3(2,"Chennai");
       pair<int,string> pair4(3,"Kolkata");
        pair<int,string> pair5(4,"Banglore");
for(int i=0;i<5;i++)
{
    if(i==pair1.first)
        {
            cout<<pair1.second<<endl;
        }
    else if(i==pair2.first)
        {
            cout<<pair2.second<<endl;
        }
      else  if(i==pair3.first)
        {
            cout<<pair3.second<<endl;
        }
        else if(i==pair4.first)
        {
            cout<<pair4.second<<endl;
        }
        else if (i==pair5.first)
        {
            cout<<pair5.second<<endl;
        }

    }
return 0;

}
