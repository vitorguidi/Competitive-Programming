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

int main(){

	fastio;
	int n; cin>>n;
	vector<ll> v, acum;
	v.resize(n);
	acum.resize(n+1);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end());

	ll acuml = 0;
	ll acumr = v[n-1];

	ll sum = 0;

	int pr = n-2;
	int pl = 0;

	int n_left = 0;
	int n_right = 1;

	for(int i=2;i<=n;i++) {
		if(i%2) {
			// cout << v[pr] << endl;
			sum += acumr - n_right*v[pr];
			sum += n_left*v[pr] - acuml;
			n_right++;
			acumr+=v[pr];
			pr--;
		} else {
			// cout << v[pl] << endl;
			sum += acumr - n_right*v[pl];
			sum += n_left*v[pl] - acuml;
			n_left++;
			acuml+=v[pl];
			pl++;
		}
		cout << sum << " ";
	}
	cout << endl;

	

	return 0;

}
