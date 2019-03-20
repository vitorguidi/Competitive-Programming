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

ll m,n,k;
ll dist[100100];
vector< tuple<ll,ll,ll> > nodes[100100];

bool check(ll val){

	frr(i,n)	dist[i]=1e18;
	dist[1]=0;

	set<pll> q;
	q.insert({0,1});

	ll u,v,from;

	while(!q.empty()){

		pll aux = *q.begin();
		q.erase(q.begin());

		from = aux.fst;
		u = aux.snd;
		
		for(auto x : nodes[u]){

			ll custo = get<0>(x);
			ll wis = get<1>(x);
			v=get<2>(x);

			if(val<wis)	continue;

			if(custo+from<dist[v]){
				dist[v]=custo+from;
				q.insert({dist[v],v});
			}			


		}

	}

	return dist[n]<k;

}

void go(){

	scanf("%lld %lld %lld",&n,&m,&k);

	frr(i,n)	nodes[i].clear();

	frr(i,m){
		ll c,u,v,w;
		scanf("%lld %lld %lld %lld",&u,&v,&c,&w);
		nodes[u].pb(make_tuple(c,w,v));
		nodes[v].pb(make_tuple(c,w,u));
	}

	ll ini=0;
	ll end =1e9;
	ll best=INF;

	while(ini<=end){
		ll mid = (ini+end)>>1;
		if(check(mid)){
			best=mid;
			end=mid-1;
		}
		else	ini=mid+1;
	}

	if(best!=INF && check(best))	printf("%lld\n",best);
	else							printf("-1\n");

}

int main(){

	int t; scanf("%d",&t);
	while(t--)	go();
	
}