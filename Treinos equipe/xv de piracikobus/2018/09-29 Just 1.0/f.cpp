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
const int mod = 1e9+7;

int grid[110][110];
int v[110][110][501];
int n,m,q;

void solve(){

	scanf("%d%d%d",&n,&m,&q);

	ms(v,0);

	frr(i,n){
		frr(j,m){
			scanf("%d",&grid[i][j]);
			v[i][j][grid[i][j]]++;
		}
	}

	frr(k,500){
		frr(i,n)
			frr(j,m)
				v[i][j][k]+= v[i-1][j][k] + v[i][j-1][k] - v[i-1][j-1][k];
	}

	frr(i,n)
		frr(j,m)
			frr(k,500)
				v[i][j][k]+=v[i][j][k-1];


	while(q--){
		
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
	
		int amt = (1+c-a)*(1+d-b);
		amt=(amt+1)/2;

		int ind=0;
		int ini=1;
		int end=500;

		while(ini<=end){
		
			int mid = (ini+end)/2;			
			int val = v[c][d][mid] - v[c][b-1][mid]  - v[a-1][d][mid] + v[a-1][b-1][mid];
		 
		 	if(val<amt){
				ini=mid+1;
				ind=mid;
		 	}
			else
				end=mid-1;

		}
		
		printf("%d\n",ind+1);
	
	}


}


int main(){
	
	int t; 
	scanf("%d",&t);;
	while(t--)	solve();

}