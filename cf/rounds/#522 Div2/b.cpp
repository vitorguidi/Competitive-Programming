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

int main(){
    
	fastio;

	string s; cin >> s;

	int len = s.size();
	
	int best_row=INF;
	int best_col=INF;
	
	for(int i=1;i<=5;i++){
		for(int j=1;j<=20;j++){

			if(i*j<len)	continue;

			best_row=min(best_row,i);
			if(i==best_row)	best_col=min(best_col,j);
		}
	}

	cout << best_row << " " << best_col << endl;

	vector<string> x;
	x.resize(best_row);

	int ast = best_row*best_col-len;

	int toper=ast/best_row;
	int ini=0;

	fr(i,best_row){

		ast-=toper;
		fr(j,toper)
			x[i].pb('*');
		if(ast%best_row){
			x[i].pb('*');
			ast--;
		}
		
		int sobra = best_col-x[i].size();
		
		fr(j,sobra)
			x[i].pb(s[ini++]);

	}

	for(auto y : x)
		cout << y << endl;

}

