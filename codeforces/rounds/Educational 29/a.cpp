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

string to_str(int x){
	string aux;
	do{
		aux.pb(x%10 + '0');
		x/=10;
	}while(x);
	return aux;
}

bool is_pal(string x){
	int len = x.size();
	fr(i,len/2)
		if(x[i]!=x[len-1-i])
			return false;
	return true;
}

int main(){
    
	fastio;

	int x; cin >> x;

	string s = to_str(x);

	fr(i,20){
		if(is_pal(s)){
			cout << "YES" << endl;
			return 0;
		}
		s.pb('0');
	}

	cout  << "NO" << endl;

}

