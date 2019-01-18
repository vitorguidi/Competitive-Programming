#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

bool danger(pii a, pii b){
	if(a.fst==b.fst)	return true;
	if(a.snd==b.snd)	return true;
	b.fst-=a.fst;
	b.snd-=a.snd;
	if(abs(b.snd)!=abs(b.fst))	return false;
	return true;
}

void solve(){
	vii aux;
	fr(i,8){
		string s; cin >> s;
		int x=  s[0]-'A';
		int y= s[1]-'1';
		aux.pb({x,y});
	}
	bool flag = true;
	fr(i,8){
		fr(j,8){
			if(i==j)	continue;
			if(danger(aux[i],aux[j]))	flag=false;
		}
	}
	if(flag)	puts("Valid");
	else		puts("Invalid");

}

int main(){
	fastio;
	int t; cin >> t;
	while(t--)	solve();
}