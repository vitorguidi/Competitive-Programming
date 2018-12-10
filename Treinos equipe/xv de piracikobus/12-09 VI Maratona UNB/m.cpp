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

	ll l; cin >> l;
	string s;	cin >> s;

	if(s=="circulo"){
		ll r; cin >> r;
		if(l>=2ll*r)	puts("Sim");
		else			puts("Nao");
	}

	if(s=="retangulo"){
		ll a,b; cin >> a >> b;
		if(a<b)	swap(a,b);
		if(l>=a || l*sqrt(2)>=a+b)	puts("Sim");
		else						puts("Nao");
	}

	if(s=="triangulo"){
		ll r; cin >> r;
		if(l>=r || l>=r*cos(acos(-1)/12.0))	puts("Sim");
		else		puts("Nao");
	}


}
