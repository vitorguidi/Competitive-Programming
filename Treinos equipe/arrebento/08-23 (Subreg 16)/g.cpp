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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int acb[550][550],acw[550][550];

int main(){

	fastio;

	int n,p;
	cin >> n >> p;

	frr(i,p){
		int x,y;
		cin >> x >> y;
		acb[x][y]=1;
	}

	frr(i,p){
		int x,y;
		cin >> x >> y;
		acw[x][y]=1;
	}

	frr(i,n){
		frr(j,n){

			acb[i][j]+=acb[i-1][j];
			acb[i][j]+=acb[i][j-1];
			acb[i][j]-=acb[i-1][j-1];

			acw[i][j]+=acw[i-1][j];
			acw[i][j]+=acw[i][j-1];
			acw[i][j]-=acw[i-1][j-1];

		}
	}

	int ansb=0,answ=0;

	frr(i,n){
		frr(j,n){

			int mx = min(n-i,n-j);
			mx++;

			fr(k,mx){

				int b = acb[i+k][j+k];
				b-=acb[i-1][j+k];
				b-=acb[i+k][j-1];
				b+=acb[i-1][j-1];

				int w = acw[i+k][j+k];
				w-=acw[i-1][j+k];
				w-=acw[i+k][j-1];
				w+=acw[i-1][j-1];

				if(!b && w)	
					answ++;
				if(!w && b)
					ansb++;

			}

		}
	}

	cout << ansb << " " << answ << endl;

}