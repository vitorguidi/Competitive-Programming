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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string t;
int n,k;

bool check(string x){

	int ans = 0;

	int szx=x.size();
	int szt=t.size();

	fr(i,szx-szt+1){

		string aux;
		
		fr(j,szt)
			aux.pb(x[j+i]);

		if(aux==t)
			ans++;
	
	}

	return (ans==k);

}

int main(){
    

	cin >> n >> k;

	getline(cin,t);
	getline(cin,t);

	string s = t;

	int len = t.size();

	vector<string> brute;

	fr(i,len){

		string aux;

		for(int j=i;j<len;j++)
			aux.pb(t[j]);
		
		brute.pb(aux);
	
	}

	int sz=len;
	string ans = t;

	for(auto x : brute){

		string aux = t;

		fr(i,k-1)
			aux+=x;

		if( check(aux) ){
			ans = aux;
			sz=x.size();
		}

	}

	cout << ans << endl;

}

