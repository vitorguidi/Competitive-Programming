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

int main() {

	fastio;

	int t; cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
	
		vi a,b;
		fr(i,n){
			int x;
			cin >> x;
			a.pb(x);
		}
		fr(i,n){
			int x;
			cin >> x;
			b.pb(x);
		}

		vector<vi> aux;

		fr(i,n){
			b[i]-=a[i];
		}


		bool flag=true;
		for(auto x : b){
			if(x<0) flag=false;
		}

		if(!flag){
			cout << "NO" << endl;
			continue;
		}

		int ini=0;
		while(ini<n){
			if(b[ini]==0){
				ini++;continue;
			}
			else{
				vi buffer;
				while(b[ini]!=0 && ini<n){
					buffer.pb(b[ini]);
					ini++;
				}
				aux.pb(buffer);
			}
		}

		if(aux.size()==0){
			cout << "YES" << endl;
			continue;
		}
		if(aux.size()>1){
			cout << "NO" << endl;
			continue;
		}

		flag=true;
		for(auto x : aux[0]){
			if(x!=aux[0][0]){
				flag=false;
			}
		}

		cout << (flag ? "YES" : "NO") << endl;

	}

}
