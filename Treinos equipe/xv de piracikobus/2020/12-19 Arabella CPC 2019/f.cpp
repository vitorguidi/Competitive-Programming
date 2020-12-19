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

const int INF = 0x3f3f3f3f;

int n,p;
vector<int> durations;
vector<int> removals;
int memo[1010][1010];

int positions[1010][1010];  //positions[i][j] => na rodada i, a posicao j contem alguma cadeira
map<int,int> revposition[1010]; //revposition[i][j] => na rodada i, a cadeira j esta em alguma posicao

void generatepositions() {


	unordered_set<int> removed;

	for(int i=0;i<n;i++) {

		int pos = 0;

		for(int j=0;j<n;j++) {
			if(removed.find(j) != removed.end())	
				revposition[i][j] = -1;
			else{
				positions[i][pos] = j;
				revposition[i][j] = pos++;
			}
		}
		for(int j=pos;j<n;j++)	positions[i][j]=-1;

		removed.insert(removals[i]);

	}

}

int dp(int song, int pos) {

	if(song==n)	return 1;

	int &pdm = memo[song][pos];
	if(pdm!=-1)	return pdm;

	pdm = 0;

	int sz = n - song;

	int new_pos_ccw = (pos - (durations[song]%sz) + sz)%sz;
	int new_pos_cw = (pos + durations[song]+ sz)%sz;

	if( positions[song][new_pos_ccw] != removals[song] ) {
		if(revposition[song][removals[song]] < new_pos_ccw)	
			pdm |= dp(song+1,new_pos_ccw-1);
		else	
			pdm |= dp(song+1,new_pos_ccw);
	}

	if( positions[song][new_pos_cw] != removals[song] ) {
		if(revposition[song][removals[song]] < new_pos_cw)	
			pdm |= dp(song+1,new_pos_cw-1);
		else
			pdm |= dp(song+1,new_pos_cw);
	}

	return pdm;

}

int main(){

	fastio;

	cin >> n >> p;

	fr(i,n-1) {
		int x; cin >> x;
		durations.push_back(x);
	}

	fr(i,n-1) {
		int x; cin >> x;
		removals.push_back(x-1);
	}

	generatepositions();


	ms(memo,-1);

	cout << (dp(0,p-1)== 1 ? "Yes" : "No") << endl; 

	return 0;

}
