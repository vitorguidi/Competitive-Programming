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

ll v[200200];
ll mnr[200200];
int n;

int main(){
    
	fastio;

	cin >> n;

	frr(i,n)	cin >> v[i];

	mnr[n+1]=INF;

	for(int i=n;i>0;i--){
		ll sou = min(mnr[i+1]-1,v[i]);
		v[i]=max(0ll,sou);
		mnr[i]=min(mnr[i+1],v[i]);
	}

	ll ans = 0;

	frr(i,n)	ans+=v[i];

	cout << ans << endl;


}