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
int tempo,id[112345],sz[112345],his[112345];

int find(int a,int t){
	if(id[a]==a) return a;
	if(his[a]>t) return a;
	return find(id[a],t);
} 

void merge(int a,int b){
	a=find(a,tempo);
	b=find(b,tempo);
	if(a==b) return;

	if(sz[b]>sz[a]) swap(a,b);

	id[b]=a;
	his[b]=tempo;
	sz[a]+=sz[b];
}

int que_tempo(int a,int b){
	ll l,r,meio,bst;
	bst=llINF;
	l=0;
	r=tempo;

	while(l<=r){
		meio=(l+r)/2;

		if(find(a,meio)==find(b,meio)){
			bst=min(bst,meio);
			r=meio-1;
		}
		else
			l=meio+1;
	}
	return bst;
}

int main(){
	fastio;
	int n,m,q;
	cin>>n>>m>>q;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
		his[i]=0;
	}

	for(int i=m;i>0;i--){
		tempo++;
		for(int j=i;j<=n;j+=i)
			merge(i,j);
	}

	int a,b;
	while(q--){
		cin>>a>>b;
		cout<<que_tempo(a,b)<<endl;
	}


}
