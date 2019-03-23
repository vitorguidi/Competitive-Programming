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

int v[10100];

int main(){
    
	fastio;

	int n; cin >> n;
	frr(i,n)	cin >> v[i];

	int page = 1;
	int dest=0;
	int cnt=0;

	while(page<=n){
		cnt++;
		dest=max(dest,v[page]);
		while(page<=dest){
			dest=max(dest,v[page]);
			page++;
		}
	}	

	cout << cnt << endl;

}