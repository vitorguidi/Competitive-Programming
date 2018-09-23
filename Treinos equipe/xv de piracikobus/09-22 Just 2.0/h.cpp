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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi bago[55];
int v[100100];
int ans[100100];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	int n; cin >> n;

	frr(i,n){
		cin >> v[i];
		bago[v[i]].pb(i);
	}

	frr(i,n){

		int aux = INF;
		int cara = v[i]+1;
		
		for(int j=cara;j<=50;j++){
		
			auto it = upper_bound(all(bago[j]),i);
			if(it==bago[j].end())	continue;
		
			int ind = *it;
			aux=min(aux,ind);
		
		}

		ans[i] = (aux==INF ? -1 : v[aux]);

	}

	for(int i=1;i<=n;i++){
		cout << ans[i];
		if(i!=n)	cout << " ";
	}
	gnl;
    

}