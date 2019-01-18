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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi seq;
int n,s;
	
int conta(ll x){

	int ans = 0;

	fr(i,n){
		if(x&(1<<i))
			ans++;
	}

	return ans;

}

bool check(ll x){
	
	vi aux;
	int sum = 0;
	
	fr(i,n){
		if(x&(1<<i)){
			aux.pb(seq[i]);
			sum+=seq[i];
		}
	}

	sort(all(aux));
	int mn = aux[0];
	
	if(sum-mn<s && sum>=s)
		return true;
	
	return false;


}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		cin >> n >> s;
		
		seq.clear();
	
		fr(i,n){
			int aux;
			cin >> aux;
			seq.pb(aux);
		}

		int ans = 0;
		
		for(ll i=1;i<(1<<n);i++){
			if(check(i))
				ans=max(ans,conta(i));
		}

		cout<< ans << endl;

	}

}