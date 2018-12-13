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

int col[2550][2550];
int row[2550][2550];
int grid[2550][2550];

int check(int bx, int by, int cx, int cy){

	int sum = 0;

	if(bx==cx){
		sum+=row[bx][max(by,cy)]-row[bx][min(by,cy)-1];
	}
	else{
		sum+=col[by][max(bx,cx)]-col[by][min(bx,cx)-1];
	}

	return sum==0;


}

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid[i+1][j+1]= (s[j]=='.' ? 0 : 1);
			row[i+1][j+1]+=grid[i+1][j+1];
			col[j+1][i+1]+=grid[i+1][j+1];
		}
	}

	frr(i,m)		//acumulando colunas
		frr(j,n)	col[i][j]+=col[i][j-1];

	frr(i,n)		//acumulando linhas
		frr(j,m)	row[i][j]+=row[i][j-1];


	int q; cin >> q;

	fr(i,q){

		int a1,b1,a2,b2;
		cin >> a1 >> b1 >> a2 >> b2;

		if(b1<=b2){
			swap(a1,a2);
			swap(b1,b2);
		}

		int bx1,by1,bx2,by2;

		int flag = false;

		if(a2>=a1){
			bx1=min(a1,a2);
			by1=min(b1,b2);
			bx2=max(a1,a2);
			by2=max(b1,b2);
		}
		else{
			bx1=min(a1,a2);
			by1=max(b1,b2);
			bx2=max(a1,a2);
			by2=min(b1,b2);
		}		

		// dbg(bx1);
		// dbg(by1);
		// dbg(bx2);
		// dbg(by2);

		if(check(bx1,by1,a1,b1) && check(bx1,by1,a2,b2))	flag=true;
		if(check(bx2,by2,a1,b1) && check(bx2,by2,a2,b2))	flag=true; 

		if(flag)	puts("YES");
		else		puts("NO");

	}

}
