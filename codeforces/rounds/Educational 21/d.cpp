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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

map<ll,ll> freq;
ll acum[200200];
ll v[200200];

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n){
		cin >> v[i];
		acum[i]=v[i]+acum[i-1];
	}

	for(int i=1;i<=n-1;i++){			//checa se ja existe algum prefixo igual a outro sufixo
		if(acum[i]==acum[n]-acum[i]){	//defino por prefixo tudo acumulado ate o i
			cout << "YES" << endl;		//defino como sufixo tudo acumulado do i+1 ate o n
			return 0;
		}
	}

	freq[v[1]]++;

	for(int i=2;i<=n;i++){			//tenta pegar alguem do prefixo e jogar no sufixo

		freq[v[i]]++;
		
		ll pos = acum[n]-acum[i];
		ll pre = acum[i];
		ll dif = pre-pos;
		
		if(dif%2ll)	continue;
	
		else if(freq[dif/2ll]){
			cout << "YES" << endl;
			return 0;
		}

	}

	freq.clear();

	freq[v[n]]++;

	for(int i=n-1;i>=1;i--){		//tenta pegar alguem do sufixo e jogar no prefixo

		freq[v[i]]++;
		
		ll pos = acum[n]-acum[i-1];
		ll pre = acum[i-1];
		ll dif = pos-pre;;
		
		if(dif%2ll)	continue;
		
		else if (freq[dif/2ll]){
			cout << "YES" << endl;
			return 0;
		}

	}

	cout << "NO" << endl;

}

