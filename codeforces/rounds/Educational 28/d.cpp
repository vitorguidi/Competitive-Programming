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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int m_amt[550][550];
int m_time[550][550];

int seg[3000][550];

int n,m,k,q;

void build(int node, int l, int r, int row){

	if(l==r){
		seg[node][row]=m_time[row][l];
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid,row);
	build(2*node+1,mid+1,r,row);

	seg[node][row]=max(seg[2*node][row],seg[2*node+1][row]);

}

int query(int node, int l, int r, int a, int b, int row){

	if(r<a || l>b)		return -INF;

	if(a<=l && r<=b)	return seg[node][row];

	int mid = (l+r)/2;

	return max( query(2*node,l,mid,a,b,row) , query(2*node+1,mid+1,r,a,b,row) );

}

int query_amt(int x, int y){
	return m_amt[x+k-1][y+k-1] - m_amt[x-1][y+k-1] - m_amt[x+k-1][y-1] + m_amt[x-1][y-1];
}

int query_max(int x, int y){
	
	int ans = -INF;

	for(int i=x;i<x+k;i++)
		ans=max( ans,query( 1,1,m,y,y+k-1,i ) );

	return ans;

}

int main(){
    
	scanf("%d %d %d %d",&n,&m,&k,&q);

	ms(m_time,-INF);

	fr(i,q){
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		m_time[x][y]=t;
		m_amt[x][y]=1;
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			m_amt[i][j]+=m_amt[i][j-1]+m_amt[i-1][j]-m_amt[i-1][j-1];

	int best = INF;

	for(int i=1;i<=n;i++)
		build(1,1,m,i);

	for(int i=1;i+k-1<=n;i++){
		for(int j=1;j+k-1<=m;j++){

			int amt = query_amt(i,j);

			if(amt!=k*k)	continue;

			int quando = query_max(i,j);

			best=min(best,quando);
			
		}
	}

	if(best==INF)
		printf("-1\n");
	else
		printf("%d\n",best);


}

