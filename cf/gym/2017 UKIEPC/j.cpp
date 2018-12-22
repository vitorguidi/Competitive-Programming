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
#define MAX 

int n;
double soma=0.0;  
int main()
{	
	fastcin;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int at;
		cin >> at;
		if(at == 0)
			soma+= 2.0;
		else if(at==1)
			soma+= 1.0;
		else if(at == 2)
			soma+= 0.5;
		else if(at == 4)
			soma+= 0.25;
		else if(at==8)
			soma+=0.125;
		else
			soma+=0.0625;
	}
	cout << setprecision(20) << soma << endl;
}