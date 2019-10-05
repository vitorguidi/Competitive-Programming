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
 
map<char,ll> val;
int grid[1010][1010];
ll dist[1010][1010];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
	int k,n,m;

bool valid(int i, int j){
	return i>=0 && i<n && j>=0 && j<m;
}

void dijkstra(int x, int y){

	memset(dist,-1,sizeof dist);

	dist[x][y]=0;

	set<pair<ll,pll>> q;
	q.insert(make_pair(0,mp(x,y)));

	while(!q.empty()){
		
		pair<ll,pll> u = *(q.begin());
		q.erase(q.begin());

		pll from = u.snd;
		ll distf = u.fst;

		fr(i,4){

			int new_x = from.fst+dx[i];
			int new_y = from.snd+dy[i];
			
			if(!valid(new_x,new_y))
				continue;
			
			if(dist[new_x][new_y]==-1){
				dist[new_x][new_y] = dist[from.fst][from.snd] + grid[new_x][new_y];
				q.insert( make_pair( dist[new_x][new_y], mp(new_x,new_y)) );
			}
		}

	}

}

void go(){

	val.clear();

	val['E']=0;

	cin >> k >> m >> n;

	ms(grid,0);

	fr(i,k){
		char id;
		ll cost;
		cin >> id >> cost;
		val[id]=cost;
	}

	string s;
	getline(cin,s);

	int x,y;

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid[i][j] = val[s[j]];
			if(s[j]=='E'){
				x=i;
				y=j;
			}
		}
	}

	dijkstra(x,y);

	ll ans = 1e18;

	fr(i,n){
		fr(j,m){
			if(i==0 || i==n-1 || j==0 || j==m-1)
				ans=min(ans,dist[i][j]);
		}
	}

	cout << ans << endl;

}

int main(){

	fastio;
 
	int t; cin >> t;
	while(t--)
		go();	
 
}