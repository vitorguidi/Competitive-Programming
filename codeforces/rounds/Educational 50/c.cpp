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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<ll> filler;

void build(int ind, int sum, ll num){


	if(ind==18 || sum==3){
		filler.pb(num);
		return;
	}

	fr(i,10){
		ll aux=i* (ll)pow(10,ind);
		if(i==0)
			build(ind+1,sum,num);
		else
			build(ind+1,sum+1,num+aux);
	}	

}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	build(0,0,0);
	sort(all(filler));
	filler.pb( (ll)1e18 );

	int t; cin >> t;

	while(t--){
		ll l,r;
		cin >> l >> r;
		auto right = upper_bound(all(filler),r);
		auto left = lower_bound(all(filler),l);
		cout << right - left << endl;

	}


}

