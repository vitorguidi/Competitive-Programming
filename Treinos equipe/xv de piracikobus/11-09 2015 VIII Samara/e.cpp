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

typedef tuple<double,int,int,int,int> state;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int ans[100100];

int main(){

	fastio;
	
	vi v;
	int n,k; 
	cin>>n>>k; 

	set<state> fila;

	frr(i,k)
		fila.insert( make_tuple(0.0,i,0,0,0) );

	int x;

	frr(i,n){
		
		int x;
		cin >> x;
		
		state aux = *(fila.begin());
		fila.erase(fila.begin());
		
		get<4>(aux)++;	//+size
		get<2>(aux)=get<3>(aux);	//troca
		get<3>(aux)=x;


		int cost = get<2>(aux)+get<3>(aux);
		cost *= get<4>(aux);
		
		get<0>(aux) = (double)cost;
		get<0>(aux) /= 2.0;

		if(get<4>(aux)==1)
			get<0>(aux)=(double)get<3>(aux);

		fila.insert(aux);

		ans[i]=get<1>(aux);


	}

	frr(i,n)
		cout << ans[i] << " ";
	gnl;


}
