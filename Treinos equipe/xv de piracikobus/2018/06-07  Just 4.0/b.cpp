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

int main(){
	int T,v[1010],n,m;
	scanf("%d",&T);
	for (;T>0;T--){
		scanf("%d",&n);
		scanf("%d",&m);
		
		fr(i,n){
			scanf("%d",&v[i]);
		}
		if (v[0]==-1){
			int j;
			fr(i,n)
				if (v[i]!=-1){
					j=i;
					i=1010;
				} 
			for (;j>0;j--){
				if (v[j]==0)
					v[j-1] = m-1;
				else
					v[j-1] = v[j] - 1;
			}


		}
	
		fr(i,n)
			if (v[i]==-1)
				v[i]= (v[i-1] + 1)%m;
			
		


		fr (i,n)
			printf("%d ",v[i]);
		printf("\n");
	}
	return (0);

}