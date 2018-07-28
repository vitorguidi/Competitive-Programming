#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+9;

struct intv{
	int l,r,val;
};

struct node{
	intv prefix,suffix,whole,best;
};

int v[50500];
node segtree[200200];

intv maximize(intv a, intv b){
	if(a.val>=b.val)	return a;
	return b;
}

intv join(intv a, intv b){

	intv aux;

	if(a.l>b.l)
		swap(a,b);

	if(a.r=b.l-1){
		aux.val=a.val+b.val;
		aux.l=a.l;
		aux.r=b.r;	
	}
	else{
		aux.val=-INF;
		aux.r=-INF;
		aux.l=INF;
	}
	
	return aux;
}

node merge(node a, node b){

	node aux;

	intv joint,new_suf,new_pref,new_whole,new_best;

	vector<intv> candidates;

	candidates.pb(a.best);
	candidates.pb(b.best);
	candidates.pb(a.whole);
	candidates.pb(b.whole);

	joint=join(a.suffix,b.prefix);
	candidates.pb(joint);

	new_pref=join(a.whole,b.prefix);
	new_pref=maximize(new_pref,a.prefix);
	candidates.pb(new_pref);


	new_suf=join(b.whole,a.suffix);
	new_suf=maximize(new_suf,b.suffix);
	candidates.pb(new_suf);

	new_whole=join(a.whole,b.whole);
	candidates.pb(new_whole);

	new_best.val=-INF;

	for(auto x : candidates)
		new_best=maximize(new_best,x);

	aux.suffix=new_suf;
	aux.prefix=new_pref;
	aux.whole=new_whole;
	aux.best=new_best;

	return aux;

}

void build(int no,int l, int r){

	if(l==r){
		node aux;
		intv temp;
		temp.l=l;	temp.r=r;	temp.val=v[l];
		aux.prefix = aux.suffix = aux.whole = aux.best = temp;
		segtree[no]=aux;
		return;
	}

	int mid = (l+r)/2;

	build(2*no,l,mid); build(2*no+1,mid+1,r);
	segtree[no]=merge(segtree[2*no],segtree[2*no+1]);

}

void update(int no, int l, int r, int ind, int val){

	if(l==r){
		node aux;
		intv temp;
		v[ind]=val;
		temp.val=v[ind];
		temp.l=l;
		temp.r=r;
		aux.whole=aux.suffix=aux.prefix=aux.best=temp;
		segtree[no]=aux;
		return;
	}

	int mid = (l+r)/2;

	if(l<=ind && ind<=mid)
		update(2*no,l,mid,ind,val);
	else
		update(2*no+1,mid+1,r,ind,val);

	segtree[no]=merge(segtree[2*no],segtree[2*no+1]);

}

node query(int no, int l, int r, int a, int b){

	if(l>r || r<a || l>b){
		node aux;
		intv tmp;
		tmp.val=-INF;
		tmp.l=INF;
		tmp.r=-INF;
		aux.best=aux.whole=aux.prefix=aux.suffix=tmp;
		return aux;
	}

	if(a<=l && r<=b)	return segtree[no];

	int mid= (l+r)/2;

	node left = query(2*no,l,mid,a,b);
	node right = query(2*no+1,mid+1,r,a,b);
 
	if(left.best.val==-INF)	return right;
	if(right.best.val==-INF)	return left;
	
	return(merge(left,right));
}

int main(){

	int n; cin >> n;

	frr(i,n)	cin >> v[i];

	build(1,1,n);

	int q; cin >> q;

	int x,y,z;

	// x.l=1;x.r=1;x.val=2;
	// y.l=2;y.r=2;y.val=3;
	// z=join(x,y);
	// cout << z.val << endl;

	fr(i,q){
		cin >> x >> y >> z;
		if(!x)
			update(1,1,n,y,z);
		else{
			node aux = query(1,1,n,y,z); 
			cout << aux.best.val << endl;
		}
	}


}