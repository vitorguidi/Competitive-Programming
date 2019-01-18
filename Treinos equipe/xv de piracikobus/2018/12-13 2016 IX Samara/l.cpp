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

int n;

bool solve(vi& a, vi& b){

	int inia=n-1;
	int inib=n-1;

	int cnt=0;

	while(inia>=0){

		while(inib-1>=0 && b[inib]>=a[inia])
			inib--;

		if(inib>=0 && a[inia]>b[inib]){
			cnt++;
			inib--;
		}

		inia--;

	}

	return cnt>n/2;


}

int main(){

	fastio;

	cin >> n;

	vi a,b;

	fr(i,n){
		int x; cin >> x;
		a.pb(x);
	}
	fr(i,n){
		int x; cin >> x;
		b.pb(x);
	}
	sort(all(a));
	sort(all(b));

	int primeiro = solve(a,b);
	int segundo = solve(b,a);

	if(primeiro && segundo)
		puts("Both");
	else if(!primeiro && !segundo)
		puts("None");
	else if(primeiro && !segundo)
		puts("First");
	else if(!primeiro && segundo)
		puts("Second");

}