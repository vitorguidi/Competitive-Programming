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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[1010];
int d[1010];
int vis[1010];

int dfs(int v){

	vis[v]=1;

	int ans = 0;
	
	for(auto x : nodes[v]){

		if(!vis[x])
			ans=max(ans,dfs(x));
		else
			ans=max(ans,d[x]);
	}

	return d[v]=1+ans;

}

int main(){

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin,s);

    int len = s.size();

    fr(i,len){
    	char letra = s[i];
    	for(int j=i+1;j<len;j++){
    		if(letra=='1' && s[j]=='3')
    			continue;
    		nodes[i].pb(j);
    	}
    }

 	fr(i,len)
 		dfs(i);

    int ans = 0;
    fr(i,len)	
    	ans=max(ans,d[i]);

    cout << len - ans << endl;

}