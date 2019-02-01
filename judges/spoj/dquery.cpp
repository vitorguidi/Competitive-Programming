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
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

struct qry{
	int ind;
	int l;
	int r;
};

int resp[200100],v[30300],cnt[1001000];
int l,r,sz,ans;
qry qr[200200];

bool comp(qry a, qry b){
	if(a.l/sz==b.l/sz)	return a.r<b.r;
	return a.l/sz < b.l/sz; 
}

void add(int val){
	cnt[val]++;
	if(cnt[val]==1)
		ans++;
}

void remove(int val){
	cnt[val]--;
	if(cnt[val]==0)
		ans--;
}

int query(int x, int y){

	while(r<y)		add(v[++r]);
	while(l>x)		add(v[--l]);
	while(r>y)		remove(v[r--]);
	while(l<x)		remove(v[l++]);
	
	return ans;

}

int main(){

	int n;
	scanf("%d",&n);

	frr(i,n)
		scanf("%d",&v[i]);

	int q;
	scanf("%d",&q);

	sz=(int)floor(sqrt(q));
	
	fr(i,q){
		
		int x,y;
		scanf("%d %d",&x,&y);	
		qry aux;
		
		aux.ind=i;
		aux.l=x;
		aux.r=y;
		
		qr[i]=(aux);
	
	}

	sort(qr,qr+q,comp);

	fr(i,q)
		resp[qr[i].ind]=query(qr[i].l,qr[i].r);

	fr(i,q)
		printf("%d\n",resp[i]);	

}