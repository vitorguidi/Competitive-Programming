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

vector<ll> tasks;
ll n,k,m;

ll solve(ll amt, ll time){

	ll score = 0;

	fr(i,k){

		ll pode = time/tasks[i];
		
		pode=min(pode,amt);
		
		score+=pode;
	
		time-=pode*tasks[i];
	
	}

	return score;

}

int main(){
    
	fastio;

	cin >> n >> k >> m;

	ll total=0;

	fr(i,k){
		ll x; cin >> x;
		tasks.pb(x);
		total+=x;
	}

	sort(all(tasks));
	
	ll best = -llINF;
	
	for(ll i=0;i<=n;i++){

		ll cost = i*total;
		ll score = i*(k+1ll);

		if(cost>m)	break;

		best = max<ll>( best , score + solve(n-i,m-cost) );

	}

	cout << best << endl;

}

