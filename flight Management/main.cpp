#include<iostream>
#include<vector>
#include<unistd.h>
#include<map>
#include<limits>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

static int id = 0;
int dijk[11][11];

class airport
{
public:
	int capacity;
	int current = 0;
	int index;
	vector <pair<int ,int>> v[11];
	airport(int );
	void plane(int);
	void depart();
	void arrive();
	void show(airport);
	void distance(airport ,airport , int);
	void curr(airport ,airport);
};

void airport :: distance(airport a1 ,airport a2 ,int dis)
{
	int ind1 = a1.index;
	int ind2 = a2.index;
	v[ind1].push_back(make_pair(ind2 ,dis));
	v[ind2].push_back(make_pair(ind1 ,dis));
	dijk[ind1][ind2]=dis;
	dijk[ind2][ind1]=dis;
}

void airport :: show(airport a)
{
	vector <pair<int,int>> :: iterator it;
	int ind = 	a.index;
		for(it=v[ind].begin(); it!=v[ind].end(); it++)
		{
			cout << "\t\t" << it->second << " --------------- " << it->first << endl;
		}
	cout << endl;
}

void airport :: arrive()
{
	if(capacity == current)
	{
		cout << "No more space available" << endl;
		return;
	}
	current++;
}

void airport :: depart()
{
	if(current == 0)
	{
		cout << "No plane avaialabe" << endl;
		return;
	}
	current--;
}

airport :: airport(int n)
{
	capacity = n;
	index = id;
	id++;
}

void airport :: plane(int n)
{
 if(current == capacity || current + n > capacity)
 {
 	cout << "Overflow" << endl;
 	return;
 }
 current = current +n;
}

void set()
{
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<11; j++)
		{
			if(i==j)
			{
				dijk[i][j]=0;
			}
			else
			{
				dijk[i][j]=99999;
			}
		}
	}
}

void mini()
{
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			cout << dijk[i][j] << "  ";
		}
		cout << endl;
	}
}

void min()
{
	int min[11][11];
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			min[i][j]=dijk[i][j];
		}
	}

	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			cout << min[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n\n\n";

	for (int k=0; k<11; k++)
	{
		for(int i=0; i<11; i++)
		{
			for(int j=0; j<11; j++)
			{
				if(min[i][k] + min[k][j] < min[i][j])
				{
					min[i][j] = min[i][k] + min[k][j];
				}
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			cout << min[i][j] << " ";
		}
		cout << endl;
	}
}

void airport :: curr(airport a,airport b)
{
	int index1 = a.index;
	int index2 = b.index;
	int distance;
	int fuel = 35000;
	distance = dijk[index1][index2];
	for(int hh=0 ; hh<2 ; hh++)
	{
		for (int mm = 0; mm < 60 ; mm++)
		{
			for(int ss = 0 ; ss < 6 ; ss++)
			{
				for(int s = 0 ; s < 10 ; s++)
				{

						cout << "\r\t\ttime -> " << hh << ":" << mm << ":" << ss << s << " \tfuel -> " << fuel << " \tdistance -> " << distance ;
						fflush(stdout);
						fuel-=4;
						distance-=0.27;
						if(distance<=0)
						{
							cout << "\n\n\t\tThe flight reached its destination in " << hh << ":" << mm << ":" << ss << s << " hrs" << endl ;
							break;
						}
					//	sleep(1);

				}
				if(distance<=0)
				break;
			}
			if(distance<=0)
			break;
		}
		if(distance<=0)
		break;
	}
}

int main()
{
	airport a(50);
	a.plane(25);
	airport b(50);
	b.plane(18);
	airport c(50);
	c.plane(29);
	airport d(50);
	d.plane(25);
	airport e(50);
	e.plane(10);
	airport f(50);
	f.plane(31);
	airport g(50);
	g.plane(30);
	airport h(50);
	h.plane(20);
	airport i(50);
	i.plane(15);
	airport j(50);
	j.plane(26);
	airport k(25);
	k.plane(15);
//	set();

	a.distance(a, b, 809);
	a.distance(a, c, 1626);
	a.distance(a, d, 1589);
	a.distance(a, e, 2296);
	a.distance(a, f, 2227);

	b.distance(b, a, 809);
	b.distance(b, c, 946);
	b.distance(b, d, 797);
	b.distance(b, e, 1504);
	b.distance(b, i, 2211);

	c.distance(c, a, 1626);
	c.distance(c, b, 946);
	c.distance(c, f, 523);
	c.distance(c, g, 1219);

	d.distance(d, a, 1589);
	d.distance(d, b, 797);
	d.distance(d, f, 776);
	d.distance(d, g, 850);
	d.distance(d, h, 1212);
	d.distance(d, j, 2124);

	e.distance(e, a, 2296);
	e.distance(e, b, 1504);
	e.distance(e, f, 1950);
	e.distance(e, i, 1670);
	e.distance(e, k, 1302);

	f.distance(f, a, 2227);
	f.distance(f, c, 523);
	f.distance(f, d, 776);
	f.distance(f, e, 1950);
	f.distance(f, h, 591);
	f.distance(f, i, 1337);
	f.distance(f, j, 1676);

	g.distance(g, d, 850);
	g.distance(g, c, 1219);
	g.distance(g, i, 629);

	h.distance(h, d, 1212);
	h.distance(h, f, 591);
	h.distance(h, i, 910);
	h.distance(h, j, 1349);

	i.distance(i, b, 2211);
	i.distance(i, e, 1670);
	i.distance(i, f, 1337);
	i.distance(i, g, 629);
	i.distance(i, h, 910);
	i.distance(i, j, 727);
	i.distance(i, k, 1362);

	j.distance(j, d, 2124);
	j.distance(j, f, 1676);
	j.distance(j, h, 1349);
	j.distance(j, i, 727);

	k.distance(k, e, 1302);
	k.distance(k, i, 1362);

	//To show all paths from particular airport
	a.show(a);
	b.show(b);
	c.show(c);
	d.show(d);
	e.show(e);
	f.show(f);
	g.show(g);
	h.show(h);
	i.show(i);
	j.show(j);
	k.show(k);

	//Initial matrix with particular distances
	//mini();

	//matrix after flyod warshall algo
	//min();

	//g.curr(a,b);

	return 0;
}


/*string source()
{
	string source;
	cout << "Enter your source location " << endl;
	cin >> source;

	source[0]=toupper(source[0]);
	for(int i=1;i<source.length();i++)
	{
		source[i]=tolower(source[i]);
	}
	return source;
}

string destination()
{
	string destination;
	cout << "Enter your destination " << endl;
	cin >> destination;

	destination[0]=toupper(destination[0]);
	for(int i=1;i<destination.length();i++)
	{
		destination[i]=tolower(destination[i]);
	}
	return destination;
}*/
