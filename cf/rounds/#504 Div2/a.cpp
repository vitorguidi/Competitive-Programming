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

	int n,m; cin >> n >> m;
	string s,t; cin >> s >> t;

	bool flag = false;

	for(auto x : s)
		if(x=='*')
			flag=true;

	if(!flag){
		if(s!=t)
			puts("NO");
		else
			puts("YES");
		return 0;
	}

	int inis=n-1;
	int init=m-1;

	while(s[inis]==t[init] && inis>=0 && init>=0 && s[inis]!='*'){
		s.pop_back();
		t.pop_back();
		inis--;
		init--;
	}

	reverse(all(s));
	reverse(all(t));


	while(s[inis]==t[init] && inis>=0 && init>=0 && s[inis]!='*'){
		s.pop_back();
		t.pop_back();
		inis--;
		init--;
	}

	if(inis==0 && s[inis]=='*')
		puts("YES");
	else
		puts("NO");

}

