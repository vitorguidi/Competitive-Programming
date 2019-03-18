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

int main(){
    
	fastio;

	string s,t;
	cin >> s >> t;

	int na=0;
	int nb=0;

	fr(i,s.size()){
		if(s[i]==t[i])	continue;
		na+=s[i]=='4';
		nb+=s[i]=='7';
	}

	int corte = min(na,nb);

	int ans = corte;

	ans+=max(na,nb)-corte;

	cout << ans << endl;

}