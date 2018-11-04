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

vi ver,hor;

int main(){
    
	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,n){
	
		int x; cin >> x;
	
		ver.pb(x);
	
	}

	ver.pb(1e9);
	sort(all(ver));

	fr(i,m){
		
		int a,b,c;
		cin >> a >> b >> c;
	
		if(a>1)	continue;
	
		hor.pb(b);
	
	}
	sort(all(hor));

	int ans = INF;
	int len = hor.size();

	int ini=0;

	fr(i,ver.size()){

		int val = ver[i];
		
		while(  ini<hor.size() && hor[ini]<val )
			ini++;

		ans=min(ans,len-ini+i);		//quantos segmentos verticais tirei + quanatos segmentos horizontais tirei
								//tirei todos os que terminam em val ou depois
	
	}

	cout << ans << endl;

}

