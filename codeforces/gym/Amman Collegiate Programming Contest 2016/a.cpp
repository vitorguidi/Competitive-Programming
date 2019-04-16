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
#define gnl cout << endl
#define dbg(x) cout << #x << " = " << x << endl
#define vll vector<long long int>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long int, long long int>

const ll MOD = 1e9+7;

int coins[200][2];
ll memo1[200][15050],memo2[200][15050];

	int n,m,k,w;

ll pd1(int ind, int cost){		//cara 0, n moedas

	if(cost<0)	return 0;

	if(ind>=n){
		if(cost==0)	return 1;
		return 0;
	}

	ll& pdm = memo1[ind][cost];
	if(pdm!=-1)	return pdm;

	pdm = 0;

	pdm+= pd1(ind+1,cost);
	pdm+= pd1(ind+1,cost-coins[ind][0]);

	pdm%=MOD;

	return pdm;

}

ll pd2(int ind, int cost){		//cara 0, m moedas

	if(cost<0)	return 0;

	if(ind>=m){
		if(cost==0)	return 1;
		return 0;
	}

	ll& pdm = memo2[ind][cost];
	if(pdm!=-1)	return pdm;

	pdm = 0;

	pdm+= pd2(ind+1,cost);
	pdm+= pd2(ind+1,cost-coins[ind][1]);

	pdm%=MOD;

	return pdm;

}

void go(){

	cin >> n >> m >> k >> w;

	fr(i,n)	cin >> coins[i][0];
	fr(i,m)	cin >> coins[i][1];

	ms(memo1,-1);
	ms(memo2,-1);

	ll ans = 0;

	for(int i=0;i<=w;i++){

		ll x = i;
		ll y = w-i;

		if(abs(x-y)>k)	continue;

		ans+=pd1(0,i)*pd2(0,w-i);
		ans%=MOD;

	}

	cout << ans << endl;

}

int main()
{	
	fastcin;
	
	int t; cin >> t;
	while(t--)	go();

}
