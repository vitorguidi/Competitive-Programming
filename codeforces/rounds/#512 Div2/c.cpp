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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;
int v[110];

bool check(int x){

	int val = v[x];
	
	int ini = x+1;
	int end = x+1;

	while(ini<=n && end<=n){
		
		while( v[end+1]-v[ini-1]<=val && end+1<=n)
			end++;


		if(v[end]-v[ini-1]!=val)
			return false;

		end++;
		ini=end;

	}

	return true;

}

int main(){
    
	fastio;

	cin >> n;

	string s; getline(cin,s);getline(cin,s);

	frr(i,n)
		v[i]=s[i-1]-'0';

	frr(i,n)
		v[i]+=v[i-1];
		
	bool flag = false;

	for(int i=1;i<=n-1;i++)
		if(check(i))
			flag=true;

	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

