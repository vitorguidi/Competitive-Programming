#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define dbg(x) cout << #x << " = " << x << endl
#define se second
#define fst first
#define snd second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"

const int N = 50;
int t, n, m;
char s[10005];
vector<int> adj[N];
bool vis[N];
char v1[N][2], v2[N][2];
int dp[1000000][20];

void init(){
	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
	memset(vis, 0, sizeof vis);
	memset(dp, -1, sizeof dp);
}

bool solve(int mask, int u){
	vis[u] = 1;

	if(dp[mask][u] != -1){
		return dp[mask][u];
	}

	mask |= (1 << u);

	// cout << "to em " << u << endl;

	bool atinge = 0;
	for(int v : adj[u]){
		if(!vis[v]){
			atinge = 1;
		}
	}

	if(atinge == 0){
		return 1;
	}

	bool other = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			other &= solve(mask, v);
		}
	}

	// bool other = 0;
	// for(int v : adj[u]){
	// 	if(!vis[v]){
	// 		other |= solve(mask, v);
	// 	}
	// }

	mask -= (1 << u);
	vis[u] = 0;
	return dp[mask][u] = !other;
}

int main(void){
	// fastcin;
	// cin >> t;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();

		// cin >> n;
		// cin.get();
		scanf("%d", &n);
		gets(s);

		// vector<pair<char,char> > v1, v2;
		for(int i = 0; i < n; i++){
			// getline(cin, s);
			gets(s);
			// printf("%s\n", s);
			// v1.pb(mp(s[0], s[int(s.size())-1]));
			v1[i][0] = s[0];
			int len = strlen(s);
			v1[i][1] = s[len-1];
		}

		// cin >> m;
		// cin.get();
		scanf("%d", &m);
		gets(s);

		for(int i = 0; i < m; i++){
			// getline(cin, s);
			// v2.pb(mp(s[0], s[int(s.size())-1]));
			// getline(cin, s);
			gets(s);
			// printf("%s\n", s);
			// v1.pb(mp(s[0], s[int(s.size())-1]));
			v2[i][0] = s[0];
			int len = strlen(s);
			v2[i][1] = s[len-1];
		}
	

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(v1[i][1] == v2[j][0]){
					adj[i].pb(n+j);
				}
			}
		}

		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(v2[j][1] == v1[i][0]){
					adj[n+j].pb(i);
				}
			}
		}

		bool ok = 0;
		for(int i = 0; i < n; i++){
			memset(dp, -1, sizeof dp);
			memset(vis, 0, sizeof vis);
			
			int x = solve(0, i);
			// cout << x << endl;
			// cout << endl;
			ok |= x;
		}

		if(ok){
			// cout << "Game " << caso << ": player1" << endl;
			printf("Game %d: player1\n", caso);
		}
		else{
			// cout << "Game " << caso << ": player2" << endl;			
			printf("Game %d: player2\n", caso);
		}
	}

	return 0;
}
close