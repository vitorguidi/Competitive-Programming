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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> state;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int m,n,k,key;
vector<state> edges;
vector<state> answer;
int best = INF;
int id[30];

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	id[b]=a;
}

void brute(int mask){

	int cost = 0;

	vector<state> candidates;
	vector<state> partial;

	for(auto x : edges)
		if( ( (1<< get<1>(x) )&mask) && ( (1<<get<2>(x) )&mask))
			candidates.pb(x);

	fr(i,n)	id[i]=i;

	for(auto x : candidates){
		if( find(get<1>(x)) != find(get<2>(x)) ){
			cost+=get<0>(x);
			join(get<1>(x),get<2>(x));
			partial.pb(x);
		}
	}

	set<int> check;

	fr(i,n)
		if((1<<i)&key)
			check.insert(find(i));

	if(check.size()!=1)	return;

	if(cost<best){
		best = cost;
		answer.clear();
		for(auto x : partial)
			answer.pb(x);
	}

}

int main(){

	scanf("%d %d %d",&n,&m,&k);

	fr(i,k){
		int x; cin >> x;
		key|=1<<(x-1);
	}


	fr(i,m){
		int x,y,w;
		cin >> x >> y >> w;
		state aux;
		x--;y--;
		get<0>(aux)=w;
		get<1>(aux)=x;
		get<2>(aux)=y;
		edges.pb(aux);
	}

	sort(all(edges));

	fr(i,1<<n){
		if((key&i)!=key)	continue;
		brute(i);
	}
	
	if(best==INF){
		puts("-1\n");
		return 0;
	}

	cout << best << " " << answer.size() << endl;
	for(auto x : answer)
		printf("%d %d\n",get<1>(x)+1,get<2>(x)+1);
	

}
