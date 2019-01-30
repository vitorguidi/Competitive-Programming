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

ll str[500500];
ll acuma[500500];
ll acumb[500500];

string s;

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n)	cin >> str[i];

	cin >> s;

	ll best = 0;

	fr(i,n){
		if(s[i]=='A')
			acuma[i+1]+=str[i+1];
		else{
			best+=str[i+1];
			acumb[i+1]+=str[i+1];
		}
	}

	frr(i,n){
		acuma[i]+=acuma[i-1];
		acumb[i]+=acumb[i-1];
	}

	frr(i,n)
		best=max<ll>({best,acuma[i] + acumb[n]-acumb[i],acuma[n]-acuma[i-1]+acumb[i-1]});
	
	cout << best << endl;

}

