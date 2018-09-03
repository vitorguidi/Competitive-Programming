#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define priority_queue pq
#define grtp greater<pair<int,int>

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct numero{
	ll dg2,dg3,val;
};

numero v1[101];

ll deg3(ll x){
	ll cnt=0;
	while(x%3==0){
		x=x/3;
		cnt++;
	}
	return cnt;
}

ll deg2(ll x){
	ll cnt=0;
	while(x%2==0){
		x=x/2;
		cnt++;
	}
	return cnt;
}

bool oprt(numero x, numero y){
	if(x.dg2<y.dg2)	return true;
	if(x.dg2==y.dg2 && x.dg3>y.dg3)	return true;
	return false;
}

int main(){

	int n;
	ll aux;
	cin >> n;

	fr(i,n){
		int d2,d3;
		numero x;
		cin >> aux;
		d2=deg2(aux);
		d3=deg3(aux);
		x.dg2=deg2(aux);
		x.dg3=deg3(aux);
		x.val=aux;
		v1[i]=x;
	}

	sort(v1,v1+n,oprt);
	fr(i,n){
		cout << v1[i].val << " ";
	}
	cout << endl;

}