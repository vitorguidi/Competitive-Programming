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
 
int seq[1000001];
int ps[1000001];
 
string s;
int tam, cache[5001];
 
int pd(int ind){
	if(ind==tam)	return 1;
	if(ind>tam)		return 0;
	if(s[ind]=='0')	return 0;
 
	int &pdm=cache[ind];
 
	if(pdm!=-1)	return pdm;
 
	if(s[ind]<='2' && s[ind+1]=='0')	return pdm=pd(ind+2);
	if(s[ind]=='2' && s[ind+1]<='6')	return pdm=pd(ind+1)+pd(ind+2);
	if(s[ind]=='1')						return pdm=pd(ind+1)+pd(ind+2);
	else								return pdm=pd(ind+1);
 
}
 
int main(){
 
	while(getline(cin,s)){
		if(s=="0")	break;
		tam=s.size();
		ms(cache,-1);
		cout << pd(0) << endl;
	}
 
}