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
vii paes;

int memo[2123][1123];

int pd(int pos,int farinha){
	if(farinha<0)
		return -INF;
	if(farinha==0 or pos==paes.size())
		return 0;
	
	int &pdm=memo[pos][farinha];
	if(pdm!=-1)
		return pdm;

	pdm=max(pdm,pd(pos+1,farinha));
	pdm=max(pdm,pd(pos+1,farinha-paes[pos].fst)+paes[pos].snd);

	return pdm;

}

int main(){
	fastio;
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;


	int aux=n;
	while(aux>=c0){
		paes.pb({c0,d0});
		aux-=c0;
	}

	int a,b,c,d;
	fr(i,m){
		cin>>a>>b>>c>>d;
		while(a>=b){
			paes.pb({c,d});
			a-=b;
		}
	}
	ms(memo,-1);
	int ans=pd(0,n);
	cout<<(ans<0?0:ans)<<endl;
}