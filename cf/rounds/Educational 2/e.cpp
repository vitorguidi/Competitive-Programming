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

int sz;
int clk=1;

int colors[100100];

int vis[100100];
int pre[100100],pos[100100];
vi nodes[100100];

int l,r;
ll soma;
ll mx;

ll v[200200];			//guarda cores
ll freq[200100];		//frequencia individual das cores
ll acum[200100];		//acumulador das flags

void dfs(int x){
	vis[x]=1;
	pre[x]=clk++;
	for(auto y : nodes[x]){
		if(vis[y])	continue;
		dfs(y);
	}
	pos[x]=clk++;
}

struct query{
	int l;
	int r;
	int ind;
};

void add(int pos){

	if(v[pos]==0)	return;

	freq[ v[pos] ]++;		//incremento a frequencia da cor
	acum[ freq[v[pos]] ]+=v[pos];	//incrementa a soma de cores relativa a frequencia maior
	
	if(freq[v[pos]]>mx){
		mx++;
		mx=freq[v[pos]];
	}

	soma=acum[mx];

}

void remove(int pos){


	if(v[pos]==0)	return;

	acum[ freq[v[pos]] ]-=v[pos];
	freq[v[pos]]--;
	
	if(acum[ mx ]==0)
		mx--;

	soma=acum[mx];

}

ll solve(int x, int y){

	while(r<y)
		add(++r);
	while(l>x)
		add(--l);
	while(l<x)
		remove(l++);
	while(r>y)
		remove(r--);

	return soma;

}

bool comp(query a, query b){
	if(a.l/sz==b.l/sz)
		return a.r<b.r;
	else
		return a.l/sz<b.l/sz;
}

int main(){

	fastio;

	int n; cin >> n;
	frr(i,n)	cin >> colors[i];

	sz=(int)floor(sqrt(n));

	fr(i,n-1){
		int a,b; cin >> a >> b;
		nodes[a].pb(b);
		nodes[b].pb(a);
	}

	dfs(1);
	
	vector<query> qr;

	frr(i,n){
		query aux;
		v[pre[i]]=colors[i];
		v[pos[i]]=colors[i];
		aux.l=pre[i];
		aux.r=pos[i];
		aux.ind=i;
		qr.pb(aux);
	}

	sort(all(qr),comp);

	vector<pll> ans;

	for(auto x : qr)
		ans.pb({x.ind,solve(x.l,x.r)});

	sort(all(ans));

	for(auto caras : ans){
		cout << caras.snd << " ";
	}
	gnl;

}