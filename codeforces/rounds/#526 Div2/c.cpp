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
const ll MOD = 1e9+7;

int acum[100100];
int nxt[100100];
ll seg[400100];

void update(int node, int l, int r, int ind, ll val){

	if(l==r){
		seg[node]+=val;
		seg[node]%=MOD;
		return;
	}

	int mid = (l+r)>>1;

	if(ind<=mid)	update(2*node,l,mid,ind,val);
	else			update(2*node+1,mid+1,r,ind,val);

	seg[node]=(seg[2*node]+seg[2*node+1])%MOD;

}

ll query(int node, int l, int r, int a, int b){

	if(r<a || l>b)	return 0;
	if(a<=l && r<=b)	return seg[node];
	int mid = (l+r)>>1;
	return (query(2*node,l,mid,a,b)+query(2*node+1,mid+1,r,a,b))%MOD;

}

int main(){
    
	fastio;

	string s; cin >> s;
	int n = s.size();

	reverse(all(s));
	s.pb('#');
	reverse(all(s));

	frr(i,n){
		if(s[i]=='b')	acum[i]++;
		acum[i]+=acum[i-1];
	}

	ms(nxt,-1);

	int ini=-1;

	frr(i,n){
		if(s[i]=='a'){
			ini=i;
			break;
		}
	}

	int end=ini+1;

	while(ini<=n){
		
		while(end<=n && s[end]!='a')			end++;
		while(end<=n && acum[end]-acum[ini]==0)	end++;
		while(end<=n && s[end]!='a')			end++;

		if(end<=n && s[end]=='a' && acum[end]-acum[ini]>0)		nxt[ini]=end;
		
		ini++;
	}

	// frr(i,n)	cout << nxt[i] << " ";
	// gnl;


	for(int i = n;i>0;i--){

		if(s[i]!='a')	continue;		//n da pra agregar na seq
		
		update(1,1,n,i,1);				//guarda na dp
		
		if(nxt[i]==-1)	continue;		//nao tem caras pra eu fazer sequencias nao triviais -> vaza

		ll tmp = query(1,1,n,nxt[i],n);	//pego todas as sequencias q formei nos caras a minha frente
		update(1,1,n,i,tmp);
		
	}

	cout << query(1,1,n,1,n) << endl;

}