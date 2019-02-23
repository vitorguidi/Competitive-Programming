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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int clk;

struct point{
	int x,y;
	point(int a, int b){x=a;y=b;}
};

struct line{

	int a,b,c;
	line(int x, int y, int z){
		a=x;b=y;c=z;
	}
	bool inside(point p){
		return a*p.x+b*p.y+c==0;
	}

};

line makeline(point p0, point p1){
	int a,b,c;
	a = p1.y-p0.y;
	b = p0.x-p1.x;
	c = p0.x*(p0.y-p1.y) + p0.y*(p1.x-p0.x);
	return line(a,b,c);
}

void solve(){

	map<pii,int> has;

	int n; cin >> n;

	vector<point> v;

    int amt=0;

	frr(i,n){
		
		double a,b; cin >> a >> b;
		a*=100.0;b*=100.0;

		int x = a; int y = b;
		if(has[{x,y}])	continue;
		has[{x,y}]=1;
		amt++;
		point aux = point(x,y);
		v.pb(aux);
	}


	if(amt==1){
		cout << "Data set #" << ++clk << " contains a single gnu." << endl;
		return;
	}

	int ans = 0;

	fr(i,amt){
		fr(j,amt){
			if(i==j)	continue;
			line aux = makeline(v[i],v[j]);
			int cnt = 0;
			fr(k,amt){
				if(aux.inside(v[k]))	cnt++;
			}
			ans=max(ans,cnt);
		}
	}

	cout << "Data set #" << ++clk << " contains " << amt << " gnus, out of which a maximum of " << ans << " are aligned." << endl;

}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	solve();
	
}