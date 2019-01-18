
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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

struct prob{
	int id;
	int dt;
	int ac;
	int pro;
};

bool cmp(prob a, prob b){
	return a.dt < b.dt;
}

void solve(){

	int n,m,k; cin >> m >> n>> k;

	vector<prob> mat[50][50];
	vector<prob> p;
	int v[100];
	ms(v,-1);

	string s;


	fr(i,k){

		int x,y,z; cin >> x >> y >> z;
		getline(cin,s);

		int dt =0;
		dt+=s[6]-'0';
		dt+=10*(s[5]-'0');
		dt+=60*(s[3]-'0');
		dt+=60*10*(s[2]-'0');
		dt+=60*100*(s[1]-'0');

		// dbg(s);
		// dbg(dt);
		// gnl;

		prob aux;
		aux.id=y;
		aux.pro=x;
		aux.ac=z;
		aux.dt=dt;

		p.pb(aux);

	}

	sort(all(p),cmp);

	for(auto x : p)
		mat[x.id][x.pro].pb(x);

	for(auto x : p){
		if(v[x.pro]==-1 && x.ac==1)
			v[x.pro]=x.id;
	}

	frr(i,m)
		cout << v[i] << " ";		//primero a resolver
	gnl;

	for(auto x : p){				//primeira correta
		if(x.ac==1){
			cout << x.id << " ";
			break;
		}
	}

	for(int i = p.size()-1;i>=0;i--){	//ultima correta
		if(p[i].ac==1){
			cout << p[i].id << " ";
			break;
		}
	}


	int best = -1;					//mais corretos de prima		
	int pessoa = -1;
	frr(i,n){
		int amt=0;
		frr(j,m){
			if(mat[i][j].size()>0 && mat[i][j][0].ac==1)
				amt++;
		}
		if(amt>best){
			pessoa=i;
			best=amt;
		}
	}

	cout << pessoa << " ";

	pessoa=-1;
	best=-1;

	frr(i,n){
		int amt=-1;
		frr(j,m){
			int len = mat[i][j].size();
			if(!len || mat[i][j][len-1].ac==0)	continue;
			amt=max(amt,len-1);
		}
		if(amt>best && amt!=-1){
			pessoa=i;
			best=amt;
		}
	}

	cout << pessoa << endl;
	

}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	solve();

}