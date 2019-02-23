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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll xd,yd,xc,yc;

ll get_black(ll xb, ll yb, ll xu, ll yu){

	ll row_good = (xu-xb+2ll)/2ll;
	ll row_bad = xu-xb+1ll-row_good;

	ll col_good = (yu-yb+2ll)/2ll;
	ll col_bad = (yu-yb+1ll)-col_good;

	ll primary = row_good*col_good + row_bad*col_bad;
	ll total = (xu-xb+1ll)*(yu-yb+1ll);

	if((xb+yb)%2==0)	return total-primary;
	else				return primary;

}

ll get_white(ll xb, ll yb, ll xu, ll yu){

	ll tot = (xu-xb+1ll)*(yu-yb+1ll);
	ll black = get_black(xb,yb,xu,yu);
	return tot-black;

}

void get_inter(ll x1,ll y1, ll x2,ll y2, ll x3, ll y3, ll x4, ll y4){

	xd=max(x1,x3);
	yd=max(y1,y3);
	xc=min(x2,x4);
	yc=min(y2,y4);

}

bool has_inter(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4){

	if(y3>y2 || x4<x1 || y4<y1 || x3>x2)	return false;
	return true;

}

void get_disj(ll x1,ll y1,ll x2,ll y2){

	
	if(x1==xd){
		xc=x2;yc=y2;
		xd=xc+1;
	}
	else{
		xd=x1;yd=y1;
		xc=xd-1;
	}

}

void solve(){

	ll n,m; cin >> n >> m;

	ll x1,y1,x2,y2,x3,y3,x4,y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	ll black = get_black(1,1,n,m);
	ll white = get_white(1,1,n,m);

	ll tira1 = get_black(x1,y1,x2,y2);

	black-=tira1;
	white+=tira1;

	ll tira2 = get_white(x3,y3,x4,y4);

	black+=tira2;
	white-=tira2;



	if(has_inter(x1,y1,x2,y2,x3,y3,x4,y4)){
		get_inter(x1,y1,x2,y2,x3,y3,x4,y4);
		ll tira3 = get_black(xd,yd,xc,yc);
		white-=tira3;
		black+=tira3;
	}

	cout << white << " " << black << endl;	

}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	solve();

}

