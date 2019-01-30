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

int n,m;
vi wgts,bar,subsets;
vi pool;
int sum;

int soma(int x){

	int ans = 0;

	fr(i,m){
		if( x&(1<<i) )
			ans+=wgts[i];
	}

	return ans;

}

bool verify(int x, int y){
	int aux = x&y;
	if(aux==0)
		return true;
	return false;
}

int main(){
    
	cin >> n >> m;

	fr(i,n){
		int aux; cin >> aux;
		bar.pb(aux);
	}    

	fr(i,m){
		int aux; cin >> aux;
		wgts.pb(aux);
	}

	vii masks;

	fr(i, (1<<m) )
		masks.pb( mp(soma(i),i) );
	
	int mx= (1<<m);

	fr(i,mx){
		for(int j=i+1;j<mx;j++){

			if(i==j)
				continue;

			if(masks[i].fst!=masks[j].fst)
				continue;
			
			if(!verify(masks[i].snd,masks[j].snd))
				continue;

			subsets.pb(2*masks[j].fst);
		}
	}

	vi ans;
	subsets.pb(0);	

	fr(i,n){
		fr(j,subsets.size()){
			ans.pb(subsets[j]+bar[i]);
		}
	}

	sort(all(ans));
	map<int,int> memo;
	
	for(auto x : ans){
		if(!memo[x]){
			cout << x << endl;
			memo[x]=1;	
		}
	}


}

