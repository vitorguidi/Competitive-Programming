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

int t;
ll n, m;

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%lld%lld", &n, &m);
		m--;
	
		ll l = 0, r = 1000000005;
		pair<ll,ll> ans;
		while(l <= r){
			ll mid = (l+r)/2LL;
			ll pos = (mid*(mid+1))/2LL;

			if(m >= pos and m <= pos+mid){
				ans.fi = mid;
				ans.se = m-pos;
				break;
			}
			else if(pos < m){
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}

		printf("Case %d: %lld %lld\n", caso, ans.fi, ans.se);
	}

	return 0;
}
close