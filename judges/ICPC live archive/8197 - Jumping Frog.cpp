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

vector<ll> primos;
string s;

void get_prim(ll n){

	primos.clear();
	for(ll i=1;i*i<=n;i++){
		if(n%i == 0) primos.pb(i);
		if( n/i != i) primos.pb(n/i);
	}

}

int main(){
	fastio;
	//dbg(!k);
	while(cin>>s){

		int tudo,nada;
		tudo=0;nada=0;
		fr(i,s.size())
			if(s[i]=='R')
				tudo++;
			else
				nada++;

		if(tudo==s.size() || nada==s.size()){
			if(tudo==s.size())
				cout<<s.size()-1<<endl;
			else
				cout<<0<<endl;
			continue;
		}	

		ll n=s.size();

		get_prim(n);

		set<ll> ans;
		ans.clear();


		fr(i,primos.size()){
			ll primo=primos[i];
			bool primo_valido=0;

			fr(j,primo){
				bool ok=1;

				if(s[j]=='P')
					ok=0;
				
				ll pos=(j+primo)%n;

				while(pos!=j && ok)
					if(s[pos]=='P')
						ok=0;
					else
						pos=(pos+primo)%n;

				if(ok)	
					primo_valido=1;	
			}
			if(primo_valido)
				for(ll d=primo;d<n;d+=primo)
					ans.insert(d);
		}
		cout<<ans.size()<<endl;

	}

}
