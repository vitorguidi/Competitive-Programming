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
const int MOD = 998244353;
 
int n;
vii v,v2,vtroll;
 
ll fat[300300];
map<pii,int> freq,freq2;
 
ll fastxp(ll base, ll exp){
	ll ans=1;
	while(exp){
		if(exp%1)
			ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2;
	}
	return ans;
}
 
ll invmod(ll base){
	return fastxp(base,MOD-1);
}
 
bool check(vii cara){ //checa se eh bad
	bool flag1=true;
	bool flag2=true;
	for(int i=1;i<n;i++){
		if(cara[i].fst<cara[i-1].fst)
			flag1=false;
		if(cara[i].snd<cara[i-1].snd)
			flag2=false;
	}
	return flag1|flag2;
}
 
int main(){
 
	fastio;
 
	cin >> n;
 
	fat[0]=1ll;
	fat[1]=1ll;
 
	for(ll i=2;i<300300;i++)
		fat[i]=(i*fat[i-1])%MOD;
 
	frr(i,n){
		int a,b;
		cin >> a >> b;
		v.pb({a,b});
		v2.pb({b,a});
		vtroll.pb({a,b});
		freq[{a,b}]++;
		freq2[{b,a}]++;
	}
 
	sort(all(v));
	//vamos contar as bad perms (increasing no fst)
 
	int ini=0;
	ll badfirst = 1;
 
	while(ini<n){
		ll val = v[ini].fst;
		ll cnt=1;
		set<pii> lol;
		lol.insert(v[ini]);
		while(ini+1<n && v[ini+1].fst==v[ini].fst){
			ini++;
			cnt++;
			lol.insert(v[ini]);
		}
		badfirst*=fat[cnt];
		badfirst%=MOD;
		for(auto x : lol)
			badfirst*=invmod(fat[freq[x]]);
		ini++;
	}
 
	//vamos contar as bed perms (increasing no snd)
	ini=0;
 
	ll badsecond=1;
	sort(all(v2));
 
	while(ini<n){
		ll val = v2[ini].fst;
		ll cnt=1;
		set<pii> lol;
		lol.insert(v[ini]);
		while(ini+1<n && v2[ini+1].fst==v2[ini].fst){
			ini++;
			cnt++;
			lol.insert(v[ini]);
		}
		badsecond*=fat[cnt];
		badsecond%=MOD;
		for(auto x : lol)
			badsecond*=invmod(fat[freq2[x]]);
		ini++;
	}
 
	ini=0;
	ll badboth=1;
 
	for(int i=1;i<n;i++){
		if(v[i].snd<v[i-1].snd)
			badboth=0;
	}
 
	while(ini<n){
		pii val = v[ini];
		ll cnt=1;
		set<pii> lol;
		lol.insert(v[ini]);
		while(ini+1<n && v[ini+1]==v[ini]){
			ini++;
			cnt++;
			lol.insert(v[ini]);
		}
		badboth*=fat[cnt];
		badboth%=MOD;
		for(auto x : lol)
			badboth*=invmod(fat[freq[x]]);
		ini++;
	}
 
	// dbg(badboth);
	// dbg(badfirst);
	// dbg(badsecond);
 
	ll ans = fat[n];
	ll bad = badfirst + badsecond - badboth;
	bad%=MOD;
	if(bad<0)
		bad+=MOD;
	ans-=bad;
	if(ans<0)
		ans+=MOD;
 
	cout << ans << endl;
 
	// sort(all(vtroll));
 
	// ll cnt = fat[n];
	// do{
	// 	if(check(vtroll))
	// 		cnt--;
	// }while(next_permutation(all(vtroll)));
 
	// cout << cnt << endl;
 
}