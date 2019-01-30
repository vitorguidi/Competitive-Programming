#include "bits/stdc++.h"
using namespace std;
 
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define grtp greater<pair<int,int>>()
#define grti greater<int>()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
 
const int INF = 0x3f3f3f3f;
const long long int llINF = 1e18;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
 
int memo[2001][2001];
 
vector<pii> bag;
int s,n;
 
int pd(int ind, int lim){
	if(ind==n)	return 0;
	if(lim<0)	return 0;
 
	int &pdm = memo[ind][lim];
 
	if(pdm!=-1)	return pdm;
 
	if(lim-bag[ind].fst>=0)	return pdm = max( bag[ind].snd + pd(ind+1,lim-bag[ind].fst) , pd(ind+1,lim) );
	else					return pdm=pd(ind+1,lim);
}
 
int main(){
 
	cin >> s >> n;
	int w,v;
	fr(i,n){
		cin >> w >> v;
		bag.pb(mp(w,v)); 
	}
 
	ms(memo,-1);
 
	cout << pd(0,s) << endl;
 
	return 0;
	
}