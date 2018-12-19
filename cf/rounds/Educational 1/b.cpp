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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string s;
string aux;


void shift(int l, int r,int k){

	int len = r-l+1;

	for(int i=l;i<=r;i++){
		int delta = (i-l+k)%len;
		aux[l+delta]=s[i];
	}

	for(int i=l;i<=r;i++)
		s[i]=aux[i];


}

int main(){

	fastio;

	cin >> s;

	int len = s.size();

	aux.resize(len);
	fr(i,len)
		aux[i]=s[i];

	int q; cin >> q;

	fr(i,q){
		int l,r,k;
		cin >> l >> r >> k;
		l--;
		r--;
		int len = r-l+1;
		k = k%len;
		shift(l,r,k);
	}

	cout << s << endl;

	
	
}