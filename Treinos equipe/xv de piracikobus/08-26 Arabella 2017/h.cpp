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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string aux = "AHIMOTUVWXY";

bool check(char s){
	
	fr(i,11){
		if(s==aux[i])
			return true;
	}

	return false;

}

int main(){

	int t; cin >> t;
	string x;
	getline(cin,x);

	while(t--){

		getline(cin,x);

		string aux2 = x;
		reverse(all(x));
		
		bool lol = true;
		
		if(aux2!=x)
			lol=false;
		
		fr(i,x.size())
			lol = lol && check(x[i]);

		if(lol)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

}