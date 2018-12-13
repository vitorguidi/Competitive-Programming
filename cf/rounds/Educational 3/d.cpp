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

ll dollar[200200];
ll pound[200200];

ll best_dollar[200200];
ll best_pound[200200];

ll acumd[200200];
ll acump[200200];

vector<pll> gad_d,gad_p;

int nd=0;
int np=0;
ll n,m,k,s;

ll check(int mid){

	ll ans = llINF;

	for(int i=0;i<=np;i++){		//esgota todas as possibilidades de k elementos com i gadgets de pounds e k-i gadgets de dollar

		ll sum = 0;

		if(k-i>nd)	continue;

		sum+=dollar[best_dollar[mid]]*acumd[k-i];
		sum+=pound[best_pound[mid]]*acump[i];

		if(sum<=s)	ans=i;

	}

	return ans;

}

int main(){
    
    fastio;

    cin >> n >> m >> k >> s;

    dollar[0]=pound[0]=INF;

    frr(i,n){

    	cin >> dollar[i];

    	if(dollar[i]<=dollar[best_dollar[i-1]])
    		best_dollar[i]=i;

    	else
    		best_dollar[i]=best_dollar[i-1];

    }

    frr(i,n){

    	cin >> pound[i];

    	if(pound[i]<=pound[best_pound[i-1]])
    		best_pound[i]=i;

    	else
    		best_pound[i]=best_pound[i-1];
    
    }

   	frr(i,m){

   		int t;
   		ll cost;
   		
   		cin >> t >> cost;
   		
   		if(t==1){
   			nd++;
   			gad_d.pb({cost,i});
   		}

   		else{
   			np++;
   			gad_p.pb({cost,i});
   		}

   	}

   	sort(all(gad_p));
   	sort(all(gad_d));

   	frr(i,nd)	acumd[i]=acumd[i-1]+gad_d[i-1].fst;
   	frr(i,np)	acump[i]=acump[i-1]+gad_p[i-1].fst;

   	int best = INF;


   	int ini=1;
   	int end=n;

   	while(ini<=end){

   		int mid = (ini+end)/2;
   		if(check(mid)!=llINF){
   			best=min(best,mid);
   			end=mid-1;
   		}
   		else
   			ini=mid+1;
   	}

   	if(best==INF){
   		cout << -1 << endl;
   		return 0;
   	}

   	int lol = check(best);

   	cout << best << endl;

   	fr(i,lol)
   		cout << gad_p[i].snd << " " << best_pound[best] << endl;

   	fr(i,k-lol)
   		cout << gad_d[i].snd << " " << best_dollar[best] << endl;
    
}