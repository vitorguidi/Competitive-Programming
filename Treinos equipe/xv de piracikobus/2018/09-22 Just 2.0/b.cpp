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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 1000000007;

ll v[11234];
ll n;
ll memo[10100][1100];

ll pd(ll ind,ll mask){
	if(ind==n-1)	return 1;

	ll &pdm=memo[ind][mask];
	if (pdm != -1) return pdm;

	pdm=pd(ind+1,0);
	pdm%=mod;

	int new_mask= mask|(1<<v[ind]);

	//dbg(new_mask);
	//int x = new_mask&(1<<v[ind+1]);
	//dbg(x);

	if((new_mask&(1<<v[ind+1]))==0){
		//olar;
		pdm+=pd(ind+1,new_mask);
	}

	return pdm%mod;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	string s;
	getline(cin,s);
	getline(cin,s);
	fr(i,s.size())
		v[i] = s[i] - '0';
	
	ms(memo,-1);
	cout << pd(0,0) << endl;
    

}