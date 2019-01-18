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

map<vi,int> freq;
bool check = false;
vi gab;

void solve(vi& a){
	
	int len = a.size();

	if(len==1 || check)	return;

	for(int i=0;i<len-1;i++){
		
		vi troll;
		
		int left = i+1;
		int right = len-left;
		int new_len=max(right,left);
		
		troll.resize(new_len);

		vi from_left;
		vi from_right;

		fr(i,left)
			from_left.pb(a[i]);

		for(int i=left;i<len;i++)
			from_right.pb(a[i]);

		reverse(all(from_left));

		fr(i,from_left.size())
			troll[new_len-1-i]+=from_left[i];
		fr(i,from_right.size())
			troll[new_len-1-i]+=from_right[i];

		if(troll==gab){
			check=true;
			return;
		}
		reverse(all(troll));
		
		if(troll==gab){
			check=true;
			return;
		}
		reverse(all(troll));

		solve(troll);

	}

}

int main(){

	fastio;
	vi aux;

	int n; cin >> n;
	fr(i,n){
		int x; cin >> x;
		aux.pb(x);
	}
	
	int k; cin >> k;
	
	fr(i,k){
		int x; cin >> x;
		gab.pb(x);
	}

	if(aux==gab)
		check=true;
	reverse(all(aux));
	if(aux==gab)
		check=true;
	reverse(all(aux));

	solve(aux);

	if(check)
		puts("S");
	else
		puts("N");

}
