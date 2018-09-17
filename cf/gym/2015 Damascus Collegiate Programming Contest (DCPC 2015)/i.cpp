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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

struct caras{
	int x;
	int y;
	ll r;
};

vector<caras> repo;
ll d[110][110];

void solve(){
	
	int n; cin >> n;

	repo.clear();
	
	fr(i,n)
		fr(j,n)
			d[i][j]=llINF;

	fr(i,n)
		d[i][i]=0;
	
	fr(i,n){
		caras aux;
		cin >> aux.x;
		cin >> aux.y;
		cin >> aux.r;
		repo.pb(aux);
	}

	ll xs,ys,xe,ye;
	cin >> xs >> ys >> xe >> ye;

	
	fr(i,n){
		fr(j,n){

			ll dx = llabs(repo[i].x-repo[j].x);
			ll dy = llabs(repo[i].y-repo[j].y);

			ll dxy=dx*dx+dy*dy;
			ll radius = repo[i].r*repo[i].r;

			ll are = llINF;

			if(radius>=dxy)
				are=2;
			
			d[i][j]=min(are,dx+dy);
		
		}
	}

	fr(k,n)
		fr(i,n)
			fr(j,n)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	ll ans = llabs(xs-xe) + llabs(ys-ye);

	fr(i,n){
		fr(j,n){
			ll aux=0;
			caras s1 = repo[i];
			caras s2 = repo[j];

			aux+=llabs(xs-s1.x)+llabs(ys-s1.y);
			aux+=llabs(xe-s2.x)+llabs(ye-s2.y);
			aux+=d[i][j];
			ans = min(ans,aux);
		}
	}

	cout << ans << endl;
	

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	int t; cin >> t;
	while(t--)
		solve();
    
}
