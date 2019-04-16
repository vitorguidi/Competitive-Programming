#include <bits/stdc++.h>
using namespace std;

#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ms(x,val) memset(x,val,sizeof x)
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX
#define gnl cout << endl
#define dbg(x) cout << #x << " = " << x << endl
#define vll vector<long long int>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long int, long long int>
#define olar cout << "olar" << endl;

int pts[100005];

void go(){

	int n,q;
	cin >> n >> q;

	int last=0;
	
	set<pii> s;
	ms(pts,0);

	for(int i=1;i<=n;i++)
		s.insert({0,-i});

	for(int i=1;i<=q;i++){

		int t,p;
		cin >> t >> p;

		pii cur = *s.rbegin();
		
		s.erase({pts[t],-t});

		pts[t]+=p;
		s.insert({pts[t],-t});

		pii now = *s.rbegin();

		if(now.se!=cur.se)	last=i;

	}

	if(n==1){
		cout << 0 << endl;
		return;
	}

	cout << last << endl;

}

int main(){

	fastcin;

	int t; cin >> t;
	while(t--)
		go();
	
}