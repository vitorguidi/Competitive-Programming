#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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
const int MAXN = 100100;

int main(){

	int n,k;
	vii seq;

	cin >> n >> k;
	
	fr(i,n){
		int aux; cin >> aux;
		seq.pb(mp(aux,i));
	}

	sort(all(seq));
	reverse(all(seq));

	int ini=0,end=1;

	while(ini<n && end<n){
		if(ini==n)	break;
		while(end<n && seq[ini].fst-seq[end].fst<k)
			end++;
		if(seq[ini].fst-seq[end].fst<k)
			break;
		if(seq[ini].fst-seq[end].fst==k && ini!=end){
			cout << "Sim" << endl;
			cout << seq[ini].snd+1 << " " << seq[end].snd+1 << endl;
			return 0;
		}
		ini++;
	}


	cout << "Nao" << endl;


}