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
 
int memo[51][1001];
int val[50];
int wgt[50];
 
int c=-1,f=-1;
 
int pd(int ind, int lim){
 
	if(ind==f)	return 0;
	if(lim<0)	return 0;
	
	int &pdm = memo[ind][lim];
	if(pdm!=-1)	return pdm;
	
	if(lim-wgt[ind]>=0)		return pdm = max( val[ind] + pd(ind+1,lim-wgt[ind]) , pd(ind+1,lim) );
	else					return pdm= pd(ind+1,lim);
}
 
int main(){
 
	int cnt=0;
 
	while(c!=0 && f!=0){
		cin >> c >> f;
		if(c==0 && f==0)	break;
 
		fr(i,f){
			cin >> wgt[i];
			cin >> val[i];
		}
		ms(memo,-1);
		cnt++;
		
		cout << "Teste " << cnt << endl;
		cout << pd(0,c) << endl << endl;
	}
 
	return 0;
	
}
 