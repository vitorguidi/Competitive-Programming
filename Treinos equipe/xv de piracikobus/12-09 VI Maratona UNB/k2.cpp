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

int n,m,k,mask;
int id[30]; 
pair<int,pii> edj[1123];

vii ans,best; 

ll c; 
ll ccbest=llINF;

bool okk=0;


int find(int a){
	if(a==id[a])
		return a; 

	return(id[a]=find(id[a]));
}

void join(int a, int b){
	a=find(a); 
	b=find(b);
	id[b]=a;
}

void kruskal(int msk){
	c=0; 
	ans.clear();

	fr(i,n)
		id[i]=i;


	fr(i,m){
		if(find(edj[i].snd.fst) != find(edj[i].snd.snd) && ( (msk & (1<<edj[i].snd.fst)) &&  (msk & (1<<edj[i].snd.snd)  ) ) ) {
			
			join(edj[i].snd.fst , edj[i].snd.snd );

			c+=edj[i].fst; 
			ans.pb({edj[i].snd.fst , edj[i].snd.snd });
		}
	}

	int lol=-1;
	bool ok=1;

	fr(i,n){
		if((1<<i) & mask){

			if(lol==-1)
				lol=find(i); 

			else if(find(i)!=lol)
				ok=0;
		}
	}
	
	if(ok && c<ccbest){

		okk=1;
		ccbest=c; 
		best=ans;
	}

}


int main(){
	fastio;
	cin>>n>>m>>k; 

	
	int x;
	fr(i,k){
		cin>>x; 
		mask |= (1<<(x-1));
	}

	fr(i,m){
		int u,v,w; 
		cin>>u>>v>>w; 
		edj[i].fst=w;
		edj[i].snd.fst=u-1;
		edj[i].snd.snd=v-1;
	}

	sort(edj,edj+m);

	for(int a=0; a < (1<<(n+1)) ;a++){
		kruskal(a);
	}
	
	if(okk=0)
		cout<<-1<<endl; 
	else{
		cout<<ccbest<<' '<<best.size()<<endl; 
		fr(i,best.size())
		cout<<best[i].fst+1<<' '<<best[i].snd+1<<endl;
	}

}