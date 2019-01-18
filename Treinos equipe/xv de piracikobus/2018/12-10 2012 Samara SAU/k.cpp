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
	stack<char> p;
	string s;
	getline(cin,s);

	fr(i,s.size()){
		if(p.empty()){
			p.push(s[i]);
			continue;
		}
		if(s[i] == '(')
			p.push(s[i]);
		if(s[i] == ')'){
			if (p.top() == '(')
				p.pop();
			else
				p.push(')');
		}
	}
	int ct =0;
	bool ok =true;

	while(!p.empty()){
		char a = p.top();
		p.pop();
		if(a == ')') ok = false;
		else ct++;
	}

	if(!ok){
		cout <<"IMPOSSIBLE"<<endl;
		return (0);
	}

	cout << s;
	fr(i,ct) cout <<")";
	gnl;
	

}
