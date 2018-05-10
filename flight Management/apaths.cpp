// CPP program to print all paths of source to
// destination in given graph
#include <bits/stdc++.h>

#include<conio.h>

using namespace std;



pair<int,string> p1(0,"Delhi");
pair<int,string> p2(1,"Mumbai");
pair<int,string> p3(2,"Lucknow");
pair<int,string> p4(3,"Jaipur");
pair<int,string> p5(4,"Chennai");
pair<int,string> p6(5,"Hyderabad");
pair<int,string> p7(6,"Bhopal");
pair<int,string> p8(7,"Banglore");
pair<int,string> p9(8,"Goa");


// utility function for printing
// the found path in graph
void printpath(vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
    {
          if(path[i]==p1.first)
        {
            cout<<p1.second<<" ";
        }
    else if(path[i]==p2.first)
        {
            cout<<p2.second<<" ";
        }
      else  if(path[i]==p3.first)
        {
            cout<<p3.second<<" ";
        }
        else if(path[i]==p4.first)
        {
                cout<<p4.second<<" ";
        }

        else if(path[i]==p5.first)
        {
                cout<<p5.second<<" ";
        }
        else if(path[i]==p6.first)
        {
                cout<<p6.second<<" ";
        }
        else if(path[i]==p7.first)
        {
                cout<<p7.second<<" ";
        }
        else if(path[i]==p8.first)
        {
                cout<<p8.second<<" ";
        }
        else if(path[i]==p9.first)
        {
                cout<<p9.second<<" ";
        }

cout<<"-->";


    }



       // cout << path[i] << " ";
    cout << endl;
}

// utility function to check if current
// vertex is already present in path
int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int> >&g, int src,
                                 int dst, int v)
{
    // create a queue which stores
    // the paths
    queue<vector<int> > q;

    // path vector to store the current path
    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        // if last vertex is the desired destination
        // then print the path
        if (last == dst)
            printpath(path);

        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

// driver program
int main()
{





    vector<vector<int> > g;
    // number of vertices
    int v = 9;
    g.resize(9);

    // construct a graph
    g[0].push_back(1);
    g[0].push_back(2);
    g[0].push_back(3);
    g[1].push_back(4);
    g[2].push_back(1);
    g[2].push_back(6);
    g[3].push_back(2);
    g[3].push_back(6);
    g[4].push_back(2);
    g[4].push_back(5);
    g[5].push_back(2);
    g[5].push_back(7);
    g[6].push_back(5);
    g[6].push_back(8);
    g[6].push_back(7);
    g[7].push_back(4);
    g[7].push_back(8);
    g[8].push_back(5);

    int s , d ;
    cout<<"Enter Source="<<endl;
    cin>>s;
    cout<<"Enter Destination="<<endl;
    cin>>d;
        string source,destination;
    for(int i=0;i<9;i++)
    {
         if(s==p1.first)
        {
            source=p1.second;
        }
    else if(s==p2.first)
        {
            source=p2.second;
        }
      else  if(s==p3.first)
        {
            source=p3.second;
        }
        else if(s==p4.first)
        {
            source=p4.second;
        }
        else if(s==p5.first)
        {
            source=p5.second;
        }
        else if(s==p6.first)
        {
            source=p6.second;
        }
        else if(s==p7.first)
        {
            source=p7.second;
        }
        else if(s==p8.first)
        {
            source=p8.second;
        }
        else if(s==p9.first)
        {
            source=p9.second;
        }

    }

        for(int i=0;i<9;i++)
    {
         if(d==p1.first)
        {
            destination=p1.second;
        }
    else if(d==p2.first)
        {
            destination=p2.second;
        }
      else  if(d==p3.first)
        {
            destination=p3.second;
        }
        else if(d==p4.first)
        {
            destination=p4.second;
        }
        else if(d==p5.first)
        {
            destination=p5.second;
        }
        else if(d==p6.first)
        {
            destination=p6.second;
        }
        else if(d==p7.first)
        {
            destination=p7.second;
        }
        else if(d==p7.first)
        {
            destination=p7.second;
        }
        else if(d==p8.first)
        {
            destination=p8.second;
        }
        else if(d==p9.first)
        {
            destination=p9.second;
        }

    }


    cout << "path from src " << source
         << " to dst " << destination << " are \n";

    // function for finding the paths
    findpaths(g, s, d, v);
     cout<<endl;
    cout<<endl;
    cout<<endl;
     cout<<"Main Menu:(press any key)";
    getch();
    system("cls");
    system("ds.exe");

    return 0;
}
