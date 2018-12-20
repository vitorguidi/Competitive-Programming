#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define grtp greater<pair<int,int>>()
#define grti greater<int>()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n,m,cl,ce,v,q;
vector<ll> esc,ele;
int se,sl;


ll query(ll x1,ll y1, ll x2, ll y2){
	
	if(x1==x2)	return abs(y1-y2);

	vector<ll>::iterator ele1,ele2,esc1,esc2;

	ll dele=INF,desc=INF;

	ele1=lower_bound( all(ele) , y1);
	ele2=lower_bound( all(ele) ,y1)-1;

	if(se>0){

	if(ele1!=ele.begin())	dele=min( abs(*ele1-y1)+abs(*ele1-y2),abs(*ele2-y2)+abs(*ele2-y1) );
	else					dele=abs(*ele1-y1)+abs(*ele1-y2);

	}

	esc1=lower_bound( all(esc),y1);
	esc2=lower_bound( all(esc),y1) -1;

	if(sl>0){

	if(esc1!=esc.begin())	desc=min( abs( *esc1-y1 ) + abs( *esc1-y2 ) , abs( *esc2-y2 )+abs( *esc2-y1 ) );
	else					desc=abs( *esc1-y1 ) + abs( *esc1-y2 );

	}

	ll tesc=desc+abs(x1-x2);
	ll tele=dele+ (abs(x1-x2)+v-1)/v; 	

	return min(tele,tesc);
}

int main(){

	cin >> n >> m >> cl >> ce >> v;	
	ll aux;
	fr(i,cl){
		cin >> aux;
		esc.pb(aux);
	}
	fr(i,ce){
		cin >> aux;
		ele.pb(aux);
	}
	
	sort(all(ele));
	sort(all(esc));

	se=ele.size();
	sl=esc.size();

	cin >> q;

	fr(i,q){
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout <<	query(x1,y1,x2,y2) << endl;
	}

	return 0;

}