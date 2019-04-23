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
const int MOD = 1e9+7;


map<string,int> cmp;
string names[10];
int n,m,u;
int memo[1100][1200][10];
int units[10],cost[10],freq[10];

int pd(int cash, int drunk, int id){

	if(id>n)				return 0;
	if(cash<0 || drunk<0)	return 0;
	
	int& pdm=memo[cash][drunk][id];
	if(pdm!=-1)	return pdm;

	if(cash==0 && drunk==0)	return pdm=1;

	pdm=0;	
	
	int pega = pd(cash-cost[id],drunk-units[id],id);
	int passa = pd(cash,drunk,id+1);

	return pdm = max(pega,passa);

}

void recover(int cash,int drunk,int id){

	if(cash==0 && drunk==0)	return;

	int pega = pd(cash-cost[id],drunk-units[id],id);
	int passa = pd(cash,drunk,id+1);

	if(pega>=passa){
		freq[id]++;
		recover(cash-cost[id],drunk-units[id],id);
	}
	else	recover(cash,drunk,id+1);

}

int processa_custo(string s){


	int base=1;
	int ans = 0;

	reverse(all(s));

	string aux;

	for(auto x : s)
		if(x!='.')
			aux.pb(x);

	for(auto x : aux){
		ans+=(x-'0')*base;
		base*=10;
	}

	return ans;

}

int processa_units(string s){

	reverse(all(s));
	string aux;
	for(auto k : s)
		if(k!='.')
			aux.pb(k);

	int base=1;
	int ans=0;

	for(auto x : aux){
		ans+=(x-'0')*base;
		base*=10;
	}

	return ans;

}

int main(){

	fastio;

	string a,b;
	cin >> a >> b;
	cin >> n;

	cmp["1/1"]=1;
	cmp["1/2"]=2;
	cmp["1/3"]=3;

	m=processa_custo(a);
	u=6*processa_units(b);

	ms(memo,-1);

	for(int i=1;i<=n;i++){
		cin >> names[i];
		int forca;
		string lol;
		string custo;
		cin >> forca >> lol >> custo;
		units[i]=(60*forca)/cmp[lol];
		cost[i]=processa_custo(custo);
	}

	if(!pd(m,u,1)){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	recover(m,u,1);	

	frr(i,n){
		if(freq[i])	cout << names[i] << " " << freq[i] << endl;
	}

	int ctot = 0;
	int utot=0;

	frr(i,n){
		ctot+=cost[i]*freq[i];
		utot+=units[i]*freq[i];
	}


}