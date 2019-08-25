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
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int hgt[5050],l[5050],r[5050];
multiset<int> s;
int v[10100];
int v2[10100];

typedef tuple<int,int,int> event;
vector<event> ev;

int n=1;

int main(){

	fastio;

	while(cin >> l[n] >> hgt[n] >> r[n])
		n++;

	n--;

	s.insert(0);

	int fim = 0;

	frr(i,n){
		ev.pb(make_tuple(l[i],0,hgt[i]));
		ev.pb(make_tuple(r[i],1,hgt[i])); 
		fim=max(fim,r[i]);
	}

	int ini=0;

	sort(all(ev));

	for(int i=1;i<=10000;i++){

		while(ini<2*n && get<0>(ev[ini])==i && get<1>(ev[ini])==0)
			s.insert(get<2>(ev[ini++]));
		while(ini<2*n && get<0>(ev[ini])==i && get<1>(ev[ini])==1)
			s.erase(s.find(get<2>(ev[ini++])));
		
		v[i]=*(s.rbegin());

	}

	ini=1;
	int val;
	vii ans;

	while(ini<=fim){
		ans.pb({ini,v[ini]});
		val=v[ini];
		while(ini<=fim && v[ini]==val)
			ini++;
	}

	fr(i,ans.size()){
		pii x = ans[i];
		cout << x.fst << " " << x.snd;
		if(i!=ans.size()-1)
			cout << " ";
	}	
	gnl;

}