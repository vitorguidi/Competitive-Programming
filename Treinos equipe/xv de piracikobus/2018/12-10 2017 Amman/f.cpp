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

int nxt[100100];
int aux[100100];
int last[100100];

void go(){

	vi v;
	int n,k;
	cin >> n >> k;

	fr(i,n)	aux[i]=n;

	fr(i,n){
		int x; cin >> x;
		v.pb(x);
	}

	map<int,int> m;

	int cnt=1;

	for(auto x : v)
		if(!m[x])
			m[x]=cnt++;
		
	

	for(int i=n-1;i>=0;i--){
		v[i]=m[v[i]];
		nxt[i]=aux[v[i]];
		aux[v[i]]=i;
	}

	map<int,int> vis;

	cnt=0;
	int ini=0;

	// fr(i,n)	dbg(nxt[i]);
	// gnl;

	set<pii> mesa;

	for(auto x : v){

		if(vis[x]){
			mesa.erase({last[x],x});
			mesa.insert({nxt[ini],x});
			last[x]=nxt[ini];
			ini++;
			continue;
		}

		cnt++;
		vis[x]=1;

		if(mesa.size()<k){
			last[x]=nxt[ini];
			mesa.insert({nxt[ini],x});
		}
		else{
			auto it = mesa.end();
			it--;
			pii aux = *it;
			mesa.erase(it);
			vis[aux.snd]=0;
			last[x]=nxt[ini];
			mesa.insert({nxt[ini],x});
		}

		ini++;

	}

	cout << cnt << endl;

}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	go();
	
}