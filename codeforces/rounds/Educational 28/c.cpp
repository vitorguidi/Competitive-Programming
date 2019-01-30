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

ll acum[20000];
ll rmq[20000];

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n){
		cin >> acum[i];
		acum[i]+=acum[i-1];
	}

	for(int i=n+1;i<=2*n;i++)
		acum[i]+=acum[i-1];

	rmq[n+1]=n+1;

	for(int i=n;i>0;i--){

		if(acum[i-1]>acum[rmq[i+1]-1])
			rmq[i]=i;
	
		else
			rmq[i]=rmq[i+1];

	}

	ll best=-llINF;
	ll d1,d2,d3;

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){

			ll val = acum[i-1]-acum[j-1]+acum[rmq[j]];

			if(val>best){
				best=val;
				d1=i;
				d2=j;
				d3=rmq[j];
			}

		}
	}

	cout << d1-1 << " " << d2-1 << " " << d3-1 << endl;

}

