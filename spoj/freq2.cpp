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
 
int cnt[100100];
int freq[100100];
int v[100100];
int out[100100];
int sz,l,r;
int ans;
set<pii> aux;
 
struct qry{
	int l;
	int r;
	int ind;
};
 
bool comp(qry a, qry b){
	if(a.l/sz==b.l/sz)	return a.r<b.r;
	return a.l/sz<b.l/sz;
}
 
void add(int ind){
 
	int val = v[ind];
	freq[cnt[val]]--;
	cnt[val]++;
	freq[cnt[val]]++;
	
	if(freq[ans+1])
		++ans;
 
}
 
void remove(int ind){
 
	int val = v[ind];
	freq[cnt[val]]--;
	cnt[val]--;
	freq[cnt[val]]++;	
	if(!freq[ans] && ans>0)
		ans--;
}
 
int query(int x, int y){
 
	while(l>x)
		add(--l);
	while(r<y)
		add(++r);
	while(l<x)
		remove(l++);
	while(r>y)
		remove(r--);
	return ans;
 
}
 
void solve(int n, int q){
 
	int id=1;
	int ans=0;
	l=r=0;
	ms(cnt,0);
	ms(freq,0);
 
	sz=(int)floor(sqrt(n));
	map<int,int> crd;
 
	frr(i,n){
		scanf("%d",&v[i]);
		if(!crd[v[i]])
			crd[v[i]]=id++;
		v[i]=crd[v[i]];
	}
 
	vector<qry> queries;
	fr(i,q){
		qry aux;
		scanf("%d %d",&aux.l,&aux.r);
		aux.ind=i;
		aux.l++;aux.r++;
		queries.pb(aux);
	}
 
	sort(all(queries),comp);
 
	fr(i,q)
		out[queries[i].ind]=query(queries[i].l,queries[i].r);
 
	fr(i,q)
		printf("%d\n",out[i]);
 
}
 
int main(){
 
	int n,q;
	int t=1;
	while(t--){
		scanf("%d",&n);
		if(!n)	break;
		scanf("%d",&q);
		solve(n,q);
	}
 
} 