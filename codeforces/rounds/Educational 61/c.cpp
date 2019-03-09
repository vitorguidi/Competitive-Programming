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

int v[5050];
int somando[5050];
int acum1[5050];
int acum2[5050];

bool inter(pii a, pii b){

	return (a.fst<=b.fst && b.fst<=a.snd) || (a.fst<=b.snd && b.snd<=a.snd);

}

int main(){
    
	fastio;

	int n,q;
	cin >> n >> q;

	vector<pii> caras;

	frr(i,q){
		int l,r;
		cin >> l >> r;
		somando[l]++;
		somando[r+1]--;
		caras.pb({l,r});
	}

	int cnt = 0;

	frr(i,n){
		cnt+=somando[i];
		v[i]+=cnt;
		if(v[i]==1)	acum1[i]++;
		if(v[i]==2)	acum2[i]++;
		acum2[i]+=acum2[i-1];
		acum1[i]+=acum1[i-1];
	}

	int best = 0;

	int tot =0;

	frr(i,n)
		if(v[i])
			tot++;

	fr(i,q){
		fr(j,q){

			if(i==j)	continue;

			pii primeiro = caras[i];
			pii segundo = caras[j];
			if(primeiro.fst>segundo.fst)	swap(primeiro,segundo);

			int lost = 0;

			lost+=acum1[primeiro.snd]-acum1[primeiro.fst-1];
			lost+=acum1[segundo.snd]-acum1[segundo.fst-1];

			if(inter(primeiro,segundo)){
				pii terceiro = {max(primeiro.fst,segundo.fst),min(primeiro.snd,segundo.snd)};
				lost+=acum2[terceiro.snd]-acum2[terceiro.fst-1];
			}
	
			best=max(best,tot-lost);

			// if(n-lost>best){
			// 	best=n-lost;
			// 	dbg(i);
			// 	dbg(j);
			// 	gnl;
			// }

		}


	}

	cout << best << endl;

}