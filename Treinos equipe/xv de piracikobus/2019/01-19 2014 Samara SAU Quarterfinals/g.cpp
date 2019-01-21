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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int main(){

	fastio;
	int n,s;
	cin >> n >> s;
	ll v[50];
	v[0] = 1;
	ll aux;

	int j;

	frr(i,n){
		ll a;
		cin >> a;
		if(a*v[i-1] <= s){
			v[i] = a*v[i-1];
		}
		else{
			j = i;
			break;
		}

	}

	int ct = 0;
	for(int i = j-1;i >= 0;i--){
		ct += s/v[i];
		s = s%v[i];
	}

	cout << ct << endl;
		


}
