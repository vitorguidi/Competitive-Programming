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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[110];

int main(){
    
	fastio;
	int n,m; cin >> n >> m;
	int mn = INF;
	int mx= 0;

	fr(i,n){
		cin >> v[i];
		mx=max(mx,v[i]);
		mn=min(mn,v[i]);
	}

	int ans =mx+m;
	int ans2=m;

	fr(i,n){
		int coiso = min(mx-v[i],m);
		v[i]+=coiso;
		m-=coiso;
	}

	int ini=0;
	while(m){
		v[ini%n]++;
		m--;
		ini++;
	}

	int lol = -INF;
	fr(i,n)
		lol=max(lol,v[i]);

	cout << lol << " " << ans << endl;

}

