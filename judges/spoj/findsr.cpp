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
int phi[100100];
int len;

void pre(){

	phi[0]=phi[1]=0;

	for(int i=2;i<=len;i++){

		phi[i]=phi[i-1];

		while(phi[i]>0 && s[phi[i]]!=s[i-1])
			phi[i]=phi[phi[i]];

		if(s[phi[i]]==s[i-1])
			phi[i]++;
	}

}

void solve(){

	if(s=="*")	return;

	len=s.size();
	pre();

	int amt = len-phi[len];

	cout << (len%amt==0 ? len/amt : 1) << endl;


}

int main(){

	fastio;

	while(getline(cin,s))
		solve();

}