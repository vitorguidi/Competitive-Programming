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

int v[100200];
int seg[400400];

void build(int node, int l, int r){

	if(l==r){
		seg[node]=l;
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	if(v[seg[2*node]] >= v[seg[2*node+1]])	
		seg[node]=seg[2*node];
	else
		seg[node]=seg[2*node+1];

}

void update(int node, int l, int r, int ind, int val){

	if(l==r){
		v[l]=val;
		seg[node]=l;
		return;
	}

	int mid = (l+r)/2;

	if(ind<=mid)	update(2*node,l,mid,ind,val);
	else			update(2*node+1,mid+1,r,ind,val);

	if(v[seg[2*node]]>=v[seg[2*node+1]])	seg[node]=seg[2*node];
	else									seg[node]=seg[2*node+1];

}

int query(int node, int l, int r,int a, int b){

	if(l>b || r<a)	return 0;

	if(a<=l && r<=b)	return seg[node];

	int mid = (l+r)/2;

	int lc = query(2*node,l,mid,a,b);
	int rc = query(2*node+1,mid+1,r,a,b);

	if(v[lc]>=v[rc])	return lc;
	else				return rc;

}

int main(){

	fastio;

	int n; cin >> n;

	v[0]=-INF;

	frr(i,n)	cin >> v[i];

	build(1,1,n);

	int q; cin >> q;

	frr(i,q){
	
		char op;
		int l,r; cin >> op >> l >> r;

		if(op=='U')
			update(1,1,n,l,r);
		else{
			int primeiro = query(1,1,n,l,r);
			int aux1 = query(1,1,n,l,primeiro-1);
			int aux2 = query(1,1,n,primeiro+1,r);
			int segundo;
			if(v[aux1]>=v[aux2])	segundo=aux1;
			else					segundo=aux2;
			cout << v[primeiro] + v[segundo] << endl;
		}

	}

}