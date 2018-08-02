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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int memo[550][550];
int v[550][550];		
int r,c;

int pd(int x, int y){

	if(!x && !y)
		return v[x][y];
	if(x<0 || y<0)
		return -INF;

	int &pdm=memo[x][y];
	
	if(pdm!=-1)
		return pdm;

	int up = pd(x-1,y);
	int left = pd(x,y-1);

	pdm= v[x][y] + max(up,left);

	if(pdm<0)
		pdm=-INF;

	return pdm;

}

int check(int val){

	ms(memo,-1);
	v[0][0]=val;
	int ans=pd(r-1,c-1);
	if(ans!=-INF)
		return true;
	return false;

}

int bins(int ini, int end){

	int mid = (ini+end)/2;

	if(ini>end)			//caso invalido
		return INF;

	if(check(mid))		//se o numero de boars for suficiente, tento diminuir
		return min(mid,bins(ini,mid-1));

	return bins(mid+1,end);	//senao aumento
}

int main(){

	int t;
	cin >> t;

	while(t--){
		cin >> r >> c;
		fr(i,r)
			fr(j,c)
				cin >> v[i][j];

		cout << bins(0,1000000) << endl;
	}

}