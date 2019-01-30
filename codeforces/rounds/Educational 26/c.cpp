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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,a,b;
int x[110],y[110];

int solve(int l1, int l2, int l3, int l4, int l5, int l6){

	int empilhado = 0;

	if(l1>=l3+l5 && l2>=max(l4,l6))
		empilhado=l3*l4+l5*l6;

	int lado = 0;

	if(l1>=max(l3,l5) && l2>=l4+l6)
		lado=l3*l4+l5*l6;

	return max(lado,empilhado);

}

int main(){
    
	fastio;

	cin >> n >> a >> b;
	fr(i,n)
		cin >> x[i] >> y[i];

	int ans = 0;

	fr(i,n){
		fr(j,n){
			if(i==j)	continue;
			
			vi aux;

			int caso1 = solve(a,b,x[i],y[i],x[j],y[j]);
			aux.pb(caso1);

			int caso2 = solve(a,b,x[i],y[i],y[j],x[j]);
			aux.pb(caso2);

			int caso3 = solve(a,b,y[i],x[i],x[j],y[j]);
			aux.pb(caso3);

			int caso4 = solve(a,b,y[i],x[i],y[j],x[j]);
			aux.pb(caso4);

			int caso5 = solve(b,a,x[i],y[i],x[j],y[j]);
			aux.pb(caso5);

			int caso6 = solve(b,a,x[i],y[i],y[j],x[j]);
			aux.pb(caso6);

			int caso7 = solve(b,a,y[i],x[i],x[j],y[j]);
			aux.pb(caso7);

			int caso8 = solve(b,a,y[i],x[i],y[j],x[j]);
			aux.pb(caso8);

			for(auto x : aux)
				ans=max(ans,x);

		}
	}

	cout << ans << endl;

}

