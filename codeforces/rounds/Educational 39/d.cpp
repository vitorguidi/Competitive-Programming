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

int n,m,k;
int memo1[550][550];
int memo2[550][550];

vi days[550];

void build(int ind){		//menor tempo de aula que consigo no dia ind com k aulas disponiveis nesse dia

	int len = days[ind].size();

	if(len==0){
		for(int i=0;i<550;i++)
			memo2[ind][i]=0;
		return;
	}

	memo2[ind][0] = days[ind][len-1] - days[ind][0] + 1;

	for(int i=1;i<len;i++){	//fixa tamanho

		memo2[ind][i]=INF;
		int sz = len-i;

		for(int j=0;j+sz-1<len;j++)
			memo2[ind][i] = min(days[ind][j+sz-1] - days[ind][j] + 1,memo2[ind][i]);

	}

	for(int i=len;i<550;i++)
		memo2[ind][i]=0;


}

int pd(int ind, int k){		//melhor q eu faço tendo k aula pra matar e estando no indice ind

	if(ind==n)	return 0;

	int &pdm = memo1[ind][k];
	if(pdm!=-1)	return pdm;

	pdm=INF;

	for(int i=0; i<=k; i++)
		pdm=min(pdm, pd(ind+1,k-i)+ memo2[ind][i] ) ;

	return pdm;

}

int main(){
    
	fastio;

	cin >> n >> m >> k;

	ms(memo1,-1);

	string s;
	
	fr(i,n){
		cin >> s;
		fr(j,s.size())
			if(s[j]!='0')
				days[i].pb(j);	
	}

	fr(i,n)	build(i);

	int ans = pd(0,k);
	cout << ans << endl;

}

