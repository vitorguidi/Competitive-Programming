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
map <string,int> pontos; 
vector<int> v;
int main()
{	
	fastcin;
	pontos["red"] = 1;
	pontos["yellow"] = 2;
	pontos["green"] = 3;
	pontos["brown"] = 4;
	pontos["blue"] = 5;
	pontos["pink"] = 6;
	pontos["black"] = 7;
	
	cin >> n;
	int red=0;
	for(int i=0;i<n;i++)
	{
		string a;
		cin >> a;
		if(a == "red")
			red++;
		else
			v.pb(pontos[a]);
	}
	if(v.size() == 0)
	{
		cout << 1 << endl;
		return 0;
	}

	ll int soma =0;
	sort(v.rbegin(),v.rend());
	soma+=v[0]*red;
	soma+=red;
	for(int i=0;i<v.size();i++)
	{
		soma+= v[i];
	}
	cout << soma << endl;
}
close