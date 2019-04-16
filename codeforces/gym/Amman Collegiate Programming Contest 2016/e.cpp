#include <bits/stdc++.h>
using namespace std;

#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ms(x,val) memset(x,val,sizeof x)
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX
#define vll vector<long long int>
#define pii pair<int,int>
#define pll pair<long long int, long long int>

int main()
{	
	fastcin;
	int n;
	cin >> n;
	while(n--)
	{
		int a;
		cin >> a;
		int resp = a/5;
		if(a%5)
			resp++;
		cout << resp << endl;
	}	
	return 0;
}