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

int n,v[100100];

int main(){
    
	fastio;

	cin >> n;
	int mx=-INF;
	
	frr(i,n){
		cin >> v[i];
		mx=max(mx,v[i]);
	}

	int end=1;
	int best = 0;

	for(int i=1;i<=n;i++){
		
		if(v[i]!=mx)	continue;
		int cnt=1;
		while(i+1<=n && v[i+1]==mx){
			i++;cnt++;
		}
		best=max(best,cnt);
	
	}

	cout << best << endl;

}