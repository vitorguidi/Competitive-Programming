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
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

typedef tuple<int,int,int,int> event;
vector<event> ev;

int soma[160600];
int full[160600];

int n;

int ask(int node, int l, int r, int a, int b){

	if(r<a || l>b)
		return 0;

	if(a<=l && r<=b){
		if(full[node])
			return r-l+1;
		if(l!=r)
			return soma[2*node]+soma[2*node+1]; 
		else
			return 0;
	}

	int mid = (l+r)>>1;

	return ask(2*node,l,mid,a,b) + ask(2*node+1,mid+1,r,a,b);

}

void update(int node, int l, int r, int a, int b, int val){

	if(r<a || l>b)
		return;

	if(a<=l && r<=b){

		full[node]+=val;

		if(full[node])
			soma[node]=r-l+1;
		else if(l==r)
			soma[node]=0;
		else
			soma[node]=soma[2*node]+soma[2*node+1];
	
		return;
	}

	int mid = (l+r)>>1;

	update(2*node,l,mid,a,b,val);
	update(2*node+1,mid+1,r,a,b,val);

	soma[node]=soma[2*node]+soma[2*node+1];
	if(full[node])
		soma[node]=r-l+1;


}

int query(){
	return ask(1,1,40000,1,40000);
}

void add(int l, int r){
	update(1,1,40000,l,r,1);
}


void remove(int l, int r){
	update(1,1,40000,l,r,-1);
}

int main(){

	fastio;

	cin >> n;

	int ori = INF;

	frr(i,n){
		int xl,yl,xr,yr;
		cin >> xl >> yl >> xr >> yr;
		xl++;yl++;xr++;yr++;
		ori=min(ori,xl);
		ev.pb(make_tuple(xl,0,yl,yr));
		ev.pb(make_tuple(xr,1,yl,yr));
	}


	sort(all(ev));

	int ini=0;

	ll ans = 0;


	while(ini<2*n){

		int val = get<0>(ev[ini]);

		ans+=(val-ori)*query();
		ori=val;

		while(ini<2*n && get<0>(ev[ini])==val){
			int yl = get<2>(ev[ini]);
			int yr = get<3>(ev[ini]);
			int op = get<1>(ev[ini]);
			if(op==0)
				add(yl+1,yr);
			else
				remove(yl+1,yr);
			ini++;

		}

	}

	cout << ans << endl;

}