#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fst first
#define snd second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX

ll freq[10100];
int clk=1;

void solve(){

	ll m,n,c; 
	cin >> m >> n >> c;

	for(int i=0;i<10100;i++)	freq[i]=0;

	for(int i=0;i<m;i++){
		int x; cin >> x;
		freq[x]++;
	}

	vector< pair<ll,ll> > choices;

	for(int i=1;i<=n;i++)
		choices.pb(mp(freq[i],i));

	sort(choices.begin(),choices.end());
	reverse(choices.begin(),choices.end());

	ll cost = (choices[0].snd*choices[0].snd)%c;
	ll occur = choices[0].fst;

	ll ans = cost*occur;

	for(int i=1;i<choices.size();i++){
		occur=min<ll>(occur,choices[i].fst);
		cost+=(choices[i].snd*choices[i].snd)%c;
		ans=max<ll>(ans,occur*cost);
	}

	cout << "Case " << clk++ << ": " << ans << endl;

}

int main()
{	
	fastcin;
	int t; cin >> t;
	while(t--)	solve();

}