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

int v[550];

int main(){
    
	fastio;

	int n; cin >> n;

	int sum = 0;

	frr(i,n){
		cin >> v[i];
		sum+=v[i];
	}

	vii grandes,pequenos;

	frr(i,n){
		if(v[i]==1)	pequenos.pb({v[i],i});
		else		grandes.pb({v[i],i});
	}

	sort(all(grandes));

	if(sum<2*n-2){
		cout << "NO" << endl;
		return 0;
	}

	vii edges;

	for(int i=0;i+1<grandes.size();i++){
		grandes[i].fst--;
		grandes[i+1].fst--;
		edges.pb({grandes[i].snd,grandes[i+1].snd});
	}


	int diameter = grandes.size()-1;

	if(pequenos.size()){
		
		edges.pb( {pequenos[pequenos.size()-1].snd,grandes[0].snd} );
		grandes[0].fst--;

		if(!grandes[0].fst){
			reverse(all(grandes));
			grandes.pop_back();
			reverse(all(grandes));
		}

		pequenos.pop_back();
		diameter++;

	}


	if(pequenos.size()){

		edges.pb({pequenos[pequenos.size()-1].snd,grandes[grandes.size()-1].snd});
		grandes[grandes.size()-1].fst--;
		
		if(!grandes[grandes.size()-1].fst)	grandes.pop_back();
		
		pequenos.pop_back();
		diameter++;

	}

	int ini=grandes.size()-1;

	while(ini>=0 && pequenos.size()){

		edges.pb( {pequenos[pequenos.size()-1].snd,grandes[ini].snd} );
		grandes[ini].fst--;
		pequenos.pop_back();

		if(!grandes[ini].fst){
			grandes.pop_back();
			ini--;
		}



	}

	cout << "YES" << " " <<  diameter << endl;
	cout << edges.size() << endl;

	for(auto x : edges)
		cout << x.fst << " " << x.snd << endl;
	
}

