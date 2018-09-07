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
#define pira cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll q; cin >> q;
	while(q--){

		ll x,y,k;
		cin >> x >> y >> k;

		ll passos = min(x,y);
		x-=passos;
		y-=passos;

		ll falta = x+y;
		ll pending = k-passos;

		if(passos+falta>k){
			cout << -1 << endl;
			continue;
		}

		if(pending%2==0){

			if(falta%2==1){
				passos--;
				falta--;
			}

		
		}
		else{

			if(falta%2==1)
				pending--;
			else{
				passos--;
				pending--;
			}

		}

			passos+=pending;
		cout << passos  << endl;

	}

}

