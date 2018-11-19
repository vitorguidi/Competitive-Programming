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

ll aux[1200100];
ll v[1200100];

int main(){
    
	fastio;

	int n; cin >> n;

	vi coord;
	vii queries;

	fr(i,n){
		int x,y;
		cin >> x >> y;
		coord.pb(x);
		coord.pb(x+1);
		coord.pb(y);
		coord.pb(y+1);
		coord.pb(x-1);
		coord.pb(y-1);
		queries.pb({x,y});
	}

	sort(all(coord));

	map<int,int> id;
	int ini=1;

	for(auto x : coord)
		if(!id[x])
			id[x]=ini++;

	ini--;

	fr(i,n){
		queries[i].fst=id[queries[i].fst];
		queries[i].snd=id[queries[i].snd];
		int x=queries[i].fst;
		int y=queries[i].snd;
		aux[x]++;
		aux[y+1]--;
	}

	int adder=0;
	frr(i,ini){
		adder+=aux[i];
		v[i]+=adder;
	}

	bool flag=true;
	for(int i=1;i<=ini;i++)
		if(v[i]>2)
			flag=false;

	cout << (flag ? "YES" : "NO") << endl;

}

