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
 
int memo[100100][2];
string s;
int n;
 
int dp(int ind, int state) {
	if(ind==s.size())	return (state==0 ? 0 : 1e9);
 
	int &pdm = memo[ind][state];
	if(pdm!=-1)	return pdm;
 
	pdm=1e9;
 
	if(state==0) {	//soma de 0
		int ans = min( (s[ind]-'0') + dp(ind+1,0), (s[ind]-'0') + 1 + dp(ind+1,1));	//min entre construir de 0, ou ir acima e sub depois
		pdm = min(pdm,ans);
	} else {
		int ans  = min(10-(s[ind]-'0') -1 + dp(ind+1,1), 10-(s[ind]-'0') +dp(ind+1,0) );
		pdm = min(pdm,ans);
	}
	return pdm;
 
}
 
int main(){
 
	fastio;
 
	cin >> s;
 
	memset(memo,-1,sizeof(memo));
 
	cout << min(1+dp(0,1),dp(0,0)) << endl;
 
	return 0;
 
}
