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
const double pi = 3.141592653589793238462643383279502884L;

struct are{
	int x,y;
};

int n,d,k;
int deg[400400];
vector<are> ans;

int main(){

	cin >> n >> d >> k;

	if(d>=n){
		  cout << "NO" << endl;
		  return 0;
	}

	frr(i,d){			//constroi o diametro da arvore

		are aux;
		aux.x=i;
		aux.y=i+1;
		ans.pb(aux);

		deg[i]++;
		deg[i+1]++;
		if(deg[i]>k || deg[i+1]>k){
			cout << "NO" << endl;
			return 0;
		}	
	}

	set<pii> free;
	
	for(int i=2;i<=d;i++){				//coloca so os vertices indexados de 2 a d (o 1 e o d+1 estourariam o diametro maximo)
		pii aux = mp( max(i-1,d+1-i),i );
		free.insert(aux);
	}
    
	for(int i=d+2;i<=n;i++){

		while(!free.empty() && deg[free.begin()->snd]==k)
			free.erase(free.begin());

		if(free.empty() || free.begin()->first==d){
			cout << "NO" << endl;
			return 0;
		}

		deg[i]++;
		deg[free.begin()->snd]++;

		are aux;
		aux.x=free.begin()->snd;
		aux.y=i;
		ans.pb(aux);

		free.insert( mp( free.begin()->fst+1, i ) );
		
	}

	if(ans.size()>=n){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	fr(i,ans.size())
		cout << ans[i].x << " " << ans[i].y << endl;


}

