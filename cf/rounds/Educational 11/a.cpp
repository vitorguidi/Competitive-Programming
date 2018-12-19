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

int check[100200];

int main(){
    
	fastio;

	int n; cin >> n;

	vi repo;

	for(ll i=2;i<=100100;i++){
		if(!check[i]){
			check[i]=1;
			repo.pb(i);
			for(ll j=i*i;j<=100100;j+=i)
				check[j]=1;
		}
	}

	vi v;

	fr(i,n){
		int x; cin >> x;
		v.pb(x);
	}

	vi ans;
	int cost=0;

	fr(i,n-1){
		
		ans.pb(v[i]);
		
		if(__gcd(v[i],v[i+1])!=1){
			
			for(auto x : repo)
				if( __gcd(x,v[i])==1 && __gcd(x,v[i+1])==1 ){
					ans.pb(x);
					cost++;
					break;
				}
			
		}
	}

	ans.pb(v[n-1]);

	cout << cost << endl;

	for(auto x : ans)
		cout << x << " ";
	gnl;

}

