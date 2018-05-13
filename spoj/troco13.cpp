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
 
int memo[1001][100001];
int val[1001];
 
int v,m;
 
int pd(int ind,int troco){
	if(troco==0)	return 1;
	if(ind==m)		return 0;
	if(troco<0)		return 0;	//se nao deu troco
 
	// dbg(ind);
	// dbg(val[ind]);
	// dbg(troco);
 
	int &pdm=memo[ind][troco];
	if(pdm!=-1)	return pdm;
	return pdm=max( pd(ind+1,troco-val[ind]) , pd(ind+1,troco) );
}
 
int main(){
	cin >> v >> m;
	fr(i,m)	cin >> val[i];
	ms(memo,-1);
	int resp= pd(0,v);
	if(resp==1)	cout << 'S' << endl;
	else		cout << 'N' << endl;
}
 
 