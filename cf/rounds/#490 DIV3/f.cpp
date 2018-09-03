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
#define pq priority_queue
#define grtp greater< pair<int,int> >

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
const double pi = 3.141592653589793238462643383279502884L;

int n,k,cnt[100100],fav[100100],h[550];
int pd[550][5500];

int main(){

	int x;

	cin >> n >> k;
	
	fr(i,n*k){	
		cin >> x;
		cnt[x]++;
	}

	fr(i,n){
		cin >> x;
		fav[x]++;
	}

	frr(i,k)
		cin >> h[i];

	fr(i,n){					//numero de players que querem a carta
		fr(j,n*k+1){			//numero de cartas desse tipo disponivel
			fr(l,k+1){			//quantidade de cartas a mais que o prox player vai receber

				pd[i+1][j+l]=max( pd[i+1][j+l], pd[i][j] + h[l] );
			}
		}
	}

	int ans=0;
	fr(i,100010){
		ans+=pd[ fav[i] ][ cnt[i] ];
	}

	cout << ans << endl;

}

