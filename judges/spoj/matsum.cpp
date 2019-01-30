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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int bit[1100][1100];
int n;

void update(int x, int y, int val){
	for(int i=x;i<n+3;i+=i&-i)
		for(int j=y;j<n+3;j+=j&-j)
			bit[i][j]+=val;		
}

int query(int x, int y){
	int ans = 0;
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j)
			ans+=bit[i][j];
	return ans;
}

void solve(){

	ms(bit,0);

	scanf("%d",&n);

	while(true){

		string s;
		char v[80];
		scanf("%s",v);

		if(strcmp("SET",v)==0){
			int x,y,num;
			scanf("%d %d %d",&x,&y,&num);
			x++;y++;
			int amt = query(x,y)-query(x-1,y)-query(x,y-1)+query(x-1,y-1);
			update(x,y,-1*amt);
			update(x,y,num);

		}
		else if(strcmp("SUM",v)==0){
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++;y1++;x2++;y2++;
			int ans = query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
			printf("%d\n",ans);
		}	
		else{
			printf("\n");
			break;
		}

	}

}

int main(){

	int t;
	scanf("%d",&t);
	while(t--)	solve();
	
}