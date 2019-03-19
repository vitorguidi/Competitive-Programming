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
#define otp(x) cout << x << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int maxn = 1e7+9;

struct node{
	int id;
	int num;
	int freq[9];
};

int n,q;
node seg[400400];
int lazy[400400];

node bode(){
	node aux;
	aux.num=-INF;
	return aux;
}

node merge(node a, node b){
	
	if(a.num==-INF)
		return b;
	if(b.num==-INF)
		return a;

	node aux;

	fr(i,9)
		aux.freq[i]=a.freq[i]+b.freq[i];

	int id=-1;
	int acum = 0;

	fr(i,9){
		if(aux.freq[i]>acum){
			id=i;
			acum=aux.freq[i];
		}
		else if(aux.freq[i]==acum)
			id=i;
	}

	aux.id=id;
	aux.num=acum;

	return aux;

}

void commit(int node,int val){
	
	int aux[9];
	ms(aux,0);

	fr(i,9)
		aux[(i+val)%9]+=seg[node].freq[i];
	
	int id=-1;
	int acum = 0;

	fr(i,9){
	
		if(aux[i]>acum){
			acum=aux[i];
			id=i;
		}
	
		else if(aux[i]==acum)
			id=i;
	
		seg[node].id=id;
		seg[node].num=acum;
		seg[node].freq[i]=aux[i];
	
	}

}

void build(int node, int l, int r){
	
	if(l==r){
		seg[node].num=1;
		seg[node].id=1;
		seg[node].freq[1]=1;
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	seg[node]=merge(seg[2*node],seg[2*node+1]);

}

node query(int node, int l, int r, int a, int b){

	int mid = (l+r)/2;

	if(lazy[node]){

		commit(node,lazy[node]);
		
		if(l!=r){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}

		lazy[node]=0;

	}

	if(r<a || l>b || l>r)	return	bode();

	else if(a<=l && r<=b)	return seg[node];

	else return merge( query(2*node,l,mid,a,b) , query(2*node+1,mid+1,r,a,b) );

}

void update(int node, int l, int r, int a, int b, int val){

	int mid=(l+r)/2;
	
	if(lazy[node]){
	
		commit(node,lazy[node]);
	
		if(l!=r){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
	
		lazy[node]=0;
	
	}

	if(r<a || l>b || l>r)
		return;

	else if(a<=l && r<=b){

		commit(node,val);
		
		if(l!=r){
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}

	}

	else{

		update(2*node,l,mid,a,b,val);
		update(2*node+1,mid+1,r,a,b,val);
		
		seg[node]=merge(seg[2*node],seg[2*node+1]);
	
	}

}

int main(){

	cin >> n >> q;

	build(1,1,n);

	fr(i,q){
		int x,y;
		cin >> x >> y;
		x++;y++;
		node aux = query(1,1,n,x,y);
		update(1,1,n,x,y,aux.id);
	}

	frr(i,n){
		node aux = query(1,1,n,i,i);
		cout << aux.id << endl;
	}


}