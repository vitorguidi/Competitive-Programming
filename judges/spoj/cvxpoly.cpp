#include "bits/stdc++.h"
using namespace std;
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define all(x)	x.begin(),x.end()
#define dbg(x)	cout << #x << " = " << x << endl
#define gnl cout << endl
#define pb push_back
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef long long int ll;
const int INF = 0x3f3f3f3f;
const long double eps = 1e-6;
const ll MOD = 1234567;
 
struct point{
	ll x,y;
	point(){}
	point(ll a,ll b){
		x=a,y=b;
	}
	point operator-(point p){return point(x-p.x,y-p.y);}
	ll operator^(point p){return x*p.y-y*p.x;}
	bool operator==(point p){return x==p.x && y==p.y;}
	bool operator!=(point p){return x!=p.x || y!=p.y;}
};
 
int n;
vector<point> v;
vector<point> aux;
 
ll memo[105][105];
point pivot;
 
void printa(point p){
	cout << p.x << " " << p.y << endl;
}
 
int ori(point from, point a, point b){
	return (a-from)^(b-from);
}
 
bool valid(point a, point b){
	return a.x>b.x || (a.x==b.x && a.y<b.y);
}
 
ll pd(int se, int fi){
 
	if(se==0)
		return 1;
 
	ll &pdm=memo[se][fi];
	if(pdm!=-1)	return pdm;
 
	pdm=0;
 
	for(int i=0;i<se;i++)
		if(ori(aux[i],aux[se],aux[fi])>0)
			pdm=(pdm+pd(i,se))%MOD;
	
 
	return pdm;
 
}
 
bool operator<(point a, point b){
	return ori(pivot,a,b)>0;
}
 
 
 
ll solve(int from){
 
	pivot = v[from];
 
	aux.clear();
	memset(memo,-1,sizeof memo);
 
	for(auto x : v)
		if(valid(x,pivot))
			aux.pb(x);
 
	sort(all(aux));
	reverse(all(aux));
	aux.pb(pivot);
	reverse(all(aux));
 
	fr(i,aux.size()-1)
		assert(ori(pivot,aux[i],aux[i+1])>=0);
 
	ll ans=0;
 
	for(int i=1;i<aux.size();i++)
		for(int j=i+1;j<aux.size();j++)
			ans=(ans+pd(i,j))%MOD;
		
	return ans;
 
}
 
int main(){
 
	fastio;
 
	int t;
	cin >> t;
	while(t--){
 
	 	
		cin >> n;
		v.clear();
		
		frr(i,n){
			point p;
			long double x,y;
			cin >> p.x >> p.y;
			v.push_back(p);
		}
 
		ll ans =0;
 
		fr(i,n){
			ll lol = solve(i);
			ans+=lol;
			ans%=MOD;
		}
 
		cout << ans << endl;
 
 
	}
 
} 