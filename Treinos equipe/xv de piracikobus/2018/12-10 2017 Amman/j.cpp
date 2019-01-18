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
	string s;
	getline(cin,s);
	while(T--){
		getline(cin,s);
		int esp = 0;

		fr(i,s.size()){
			if(s[i] == ' ')
				esp++;
		}

		bool ok = false;
		int n = s.size();
		for(int i = 2;i<= esp + 1;i++){
			if((n - i + 1)%i == 0){
				int tam = (n -i + 1)/i;
				int j = tam;
				bool a = false;
				while(j<n){
					if(s[j]!=' ') a = true;
					j+= tam + 1;
				}
				if (!a) ok =true;
			}
 		}

 		if(ok) cout <<"YES";
 		else cout <<"NO";

 		gnl;

		
	}

}
