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

int calc(int x, int y){
	return (x+y-1)/y;
}

int main(){
    
	fastio;

	int n,k; cin >> n >> k;

	frr(i,n){
		int x; cin >> x;
		v[x]++;
	}

	vi freq;

	frr(i,100)
		if(v[i])
			freq.pb(v[i]);

	fr(i,freq.size())
		freq[i]=calc(freq[i],k)*k;


	int min_dishes=0;

	for(auto x : freq)
		min_dishes=max(min_dishes,calc(x,k));

	int multi=min_dishes*k;

	fr(i,freq.size())
		freq[i]=calc(freq[i],multi)*multi;

	int total=0;

	for(auto x : freq)
		total+=x;

	cout << total-n << endl;

}

