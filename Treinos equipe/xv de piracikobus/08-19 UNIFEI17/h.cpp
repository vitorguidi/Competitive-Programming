#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define fr(i,n) for(int i =0; i<n;i++)
#define pq priority_queue
#define grtp greater< pair<int,int> >
#define gnl cout << endl
#define olar cout << "olar" << endl

typedef long long int ll;

const int INF = 0x3f3f3f3f;

ll n,m;
ll v[1010][1010];

int main(){
	
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

	
	ll n,m; 

	cin >> n >> m;

	int mn = INF;

	fr(i,n){

		fr(j,m){

			int aux; cin >> aux;

			if(aux==0)
				continue;
		
			mn = min(aux,mn);
			v[i][j]= aux;

		}

	}

	ll ans = 0;

	fr(i,n){

		fr(j,m){
		
			int aux = v[i][j];
			if(aux==0)
				continue;
			if(aux>mn)
				ans+=aux-mn;
		
		}
	}

	cout << ans << endl;

}