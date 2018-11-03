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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int mod = 1e9+7;

int mn[300300];
map<pii,int> id;
bool contains(pii a, pii b){
	return a.fst<=b.fst && b.snd<=a.snd;
}

bool mycomp(pair<pii,int> a, pair<pii,int> b){
	pii x = a.fst;
	pii y = b.fst;
	if(x.fst<y.fst)
		return true;
	else if(x.fst==y.fst)
		return x.snd>y.snd;
	return false;
}

int main(){

	int n; cin >> n;
	vector< pair<pii,int> > x;

	frr(i,n){
		int a,b;
		cin >> a >> b;
		pii aux = {a,b};
		x.pb( mp(aux,i) );
	}

	sort(all(x),mycomp);
	ms(mn,INF);

	for(int i=n-1;i>=0;i--)
		mn[i]=min(mn[i+1],x[i].fst.snd);
	
	bool flag=false;
	int l=-1,r=-1;

	fr(i,n){
		
		if(flag)
			break;

		if(mn[i+1]<=x[i].fst.snd){
		
			for(int j=i+1;j<n;j++){
				if(contains(x[i].fst,x[j].fst)){
					l=i;
					r=j;
					flag=true;
					break;
				}
			}

		}
	}

	if(flag)
		cout << x[r].snd << " " << x[l].snd << endl;
	else
	cout << "-1 -1" << endl;

}