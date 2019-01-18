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

int main(){

	fastio;
	int T;
	cin >> T;
	string s,t;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		getline(cin,t);

		int n;
		n = s.size();

		bool ok = true;
		int ct = 0;
		int par = 0;
		
		fr(i,(n/2) + 1){
			int j,comp;

			if(par%2 == 0)
				j = i;
			else
				j = n-1-i;
			comp = n -1 -j;
			//dbg(j);

			if(s[j] == t[i]) continue;
			if(s[j]!=t[i]){
				if(s[comp] == t[i] && s[j] == t[n-1-i]){
					ct++;
					char aux = s[comp];
					s[comp] = s[j];
					s[j] = aux;
					par++;
		//			dbg(s);
		//			dbg(t);
					//olar;
				}
				else{
					ok = false;
				}
			}
		}
		//dbg(ct);
		if(ok){
			cout << ct;
		}
		else
			cout << -1;
		gnl;


	}

}