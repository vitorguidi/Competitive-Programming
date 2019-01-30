#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 1000000000000001018
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 150 

int h[MAX],r,t;
int v[MAX][MAX];
int maior = -1;
int main()
{	
	fastcin;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int r,t;
		cin >> h[i] >> r >> t;
		if(r<t)
			for(int j=r+1;j<t;j++)
				v[i][j]=1;
		else
		{
			for(int j = r+1;j<=h[i];j++)
				v[i][j]=1;
			for(int j=0;j<t;j++)
				v[i][j]=1;
		}
		maior = max(h[i],maior);
	}
	for(int i=0;i<= maior*1825;i++)
	{
		bool deu = true;
		for(int j=0;j<n;j++)
		{
			int hat = i%h[j];
			if(v[j][hat]==1)
			{
				deu = false;
				break;
			}
		}
		if(deu)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
}
close