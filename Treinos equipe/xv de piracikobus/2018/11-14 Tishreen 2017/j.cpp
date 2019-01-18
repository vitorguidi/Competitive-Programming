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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll id[1123],sz[1123];
pair<ll,pll> hole[1123];
ll n,w,l;

ll find(ll n){
		if(id[n]==n)
			return n; 
		return(id[n]=find(id[n]));

	}
void join(ll a, ll b){
		a=find(a); 
		b=find(b); 
		if(sz[b]>sz[a])
			swap(a,b); 
		id[b]=a; 
		sz[a]+=sz[b];
	}
bool intersec(ll i, ll j){
	ll r1,r2,dx,dy; 
	r1=hole[i].fst;
	r2=hole[j].fst;
	dx=hole[i].snd.fst - hole[j].snd.fst;
	dy=hole[i].snd.snd - hole[j].snd.snd;
	return( (dx*dx + dy*dy )   <=    ( r1*r1 + 2ll*r1*r2 + r2*r2 )    );
}	

bool test(ll aux){
	bool p1,p2;
	p1=p2=0; 
	fr(i,n)
		if(find(i)==aux){
			if(hole[i].snd.fst <= hole[i].fst)
				p1=1; 
			if(w-hole[i].snd.fst <= hole[i].fst)
				p2=1;
		}
	return(p1 && p2);	

}
void solve(){
	ll freq[1123]; 
	cin>>n>>w>>l; 
	fr(i,n){
		id[i]=i; 
		sz[i]=1;
		freq[i]=0;
	}	
	ll a,b,c;
	fr(i,n){
		cin>>a>>b>>c; 
		hole[i].fst=c; 
		hole[i].snd.fst=a;
		hole[i].snd.snd=b;

	} 
	fr(i,n){
		for(ll j=i+1;j<n;j++){
			if(intersec(i,j) && find(i)!=find(j))
				join(i,j);
				}
	} 
	
	ll tot=0; 
	fr(i,n){
		ll aux= find(i);
		if(freq[aux]==0){
			if(test(aux))
				tot++; 
			freq[aux]=1;
		}
	}
	cout<<tot<<endl;

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();



}
