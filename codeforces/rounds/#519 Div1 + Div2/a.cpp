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

int v[200];

int main(){
    
	fastio;

	int n; cin >> n;
	int mx=0;
	fr(i,n){
		cin >> v[i];
		mx=max(v[i],mx);
	}

	ll v1=0;
	ll v2=0;

	ll best = INF;

	for(int k=mx;k<=100000;k++){
		
		v1=0;
		v2=0;
		bool flag = true;

		for(int j=0;j<n;j++){
		
			v1+=v[j];
		
			if(k-v[j]<0)
				flag=false;
		
			v2+=k-v[j];
		}

		if(!flag)	continue;
		if(v2>v1)	best=min<ll>(best,k);
	}

	cout << best << endl;

}

