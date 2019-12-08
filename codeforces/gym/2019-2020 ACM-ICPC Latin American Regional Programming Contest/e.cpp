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

ll func(ll n, ll s){
	if(n < s) return n*(n-1)/2;
	else return s*(s-1)/2;
}

int main(){


	fastio;

	string s;
	cin >> s;
	ll n;
	cin >> n;

	ll ans = n*s.size();

	ll i = 0, j = s.size() - 1, tam, it;
	while(i < s.size() && s[i] == 'P'){
		i++;
	}

	while(j >= 0 && s[j] == 'P'){
		j--;
	}

	if(j < i){
		cout << 0 << endl;
		return 0;
	}

	tam = i+(s.size() - 1 - j);
	if(n-1 < tam) ans -= tam*n - (n-1)*n/2;
	else ans -= tam*(tam+1)/2;

	while(i < s.size()){
		while(s[i] == 'E') i++;
		
		if(i >= s.size())  break;

		tam = 0;
		while(s[i] == 'P'){
			tam++;
			i++;
		}

		if(i >= s.size()) break;

		if(n-1 < tam) ans -= tam*n - (n-1)*n/2;
		else ans -= tam*(tam+1)/2;
	}

	cout << ans << endl;
}
