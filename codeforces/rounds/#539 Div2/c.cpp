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

int v[300300];
int n;

ll bit[1<<22][2];

void update(int ind, int val, int par){
	for(int i=ind;i<(1<<22);i+=i&-i)
		bit[i][par]+=val;
}

ll query(int ind, int par){
	ll ans = 0;
	for(int i=ind;i>0;i-=i&-i)	ans+=bit[i][par];
	return ans;
}

int main(){
    
	fastio;

	cin >> n;
	frr(i,n){
		cin >> v[i];
		v[i]^=v[i-1];
	}
	frr(i,n)	v[i]++;

	ll ans = 0;

	// frr(i,n)	cout << v[i] << " ";
	// gnl;

	update(1,1,0);update(2,-1,0);
	update(1,1,1);update(2,-1,1);
	update(v[1],1,1);update(v[1]+1,-1,1);

	for(int i=2;i<=n;i++){

		ll aux = query(v[i],(i%2));
	
		ans+=aux;

		if(i%2 && v[i]==1)
			ans--;

		update(v[i],1,i%2);
		update(v[i]+1,-1,i%2);

	}

	cout << ans << endl;

}