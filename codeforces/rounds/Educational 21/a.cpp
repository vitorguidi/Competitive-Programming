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

string converte(ll x){
	string aux;
	do{
		aux.pb(x%10+'0');
		x/=10;
	}while(x);
	reverse(all(aux));
	return aux;
}

ll to_num(string x){

	ll base = 1;
	int len = x.size()-1;

	ll ans = 0;

	for(int i=len;i>=0;i--){
		ans+=base*(x[i]-'0');
		base*=10ll;
	}

	return ans;

}

int main(){
    
	fastio;

	ll x; cin >> x;
	string aux = converte(x);
	
	char dig = aux[0];
	int len = aux.size();
	
	if(dig=='9'){
		string ans = "1";
		fr(i,len)
			ans+='0';
		aux=ans;
	}
	else{
		aux[0]++;
		for(int i=1;i<aux.size();i++)	aux[i]='0';
	}

	cout << to_num(aux)-x << endl;


}

