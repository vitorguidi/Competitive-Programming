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

int used[200100];

int main(){
    
	fastio;

	stack<pair<char,int>> stk;

	int n,k; cin >> n >> k;

	string s;
	cin >> s;
	
	vii aux;

	fr(i,n){

		if(s[i]=='('){
			stk.push({'(',i});
			continue;
		}

		if(s[i]==')'){
			pair<char,int> cara = stk.top();
			stk.pop();
			aux.pb(mp(cara.snd,i) );
		}

	}

	sort(all(aux));

	string vamodale;

	int last=-1;

	for(auto x : aux){
		if(x.snd<=last)
			continue;
		int amt = x.snd-x.fst+1;
		if(amt<=k){
			k-=amt;
			for(int i=x.fst;i<=x.snd;i++)
				used[i]=1;
			last=x.snd;
		}
	}

	fr(i,n)
		if(used[i])
			cout << s[i];

	gnl;

}

