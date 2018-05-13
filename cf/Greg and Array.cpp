#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define pq priority_queue	
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pq priority_queue
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define olar() cout << "olaarr" << endl
#define gnl cout << endl;


const int MAXN = 100100;
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct operation{
	int ini,end;
	ll val;
};

struct query{
	int ini,end;
};

ll v[MAXN],acum[MAXN],acum2[MAXN],req[MAXN];

int n,m,k;
operation o[MAXN];
query q[MAXN];

void sum_requests(int a){
	int ini=q[a].ini;
	int end=q[a].end;
	acum2[ini]+=1;
	acum2[end+1]-=1;
}

void apply(int op){
	operation x = o[op];
	ll amt=req[op]*x.val;

	acum[x.ini]+=amt;
	acum[x.end+1]-=amt;
}

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l,r,d;
    cin >> n >> m >> k;

    frr(i,n)	cin>>v[i];	//le elementos do vetor
    
    frr(i,m){				//le operacoes possiveis
    	cin >> l >> r >> d;
    	o[i].ini=l;
    	o[i].end=r;
    	o[i].val=d;
    }	

    frr(i,k){		//le as queries que vamos executar
    	int ini,end;
    	cin >> ini >> end;
    	q[i].ini=ini;
    	q[i].end=end;
    }

    frr(i,k)	sum_requests(i);
    ll delta=0;
    for(int i=1;i<=m;i++){
    	delta+=acum2[i];
    	req[i]+=delta;
    }

	frr(i,m)	apply(i);

	delta=0;
	for(int i=1;i<=n;i++){
		delta+=acum[i];
		v[i]+=delta;
	}	
	for(int i=1;i<=n;i++)	cout << v[i] << " ";
	gnl;	

}