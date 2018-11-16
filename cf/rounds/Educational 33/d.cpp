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

ll mor[100100],af[100100];
ll mxm[100100],mxa[100100];
ll v[100100];

void update(int ind, ll val,vector<ll>& bit){
	for(int i=ind;i<100100;i+=i&-i)
		bit[i]+=val;
}

ll query(int ind,vector<ll>& bit){
	ll ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int main(){
    
	fastio;

	ll n,d;
	cin >> n >> d;

	vector<ll> bit_mxa(100100),bit_mxm(100100);
	vector<ll> bit_a(100100),bit_m(100100);

	frr(i,n){
		
		ll val;
		cin >> val;
		
		af[i]=mor[i]+val;
		mor[i+1]=af[i];
		
		v[i]=val;

		if(af[i]>d || mor[i]>d){
			cout << -1 << endl;
			return 0;
		}

	}

	mxa[n+1]=mxm[n+1]=-INF;

	for(int i=n;i>0;i--){

		mxm[i]=max(mor[i],mxm[i+1]);		//maior balanço de manha de mim a direita
		mxa[i]=max(af[i],mxa[i+1]);			//maior balanco de tarde de mim a direita
		
		update(i,mxm[i],bit_mxm);			//bit de maximo de manha
		update(i+1,-1ll*mxm[i],bit_mxm);
		
		update(i,mxa[i],bit_mxa);			//bit de maximo de tarde
		update(i+1,-1ll*mxa[i],bit_mxa);

		update(i,af[i],bit_a);				//bit de valores de tarde
		update(i+1,-1ll*af[i],bit_a);

		update(i,mor[i],bit_m);				//bit de valores de manha
		update(i+1,-1ll*mor[i],bit_m);
	
	}

	int cnt = 0;

	frr(i,n){
		
		if(v[i])	continue;
		
		ll limite = max<ll>( query(i,bit_mxa) , query(i,bit_mxm) );		//max a direita (tanto manha quanto tarde)
		ll atual = min<ll>( query(i,bit_m) , query(i,bit_a) );			//valor minimo atual no dia de hj (deve ser >=0)

		if(limite>d || max<ll>( query(i,bit_m) , query(i,bit_a) ) > d){
			cnt=-1;
			break;
		}

		if(atual>=0)	continue;

		ll delta = d-limite;

		if(atual + delta<0){
			cnt=-1;
			break;
		}

		cnt++;

		update(i,delta,bit_m);
		update(i,delta,bit_a);
		update(i,delta,bit_mxa);
		update(i,delta,bit_mxm);

	}

	cout << cnt << endl;

}

