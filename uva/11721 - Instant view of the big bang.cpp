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
const ll llINF = 0x3f3f3f3f3f3f3f;

int d[1010];	//distancia[cidade][passadas]	
int clk=1;
int t; 

void solve(){

	int n,m; 
	cin >> n >> m;

	ms(d,INF);
	d[0]=0;

	vector<tuple<int,int,int>> edges;

	frr(i,m){
		int ori,des,cost;
		cin >> ori >> des >> cost;
		edges.pb(make_tuple(des,ori,cost));
	}
	
	frr(i,n-1){


		for(auto x : edges){
			
			int ori = get<0>(x);
			int des = get<1>(x);
			int cost = get<2>(x);

			if(d[des]>d[ori]+cost)
				d[des]=d[ori]+cost;

		}

	}

	queue<int> caras;
	vi aux;

	bool flag = false;

	for(auto x : edges){
		
		int ori = get<0>(x);
		int des = get<1>(x);
		int cost = get<2>(x);

		if(d[des]>d[ori]+cost){
			aux.pb(des);
			caras.push(des);
		}

	}

	ms(d,INF);
	for(auto x : aux)
		d[x]=0;

	vi nodes[1010];

	for(auto x : edges)
		nodes[get<0>(x)].pb( get<1>(x)  );

	while(!caras.empty()){

		int pai = caras.front();
		caras.pop();

		for(auto x : nodes[pai]){

			if(d[x]>d[pai]+1){
				d[x]=d[pai]+1;
				caras.push(x);
			}

		}

	}

	cout << "Case " << clk++ << ": ";

	if(aux.empty()){
		cout << "impossible" << endl;
		return;
	}

	vi ans;

	fr(i,n)
		if(d[i]!=INF)
			ans.pb(i);


	int len = ans.size();
	fr(i,len){
		cout << ans[i];
		if(i!=len-1)
			cout << " ";
	}
	gnl;

}

int main(){

	fastio;

	cin >> t;
	frr(i,t)
		solve();

}