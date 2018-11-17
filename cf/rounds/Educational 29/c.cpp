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

ll k, a, b;
pii m[5][5];		//m[jogada anterior alice][jogada anterior bob] -->> guarda a jogada futura (alice,bob)	
vector<pll> plays;
int vis[5][5];

void dfs(pii v){

	vis[v.fst][v.snd]++;
	plays.pb(v);

	pii prox = m[v.fst][v.snd];

	if(!vis[prox.fst][prox.snd])	dfs(prox);
	else							vis[prox.fst][prox.snd]++;

}

ll score(int p1, int p2){
	if(p1==1 && p2==3)	return 1;
	if(p1==2 && p2==1)	return 1;
	if(p1==3 && p2==2)	return 1;
	return 0;
}

int main(){
    
	fastio;

	cin >> k >> a >> b;

	frr(i,3)
		cin >> m[1][i].fst;

	frr(i,3)
		cin >> m[2][i].fst;

	frr(i,3)
		cin >> m[3][i].fst;


	frr(i,3)
		cin >> m[1][i].snd;

	frr(i,3)
		cin >> m[2][i].snd;

	frr(i,3)
		cin >> m[3][i].snd;

	dfs({a,b});

	// for(auto x : plays)
	// 	cout << x.fst << " " << x.snd << " - " << vis[x.fst][x.snd] << endl;

	vector<pii> cauda,ciclo;

	bool flag = false;
	
	for(int i=0;i<plays.size();i++){
		pii cara = plays[i];
		if(vis[cara.fst][cara.snd]==2)
			flag = true;
		if(flag)
			ciclo.pb(cara);
		else
			cauda.pb(cara);
	}

	// cout << "cauda" << endl;

	// for(auto x : cauda)
	// 	cout << x.fst << " " << x.snd << endl;

	// cout << "ciclo" << endl;
	// for(auto x : ciclo)
	// 	cout << x.fst << " " << x.snd << endl;

	ll sa=0,sb=0;

	for(auto x : cauda){
		if(k<=0)
			break;
		sa+=score(x.fst,x.snd);
		sb+=score(x.snd,x.fst);
		k--;
	}

	ll len = ciclo.size();

	ll sca = 0;
	ll scb = 0;

	if(len==0){
		cout << sa << "  " << sb << endl;
		return 0;
	}

	for(auto x : ciclo){
		sca+=score(x.fst,x.snd);
		scb+=score(x.snd,x.fst);
	}

	// dbg(k);
	// dbg(k/len);
	// dbg( (k/len)*len );
	
	sa+=(k/len)*sca;
	sb+=(k/len)*scb;

	k-=(k/len)*len;

	for(auto x : ciclo){
		if(k<=0)	break;
		sa+=score(x.fst,x.snd);
		sb+=score(x.snd,x.fst);
		k--;
	}

	cout << sa << " " << sb << endl;

}

