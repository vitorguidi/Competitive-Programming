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

int v[100100];
int tag[100100];
vi caras[100100];

int main(){
    
	fastio;

	int n; cin >> n;

	ms(v,-1);

	frr(i,n){
		int x; cin >> x;
		x=n-x;
		v[i]=x;
	}

	frr(i,n)	caras[v[i]].pb(i);

	int clk=0;

	fr(i,100100){
		
		int len = caras[i].size();
		if(!len)	continue;

		if(len%i){
			cout << "Impossible" << endl;
			return 0;
  		}

  		while(len){

  			clk++;

  			fr(j,i){
  				tag[caras[i][--len]]=clk;
  				caras[i].pop_back();
  			}

  		}

	}

	if(clk>n){cout << "Impossible" << endl;return 0;}
	cout << "Possible" << endl;

	frr(i,n)	cout << tag[i] << " ";
	gnl;

}