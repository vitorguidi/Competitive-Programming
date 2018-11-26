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

ll cnt[10000];
ll w[10000];
ll brute[10000][110];
int n,m,q;

int numberfy(string x){

	reverse(all(x));

	int base=1;

	int ans = 0;

	for(int i=0;i<n;i++){
		ans+=base*(x[i]-'0');
		base*=2;
	}

	return ans;

}

ll calc(int i, int j){

	ll ans = 0;

	for(int k=0;k<n;k++)
		if( ((1<<k)&i) == ((1<<k)&j) )
			ans+=w[k];

	return ans;
}

int main(){
    
	fastio;

	cin >> n >> m >> q;

	fr(i,n)	cin >> w[n-1-i];

	fr(i,m){
		string x; cin >> x;
		cnt[numberfy(x)]++;
	}

	fr(i,1<<n){
		fr(j,1<<n){
			int wu = calc(i,j);
			if(wu>100)	continue;
			brute[i][wu]+=cnt[j];
		}
	}

	fr(i,1<<n)
		for(int j=1;j<=100;j++)
			brute[i][j]+=brute[i][j-1];
	

	fr(i,q){
		string x;
		int k;
		cin >> x >> k;
		cout << brute[numberfy(x)][k] << endl;
	}

}