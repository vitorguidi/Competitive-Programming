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

int v[110];
int acum_one[110];
int acum_zero[110];

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n){
		cin >> v[i];
		if(v[i])	acum_one[i]++;
		else		acum_zero[i]++;
		acum_one[i]+=acum_one[i-1];
		acum_zero[i]+=acum_zero[i-1];
	}

	int ans = max(acum_zero[n],acum_one[n]);

	int aux = 0;
	
	for(int i=1;i<=n;i++){
		if(v[i]==0)
			aux++;
		ans=max(ans,aux+acum_one[n]-acum_one[i-1]);
	}

	cout << ans << endl;

}

