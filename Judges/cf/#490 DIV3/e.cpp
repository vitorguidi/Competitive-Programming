#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int good[5050],vis[5050];
vi nodes[5050];

int dfs(int v){

  int tam = nodes[v].size();
  vis[v]=1;

  int ans=0;

  fr(i,tam){
    int filho = nodes[v][i];
    if(!vis[filho] && !good[filho])
      ans+=1+dfs(filho);
  }

  return ans;

}

int main(){
    
  int n,m,s;

  cin >> n >> m >> s;

  fr(i,m){
    int x,y;
    cin >> x >> y;
    nodes[x].pb(y);
  }

  dfs(s);

  frr(i,n){
    if(vis[i]){
      good[i]=1;
    }
  }

  vii reach;
  
  frr(i,n){
    if(!good[i]){
      ms(vis,0);
      int aux=dfs(i);
      reach.pb(mp(aux,i));
    }
  } 

  sort(reach.begin(),reach.end());

  int ans=0;

  for(int i=reach.size()-1;i>=0;i--){

    if(good[reach[i].snd])
      continue;

    ms(vis,0);

    dfs(reach[i].snd);
    
    ans++;
    
    frr(i,n){
      if(vis[i] && !good[i]){
        good[i]=1;
      }
    }

  }

  cout << ans << endl;

}

