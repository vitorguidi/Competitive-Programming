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
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
 
const int INF = 0x3f3f3f3f;
const long long int llINF = 1e18;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
ll cns[10001];
ll m, cache[10001][2];
 
ll pd(int ind, int flag){
	if(ind == m)	return 0;
	if(ind==m-1){	
		if(flag==0)	return cns[m-1];
		if(flag==1)	return 0;
	}
	ll &pdm=cache[ind][flag];
	if(pdm!=-1)	return pdm;
 
	if(flag==0 && cns[ind]!=0)	return pdm=max( cns[ind] + pd(ind+1,1) , pd(ind+1,0) );
	else							return pdm=pd(ind+1,0);
	
}
 
int main(){
 
	int n,v;
 
	cin >> n;
 
	frr(i,n){
		cin >> m;
		fr(i,m) cin >> cns[i];
		ms(cache,-1);
		cout << "Case " << i << ": ";
		cout << pd(0,0) << endl; 
	}
	cout << endl;
 
}