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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

#define MAX 1123456 

int id[MAX],sz[MAX];
pair<int,pii> edj[MAX];

int find(int l){
	if(id[l]==l)
		return(l);
	return(id[l]=find(id[l]));

}
void join(int a,int b){
	a=find(a);
	b=find(b);
	if(sz[a]<sz[b])
		swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];

}



int kruskal(int m){
	int mx;
	mx=0;
	sort(edj,edj+m);
	fr(i,m){
		if( find(edj[i].snd.fst) != find(edj[i].snd.snd)  ){
			join(edj[i].snd.fst,edj[i].snd.snd);
			mx=max(mx, edj[i].fst);
		}
	}
	return(mx);
}

int main(){
	int T,m,n;
	cin >> T;
	while(T--){
		cin >> n >> m;
		frr(i,n){
			id[i]=i;
			sz[i]=1;
		}
		int a,b,c;
		fr(i,m){
			cin>>a>>b>>c;
			edj[i].fst=c; 
			edj[i].snd=mp(a,b);
		}
		cout<<kruskal(m)<<endl;
	}

}