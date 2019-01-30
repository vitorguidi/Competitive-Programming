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
#define fastcin ios_base::sync_with_stdio(false)
#define ll long long
#define endl "\n"

const int N = 100005;
ll n, d, c;
int v[N];
int t;

int main(){	
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%lld%lld%lld", &n, &d, &c);
	
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
		}

		sort(v+1, v+n+1);

		ll ans = ((ll)n)*d;
		for(int i = 1; i <= n; i++){
			ans = min(ans, ((ll)i)*c*((ll)v[i]) + ((ll)(n-i))*d);
		}

		printf("Case %d: %lld\n", caso, ans);
	}

	return 0;
}