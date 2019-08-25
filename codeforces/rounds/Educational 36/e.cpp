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

int ans;
int n,q;
set<pii> s;

pii inter(pii a, pii b){
	return{max(a.fst,b.fst),min(a.snd,b.snd)};
}

bool valid(pii a){
	return a.fst<=a.snd;
}

void remove(int l, int r){

	while(s.lower_bound({l,0})!=s.end()){
		
		auto it = s.lower_bound({l,0});
		pii val = *it;
		pii aux = {val.snd,val.fst};

		//sempre me retorna pares da forma (fim,inicio)
		pii meio = inter({l,r},aux);

		if(!valid(meio))
			break;

		pii raboLeft = make_pair(aux.fst,meio.fst-1);
		pii raboRight = make_pair(meio.snd+1,aux.snd);

		s.erase(val);

		ans-=meio.snd-meio.fst+1;

		if(valid(raboLeft))
			s.insert({raboLeft.snd,raboLeft.fst});
		if(valid(raboRight))
			s.insert({raboRight.snd,raboRight.fst});


	}
}

void add(int l, int r){
	remove(l,r);
	ans+=r-l+1;
	s.insert({r,l});
}
	
int main(){

	scanf("%d %d",&n,&q);
	ans=n;

	s.insert({n,1});

	while(q--){
		int op,l,r;
		scanf("%d %d %d",&l,&r,&op);
		if(op==1)
			remove(l,r);
		else
			add(l,r);
		printf("%d\n",ans);
	}

}