#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int memo[222222],prox[222222],f[222222],v[222222],n;

int pd (int i){
	if (i==n-1) return 0;
	int &ans=memo[i];
	if (ans == -1)
		if (prox[i]==-1)
			ans=1 + pd(i+1);
		else
			ans = min(1 + pd(i+1),1 + pd(prox[i]));
	return (ans);
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ms(prox,-1);
		ms(f,-1);
		ms(v,-1);
		ms(memo,-1);
		scanf("%d",&n);
		fr(i,n)
			scanf("%d",&v[i]);
		fr(i,n){
			int at = v[i];
			if (f[at]==-1)
				f[at] = i;
			else{
				prox[f[at]] = i;
				f[at] = i;
			}
		}
		printf("%d\n",pd(0));
		//fr(i,n)
		//	printf("%d ",prox[i]);
 
	}
	return (0);
}
