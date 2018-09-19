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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef pair<pii,pii> palco; 

const int INF = 0x3f3f3f3f;

vector<palco> palcos;

int n,len;
int memo[1100][1100];
int go[1100];

bool compatible(palco a, palco b){
	return b.fst.fst>=a.fst.snd;
}

int pd(int ind, int mask){

	if(ind==len){
		if( mask==((1<<n)-1) )
			return 0;
		return -INF;
	}

	int &pdm=memo[ind][mask];
	if(pdm!=-1)	return pdm;

	pdm=-INF;
	pdm=max( pdm , pd(ind+1,mask) );

	palco atual = palcos[ind];
	int new_mask = mask | (1<<atual.snd.snd);

	pdm = max( pdm , atual.snd.fst + pd(go[ind],new_mask) );
	
	return pdm;

}

int main(){

	cin >> n;

	fr(i,n){
		int aux; cin >> aux;
		fr(j,aux){
			pii x1,x2;
			cin >> x1.fst;
			cin >> x1.snd;
			cin >> x2.fst;
			x2.snd=i;
			palco aux=mp(x1,x2);
			palcos.pb(aux);
		}
	}

	sort(all(palcos));
	len = palcos.size();

	fr(i,1100)
		go[i]=len;

	fr(i,len){
		for(int j=i+1;j<len;j++){
			if(compatible(palcos[i],palcos[j])){
				go[i]=j;
				break;
			}
		}
	}

	ms(memo,-1);
	int ans = pd(0,0);

	if(ans<0)
		cout << -1 << endl;
	else
		cout << ans << endl;

}