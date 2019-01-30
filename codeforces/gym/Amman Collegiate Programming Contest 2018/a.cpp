#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	(void)0
#define all(x)	x.begin(),x.end()

#define gnl (void)0
#define fastio ios_base::sync_with_stdio(false);	cin.tie(NULL)   
#define int long long
    
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


pair<pii,int> seq[100100];
int m,k;
ll acum[100100];

ll go(){

	ll ans = 0;

	frr(i,m){
	
		int ini=i;
		int end = m;
		int mid;
		
		int tgt = seq[i].fst.fst + k -1;
		int best = ini -1;
		while(ini<=end){
		
			mid=(ini+end)/2;
			
			if(seq[mid].fst.snd<=tgt){
				best=mid;
				ini=mid+1;
			}
			else
				end=mid-1;
				
		}
		ini=best;
		
		ll aux = acum[ini]-acum[i-1];
		
		
		ll sobra = k - (seq[ini+1].fst.fst - seq[i].fst.fst );
		
		ini++;
		
		if(sobra>0 && ini<=m){
			ll delta = seq[ini].snd*min<ll>(sobra,seq[ini].fst.snd-seq[ini].fst.fst+1);
			dbg(delta);
			dbg(delta);
			aux+= delta;
		
		}
		
		ans= max(ans,aux);
		
	}
	
	return ans;
	
}

void solve(){
	
	cin >> m >> k;	
	
	acum[0]=0;
	
	frr(i,m){
		ll l,r,val;
		cin >> seq[i].fst.fst >> seq[i].fst.snd >> seq[i].snd;
	}
	
	ll ans = 0;
	
	sort(seq+1,seq+m+1);
	
	frr(i,m)
		acum[i] = seq[i].snd * ( seq[i].fst.snd-seq[i].fst.fst+1) + acum[i-1];
		
	ans=max(ans,go());
	
	frr(i,m){
		seq[i].fst.fst=(ll)1e9-seq[i].fst.fst;
		seq[i].fst.snd=(ll)1e9-seq[i].fst.snd;
		swap(seq[i].fst.fst,seq[i].fst.snd);
	}
	
	sort(seq+1,seq+m+1);
	
	frr(i,m)
		acum[i] = seq[i].snd * ( seq[i].fst.snd-seq[i].fst.fst+1) + acum[i-1];
		
		
	ans=max(ans,go());
	
	cout << ans << endl;
	
}

int32_t main(){

	fastio;
	
	int t; cin >> t;
	while(t--) solve();

}