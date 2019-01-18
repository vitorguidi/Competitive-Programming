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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

void solve(){
	ll n; cin >> n;

	if(n%2){
		cout<<"Impossible"<<endl;
		return;
	}

	ll A,B,C;
	A=n;B=n;C=n;

	A/=2;
	
	if((C+A)%2){
		cout<<"Impossible"<<endl;
		return;
	}
	C+=A;
	C/=2;
	
	if((B+C)%2){
		cout<<"Impossible"<<endl;
		return;
	}
	B+=C;
	B/=2;

	A+=B;

	cout<<A<<' '<<B<<' '<<C<<endl;

}

int main(){
	fastio;
	int t; cin >> t;
	while(t--)	solve();
}