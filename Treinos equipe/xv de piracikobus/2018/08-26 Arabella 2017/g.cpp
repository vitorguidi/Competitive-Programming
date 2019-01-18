#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll n,m,k;
struct rect{
	int xb,yb;
	int xu,yu;
};


vector<rect> bombs;

rect inter(rect a, rect b){
	
	rect aux;
	
	int xb=max(a.xb,b.xb);
	int yb=min(a.yb,b.yb);

	int xu=min(a.xu,b.xu);
	int yu=max(a.yu,b.yu);

	aux.xb=xb;
	aux.yb=yb;
	aux.xu=xu;
	aux.yu=yu;
		
	return aux;
}


ll calc(rect coiso){

	ll l = coiso.yb;
	ll r = m-coiso.yu+1;

	ll u = coiso.xu;
	ll d = n-coiso.xb+1;

	ll ans = l*r*u*d;

	return ans;
}

ll solve(ll mask){

	rect aux;
	aux.xb=-INF;
	aux.yb=INF;
	aux.xu=INF;
	aux.yu=-INF;

	int cnt=0;

	fr(i,k){
		if( (1<<i)&mask ){
			aux=inter(aux,bombs[i]);
			cnt++;
		}
	}

	ll ans = 1;

	if(cnt%2==0)
		ans=-1;

	ans=ans*calc(aux);
	return ans;

}


int main(){

	int t;
	cin >> t;
	while(t--){

		cin >> n >> m >> k;

		bombs.clear();

		fr(i,k){
			int x,y;
			cin >> x >> y;
			rect aux;
			aux.xb=aux.xu=x;
			aux.yu=aux.yb=y;
			bombs.pb(aux);
		}

		ll ans = 0;
		ll tot = (m*(m+1)*n*(n+1))/4;

		for(int i=1;i<(1<<k);i++)
			ans+=solve(i);
	
		cout << tot-ans << endl;

	}
}