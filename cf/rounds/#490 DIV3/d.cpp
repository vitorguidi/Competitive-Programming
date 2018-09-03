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

int main(){
    
  int n,m;
  map<ll,ll> cnt;

  vector<ll> free;
  vector<vi> index;
  vector<ll> v;

  cin >> n >> m;

  index.resize(m);

  fr(i,n){
  
  	ll aux;
  	cin >> aux;

  	v.pb(aux);
  	index[aux%m].pb(i);
  	cnt[aux%m]++;
  
  }


  ll ans=0;

  fr(j,2*m){

  	int i = j%m;
	  	
  	if(cnt[i]>n/m){

  		int last=cnt[i]-1;

  		while(cnt[i]>n/m){
  			free.pb(index[i][last]);
  			last--;
  			cnt[i]--;
  			index[i].pop_back();
  		}

  	}

  	if(cnt[i]<n/m){

  		while(!free.empty() && cnt[i]<n/m){

  			int last = free.size()-1;

  			int pos = free[last];
  			ll num=v[pos];

  			num=num%m;

  			int delta;

  			if(num<i)
  				delta=i-num;
  			else
  				delta=i+m-num;

  			v[pos]+=delta;
  			ans+=delta;

  			free.pop_back();
  			index[i].pb(pos);

  			cnt[i]++;
  			last--;

  		}

  	}

  }


	cout << ans << endl;
	fr(i,n)
		cout << v[i] << " ";
	gnl;


}

