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

int n;
string s;

string solve(int ind){

	string aux;
	for(int i=0;i<ind;i++)
		aux.pb(s[i]);
	for(int i=ind+1;i<n;i++)
		aux.pb(s[i]);

	return aux;
}

int main(){
    
	fastio;

	cin >> n;
	cin >> s;

	int ind=-1;

	fr(i,n-1)
		if(s[i]>s[i+1]){
			ind=i;
			break;
		}

	if(ind==-1){
		fr(i,n-1)
			cout << s[i];
		gnl;
		return 0;
	}

	for(int i=0;i<n;i++)
		if(i!=ind)
			cout << s[i];

	gnl;

}

