#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >
#define gnl cout << endl
#define olar cout << "olar" << endl

const int INF = 0x3f3f3f3f;

double val[100100];
double seg[400400];

void build(int node, int x, int y){

	if(x==y){
		seg[node]=val[x];
		return;
	}
	int mid = (x+y)/2;
	build(2*node,x,mid);
	build(2*node+1,mid+1,y);
	seg[node]=seg[2*node]+seg[2*node+1];

}

void update(int node, int x, int y, int id){

	if(x==y){
		seg[node]=val[id];
		return;
	}	

	int mid = (x+y)/2;
	if(id<=mid)	update(2*node,x,mid,id);
	else		update(2*node+1,mid+1,y,id);
	seg[node]=seg[2*node]+seg[2*node+1];

}

double query(int node, int x, int y, int l, int r){
	if(y<l || x>r)		return 0;
	if(x>=l && y<=r)	return seg[node];
	int mid = (x+y)/2;
	return query(2*node,x,mid,l,r)+query(2*node+1,mid+1,y,l,r);
}

int main(){

	int n,q;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)	scanf("%lf",&val[i]);
	scanf("%d",&q);


	build(1,1,n);

	for(int i=0;i<q;i++){
		int t;
		scanf("%d",&t);

		if(t==1){
			int e;
			double v;
			scanf("%d %lf",&e,&v);
			val[e]=v;
			update(1,1,n,e);
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			double x = query(1,1,n,l,r);
			x=x/(r-l+1);
			printf("%.6lf\n",x);
		}

	}


}