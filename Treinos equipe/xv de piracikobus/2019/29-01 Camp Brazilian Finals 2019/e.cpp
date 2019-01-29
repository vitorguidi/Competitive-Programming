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
map<string,int> mapa;

int id[212345],sz[212345];
int n,m,Q;

int find(int a){
	if(id[a]==a)
		return a;
	return find(id[a]);
}

void merge(int a,int b){

	a=find(a);
	b=find(b);
	if(a==b) return;

	if(sz[a]<sz[b])
		swap(a,b);

	sz[a]+=sz[b];
	id[b]=a;
}


bool merge_amigo(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return true;

	int ia,ib;
	ia=find(a+n);
	ib=find(b+n);

	if(ia==b || ib==a) return false;
	
	merge(ia,ib);
	merge(a,b);
	return true;
}

bool merge_inimigo(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return false;

	int ia,ib;
	ia=find(a+n);
	ib=find(b+n);
	if(ia==ib) return false;

	if(ia==b || ib==a) return true;

	merge(ia,b);
	merge(ib,a);

	return true;
}

int main(){
	fastio;
	cin>>n>>m>>Q;
	
	string s,q;
	frr(i,n){
		
		id[i]=i;
		sz[i]=1;
		id[n+i]=n+i;
		sz[n+i]=0;
		

		cin>>s;
		mapa[s]=i;
	}

	int op;
	fr(i,m){
		cin>>op>>s>>q;
		int a,b;
		a=mapa[s];
		b=mapa[q];

		if(op==1){
			if(merge_amigo(a,b))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			if(merge_inimigo(a,b))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}

	}
	int a,b;
	fr(i,Q){
		cin>>s>>q;

		a=mapa[s];
		b=mapa[q];
		a=find(a);
		b=find(b);

		if(b==a)
			cout<<1<<endl;
		else if(find(a+n)==b || find(b+n)==a)
			cout<<2<<endl;
		else
			cout<<3<<endl;

	}

}
