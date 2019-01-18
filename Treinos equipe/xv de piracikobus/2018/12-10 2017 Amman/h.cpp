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

int v[1000100];
int n,s;


void imprime(){
	if(v[0] == 0){
		cout << -1 <<endl;
		return;
	}
	fr(i,n) cout <<v[i];
	gnl;
}

void solve(){

	cin >> n >> s;

	if(s%2==1 && n%2==0){
		cout << -1 << endl;
		return;
	}

	if(9*n<s){
		cout << -1 << endl;
		return;
	}

	ms(v,0);

	int k = 0;

	while(s>=18){
		v[k] = 9;
		v[n-1-k] = 9;
		s-=18;
		k++;
	}
	if(s==0){ 
		imprime();
		return;
	}

	if(k == n -1 -k){
		v[n/2] = s;
	}
	else{
		v[k] = s/2;
		v[n-1-k] = s/2;
		if (s%2 == 1){
			v[n/2] = 1;
		}
	}

	imprime();

}



int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}

}
