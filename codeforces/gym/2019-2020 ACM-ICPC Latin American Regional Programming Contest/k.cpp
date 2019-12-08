#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(ll i=0;i<n;i++)
#define frr(i,n)	for(ll i=1;i<=n;i++)
#define frm(i, n)   for(ll i = n-1; i >= 0; i--)

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

ll pol[10010];
ll polAux[10010];

int main(){

	fastio;

	string s;
	cin >> s;

	int dg = 0;
	char ant = s[0];
	pol[0] = 1;

	frr(i, s.size() - 1){
		if(ant != s[i]){
			ant = s[i];
			dg++;

			polAux[0] = 0;
			frr(j, dg){
				polAux[j] = pol[j-1];
			}
			
			fr(j, dg){
				polAux[j] -= pol[j]*(2*i+1);
			}

			fr(j, dg+1) pol[j] = polAux[j];


		}
	}

	cout << dg << endl;
	if(s[s.size() - 1] == 'A'){
		frm(i, dg+1) cout << -pol[i] << " ";
		cout << endl;
	}
	else{
		frm(i, dg+1) cout << pol[i] << " ";
		cout << endl;
	}
}
