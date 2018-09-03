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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

pii acuml[300200],acumr[300200];
pii cara[300200],v[300200];

pii nill(){
	return {-INF,INF};
}

pii inter(pii x, pii y){
	int l = max(x.fst,y.fst);
	int r = min(x.snd,y.snd);
	return {l,r};
}

int calc(pii x){
	if(x.fst>x.snd)
		return 0;
	return x.snd-x.fst;
}

int main(){
    
    int n; cin >> n;

 	acuml[0]=acumr[0]=nill();
 	acumr[n+1]=acuml[n+1]=nill();

 	frr(i,n){
 		int x,y; cin >> x >> y;
 		v[i]={x,y};
 	}

 	frr(i,n)
 		acuml[i]=inter(v[i],acuml[i-1]);
 	
 	for(int i=n;i>0;i--)
 		acumr[i]=inter(v[i],acumr[i+1]);

 	frr(i,n)
 		cara[i]=inter(acuml[i-1],acumr[i+1]);

 	int ans = 0;

 	frr(i,n)
 		ans=max(ans,calc(cara[i]));

 	cout << ans << endl;
 	
 }

