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

int main(){
    
	fastio;

	int n; cin >> n;
	
	string s;

	vector<string> aux;

	getline(cin,s);
	getline(cin,s);

	int ini=0;

	while(ini<n){
		string temp;
		while(s[ini]!=' ' && ini<n)
			temp.pb(s[ini++]);
		if(ini<n)
			ini++;
		aux.pb(temp);
	}

	int mx=0;

	for(auto x : aux){
		int cnt = 0;
		for(auto y : x)
			cnt+=(y>='A' && y<='Z');
		mx=max(mx,cnt);
	}

	cout << mx << endl;

}

