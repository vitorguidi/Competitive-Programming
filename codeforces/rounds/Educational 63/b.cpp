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
const int MOD = 1e9+7;

int main(){

	fastio;

	int n; cin >> n;
	string s; cin >> s;

	int mvs = n-11;

	int adv = mvs/2;
	int pet = mvs-adv;

	int cnt = 0;

	for(auto x : s)
		if(x=='8')
			cnt++;

	string aux;

	for(auto x : s){
		if(x!='8')
			aux.pb(x);
		else{
			if(!adv)
				aux.pb(x);
			else{
				cnt--;
				adv--;
			}
		}
	}

	if(!cnt){
		cout << "NO" << endl;
		return 0;
	}

	int antes = 0;
	for(int i=0;i<aux.size();i++){
		if(aux[i]!='8')	antes++;
		else			break;
	}

	cout << (pet>=antes ? "YES" : "NO") << endl;

}