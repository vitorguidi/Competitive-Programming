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
#define vll vector<long long int>
#define pii pair<int,int>
#define pll pair<long long int, long long int>

void go(){

	int n,k;
	cin >> n >> k;

	string s; cin >> s;

	int ini=0;
	int best = 0;

	while(ini<s.size()){
		int cnt = 0;
		if(s[ini]=='1'){
			ini++;
			continue;
		}
		while(ini<s.size() && s[ini]=='0'){
			cnt++;
			ini++;
		}
		best=max(best,cnt);
	}

	cout << (best >= k+1 ? "yes" : "no") << endl;



}

int main()
{	
	fastcin;
	int t; cin >> t;
	while(t--)	go();

}