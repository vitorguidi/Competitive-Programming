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

int main(){
    
	fastio;

	int n; cin >> n;

	int v[2010];

	frr(i,n)	cin >> v[i];

	int cnt=0;

	frr(i,n){
		frr(j,n){
			if(i==j)	continue;
			if(i<j && v[i]>v[j])	cnt++;
		}
	}

	cnt%=2;

	int q; cin >> q;

	fr(i,q){
		int l,r; cin >> l >> r;
		int amt = (r-l+1)/2;
		amt%=2;
		cnt+=amt;
		cnt%=2;
		if(cnt)	puts("odd");
		else	puts("even");
	}

}

