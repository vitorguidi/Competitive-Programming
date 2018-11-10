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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll v[100100];
ll id[100100];

ll n,m,l;
ll ans;

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)	return;
	id[x]=y;
}

void update(int cara, ll val){

	v[cara]+=val;
	if(v[cara]-val>l)	return;

	if(v[cara]-val<=l && v[cara]>l)
		ans++;

	if(cara-1>0 && v[cara-1]>l && v[cara]>l && find(cara)!=find(cara-1)){
		ans--;
		join(cara,cara-1);
	}

	if(cara+1<=n && v[cara]>l && v[cara+1]>l && find(cara)!=find(cara+1)){
		ans--;
		join(cara,cara+1);
	}

}

int main(){
    
	fastio;

	cin >> n >> m >> l;

	frr(i,n){
		
		id[i]=i;
		cin >> v[i];

		if(v[i]>l)
			ans++;

		if(i>1 && v[i-1]>l && v[i]>l){
			ans--;
			join(i,i-1);
		}
	
	}

	fr(i,m){

		int op;
		cin >> op;
		
		if(!op)	cout << ans << endl;
		
		else{
			int cara,val;
			cin >> cara >> val;
			update(cara,val);
		}

	}




}

