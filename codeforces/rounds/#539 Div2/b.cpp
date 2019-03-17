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

int v[100100];
int mxl[100100];
int mxr[100100];

int main(){
    
	fastio;

	int n; cin >> n;

	ll sum = 0;
	int best = INF;

	frr(i,n){
		cin >> v[i];
		sum+=v[i];
	}

	v[0]=v[n+1]=INF;
	mxl[0]=mxr[n+1]=INF;

	for(int i=1;i<=n;i++){
		mxl[i]=min(v[i-1],mxl[i-1]);
	}
	for(int i=n;i>0;i--){
		mxr[i]=min(mxr[i+1],v[i+1]);
	}

	frr(i,n){
		frr(j,v[i]){

			if(v[i]%j!=0)	continue;

			int cara = min(mxl[i],mxr[i]);
			int delta = v[i]/j  + cara*j - v[i]- cara;
			best=min(best,delta);
		
		}

	}

	cout << sum+best << endl;

}