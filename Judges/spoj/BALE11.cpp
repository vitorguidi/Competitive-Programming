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
 
ll mergesort(vector<int> &v){
	int tam=v.size();
	if(tam==1)	return 0;
	vector<int> v1,v2;
	ll inv=0;
	fr(i,tam/2)					v1.pb(v[i]);
	for(int i=tam/2;i<tam;i++)	v2.pb(v[i]);
	inv+=mergesort(v1);
	inv+=mergesort(v2);
	v1.pb(-INF);
	v2.pb(-INF);
	int s=v1.size();
	int ini1=0,ini2=0;
	fr(i,tam){
		if(v1[ini1]>=v2[ini2]){
			v[i]=v1[ini1];
			ini1++;
		}
		else{
			v[i]=v2[ini2];
			ini2++;
			inv+=s-1-ini1;
		}
	}
	return inv;
}
 
int main(){
	ll n,aux;
	cin >> n;
	vector<int> v;
	fr(i,n){
		cin >> aux;
		v.pb(aux);
	}
	cout << (n*(n-1))/2 - mergesort(v) << endl;
	return 0;
}	
 