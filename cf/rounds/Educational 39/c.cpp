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

int v[100100];
int n;

int main(){
    
	fastio;

	string s; getline(cin,s);
	int n = s.size();

	if(n<26){
		cout << -1 << endl;
		return 0;
	}

	int ini=0;
	int cur=0;

	for(int i=0;i<n;i++){
		if(cur==26)	break;
		if(s[i]-'a'<=cur){
			s[i]=cur+'a';
			cur++;
		}
	}

	cout << (cur==26 ? s : "-1") << endl; 


}

