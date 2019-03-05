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

string prettify(string s){

	stack<char> q;

	fr(i,s.size()){

		if(q.empty())
			q.push(s[i]);

		else if( q.top()=='(' && s[i]==')' )
			q.pop();
		
		else
			q.push(s[i]);

	}

	string ans;

	while(!q.empty()){
		ans.pb(q.top());
		q.pop();
	}

	reverse(all(ans));

	return ans;



}

pii numberfy(string x){

	int l = 0;
	int r = 0;

	for(auto v : x){
		if(v=='(')	l++;
		else		r++;
	}

	return {l,r};

}

int main(){
    
	fastio;

	map<string,ll> oc;
	map<pii,ll> freq;

	int n; cin >> n;

	fr(i,n){

		string x; cin >> x;
		string lol = prettify(x);

		pii val = numberfy(lol);

		if(val.fst!=0 && val.snd!=0)	continue;
		// if(oc[x])	continue;
		// oc[x]++;
		freq[numberfy(lol)]++;
	
	}

	ll ans = 0;

	for(auto x : freq){
		
		pii lol = x.fst;
		pii comp = {lol.snd,lol.fst};

		while(freq[lol]>0 && freq[comp]>0){
			
			if(lol==comp && freq[comp]<2)	break;
			ans++;
			freq[lol]--;
			freq[comp]--;
		}
		
	}


	cout << ans << endl;

}