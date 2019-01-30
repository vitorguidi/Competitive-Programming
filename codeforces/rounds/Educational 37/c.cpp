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

	vi v;
	vector<vi> seq;

	fr(i,n){
		int x; cin >> x;
		v.pb(x);
	}

	string s; cin >> s;

	vi aux;

	int ini=0;
	aux.pb(v[0]);

	for(int i=1;i<n;i++){
		if(s[i-1]=='0'){
			seq.pb(aux);
			aux.clear();
			aux.pb(v[i]);
		}
		else
			aux.pb(v[i]);
	}

	seq.pb(aux);

	fr(i,seq.size()){
		sort(all(seq[i]));
	// 	cout << "grupo " << i << endl;
	// 	for(auto x : seq[i])
	// 		cout << x << " ";
	// 	gnl;
	}

	vi final;

	for(auto x : seq)
		for(auto y : x)
			final.pb(y);


	bool flag=true;
	fr(i,n-1)
		if(final[i]>final[i+1])
			flag=false;

	if(flag)
		puts("YES");
	else
		puts("NO");


}

