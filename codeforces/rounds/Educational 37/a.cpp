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

int v[220];
int check[220];

void solve(){

	int n,k; cin >> n >> k;
	vi taps;
	fr(i,k){
		int x; cin >> x;
		taps.pb(x);
	}

	for(int i=1;i<=n;i++){

		ms(check,0);

		for(auto x : taps){

			for(int j = x-(i-1);j<=x+(i-1);j++){
				if(j<1 || j>n)	continue;
				check[j]=1;
			}

		}

		bool flag = true;

		frr(i,n)
			if(!check[i])
				flag=false;

		if(flag){
			cout << i << endl;
			break;
		}


	}


}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	solve();

}

