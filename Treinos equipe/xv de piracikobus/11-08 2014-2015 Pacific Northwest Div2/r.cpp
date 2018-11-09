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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll memo[81][11][2];
string s;

ll pd(int id, int last,int estouro){
	if(id == s.size())
		return 1; 

	ll &pdm=memo[id][last][estouro];
	if(pdm!=-1)	return pdm;
	
	ll ans=0;
	for(int i=last;i<=9;i++){
		if(estouro){
			if(i<=(s[id]-'0'))
				ans+=pd(id+1,i, (i==(s[id]-'0')? 1:0 ) );
		}
		else
			ans+= pd(id+1,i, 0 ) ;
	}
	pdm=ans; 
	return ans;

}

void solve(){
	cin>>s; 
	bool ok=1;
	frr(i,s.size()-1)
		if(s[i]<s[i-1]){
			cout<<-1<<endl; 
			return;
		} 

	ms(memo,-1);		
	ll ans=0; 
	for(int i=0;i <= (s[0]-'0');i++)
		ans += pd(1,i, (i==(s[0]-'0')? 1:0 ) );
	ans--;
	cout<<ans<<endl;

}

int main(){

	fastio;

	int t; cin>>t;
	while(t--)	solve();

}