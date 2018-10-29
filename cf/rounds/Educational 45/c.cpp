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


string parser(string a){

	stack<char> q;

	for(int i=0;i<a.size();i++){
		char aux = a[i];
		if(q.empty())
			q.push(aux);
		else if(aux==')' && q.top()=='(')
			q.pop();
		else
			q.push(aux);
	}

	string ans;
	stack<char> p;

	while(!q.empty()){
		p.push(q.top());
		q.pop();
	}
	
	while(!p.empty()){
		ans.pb(p.top());
		p.pop();
	}

	return ans;
	
}


int main(){
    
	fastio;
	int n; cin >> n;

	vii v;
	map<int,int> cl;
	map<int,int> cr;


	ll ans = 0;
	ll freak = 0;

	fr(i,n){
		
		string a; cin >> a;
		a=parser(a);

		int l=0,r=0;
		int ini=0;
		int len = a.size();
		
		while(a[ini]==')' && ini<len){
			l++;
			ini++;
		}
		
		while(a[ini]=='(' && ini<len){
			r++;
			ini++;
		}
		
		if(l && r)
			continue;
		if(!l && !r){
			freak++;
			continue;
		}
		
		cl[l]++;
		cr[r]++;
		
		v.pb({l,r});
	
	}

	for(auto x : v){

		if(x.fst)
			ans+=cr[x.fst];
		else
			ans+=cl[x.snd];

	}

	ans/=2;
	ans+=freak*freak;

	cout << ans << endl;


}

